#include "vcd_assert/state.hpp"

#include "vcd/test/header.hpp"

#include <catch2/catch.hpp>
#include <range/v3/algorithm/copy.hpp>
#include <range/v3/algorithm/equal.hpp>
#include <range/v3/view/indices.hpp>

using namespace VCD;
using namespace VCDAssert;
using ranges::view::indices;

static void catch_state_value(State &state, std::size_t index, double value1,
                              double value2)
{
  CHECK_THROWS(state.get_scalar_value(index));
  CHECK_THROWS(state.get_vector_value(index));
  CHECK_NOTHROW(state.get_real_value(index));

  StateValuePointer svp = state.get_value_pointer(index);

  REQUIRE(std::holds_alternative<double*>(svp));

  auto p = std::get<double*>(svp);
  *p = value1;

  CHECK(state.get_real_value(index) == Approx(value1));

  std::array<VCD::Value, 3> tmp_test = {Value::one, Value::x, Value::z};

  CHECK_NOTHROW(state.set_value(index, value2));
  REQUIRE_THROWS(state.set_value(index, Value::x));
  REQUIRE_THROWS(state.set_value(index, tmp_test));

  CHECK(*p == value2);
}

static void catch_state_value(State &state, std::size_t index, VCD::Value value1,
                              VCD::Value value2)
{
  CHECK_THROWS(state.get_real_value(index));
  CHECK_THROWS(state.get_vector_value(index));
  CHECK_NOTHROW(state.get_scalar_value(index));

  StateValuePointer svp = state.get_value_pointer(index);

  REQUIRE(std::holds_alternative<VCD::Value*>(svp));

  auto p = std::get<VCD::Value*>(svp);
  *p = value1;

  CHECK(state.get_scalar_value(index) == value1);

  std::array<VCD::Value, 3> tmp_test = {Value::one, Value::x, Value::z};

  CHECK_NOTHROW(state.set_value(index, value2));
  REQUIRE_THROWS(state.set_value(index, 3.14));
  REQUIRE_THROWS(state.set_value(index, tmp_test));

  CHECK(*p == value2);
}

static void catch_state_value(State &state, std::size_t index,
                              std::vector<Value> value1,
                              std::vector<Value> value2)
{
  REQUIRE(value1.size() == value2.size());

  CHECK_THROWS(state.get_real_value(index));
  CHECK_THROWS(state.get_scalar_value(index));
  CHECK_NOTHROW(state.get_vector_value(index));

  StateValuePointer svp = state.get_value_pointer(index);

  REQUIRE(std::holds_alternative<ranges::span<Value>>(svp));

  auto r = std::get<ranges::span<Value>>(svp);
  REQUIRE(r.size() == value1.size());

  ranges::copy(value1, ranges::begin(r));
  auto tmp1 = state.get_vector_value(index);
  REQUIRE(tmp1.size() == value1.size());
  CHECK(ranges::equal(tmp1, ranges::begin(value1)));

  CHECK_NOTHROW(state.set_value(index, value2));
  REQUIRE_THROWS(state.set_value(index, 3.14));
  REQUIRE_THROWS(state.set_value(index, Value::x));

  CHECK(ranges::equal(r, ranges::begin(value2)));
}

TEST_CASE("VCDAssert.State") {
  constexpr auto x = Value::x;
  constexpr auto z = Value::z;
  constexpr auto one = Value::one;
  constexpr auto zero = Value::zero;

  Test::TestHeader test_base {
    TimeScale{TimeNumber::_1, TimeUnit::s}, 
    "date",
    "version",
    // Root scope
    Test::TestScope {
      ScopeType::begin,
      "root",
      {}, // No child scopes
      {} // Start with empty variables
    }
  };

  SECTION("No vector values") {
    std::vector<Test::TestVar> test_no_vector = {
      {VarType::real, 64, "1", "1"},
      {VarType::reg, 1, "2", "2"},
      {VarType::wire, 1, "3", "3"},
      {VarType::real, 64, "4", "4"}
    };

    test_base.root_scope.value().variables = std::move(test_no_vector);

    HeaderReader reader;
    Test::read_in_test_header(reader, test_base);
    auto header = reader.release();

    auto state = State(header);

    catch_state_value(state, 0, 3.14, 2.78);
    catch_state_value(state, 1, Value::zero, Value::z);
    catch_state_value(state, 2, Value::x, Value::one);
    catch_state_value(state, 3, 2.78, 3.14);
  }

  SECTION("Only vector values") {
    std::vector<Test::TestVar> test_only_vector = {
      {VarType::reg, 2, "1", "1"},
      {VarType::reg, 3, "2", "2"},
      {VarType::reg, 2, "3", "3"},
      {VarType::reg, 3, "4", "4"}
    };

    test_base.root_scope.value().variables = std::move(test_only_vector);

    HeaderReader reader;
    Test::read_in_test_header(reader, test_base);
    auto header = reader.release();

    auto state = State(header);

    catch_state_value(state, 0, {x,one}, {zero, zero});
    catch_state_value(state, 1, {one, z, z}, {one, zero, x});
    catch_state_value(state, 2, {zero, x}, {x, one});
    catch_state_value(state, 3, {z, z, z}, {one, one, one});
  }

  SECTION("Mixed values") {
    std::vector<Test::TestVar> test_mixed = {
      {VarType::real, 64, "1", "1"},
      {VarType::reg, 1, "2", "2"},
      {VarType::wire, 5, "3", "3"},
      {VarType::real, 64, "4", "4"}
    };

    test_base.root_scope.value().variables = std::move(test_mixed);

    HeaderReader reader;
    Test::read_in_test_header(reader, test_base);
    auto header = reader.release();

    auto state = State(header);

    catch_state_value(state, 0, 5.67, 1.13);
    catch_state_value(state, 1, Value::one, Value::x);
    catch_state_value(state, 2, {x, one, one, one, one}, {one, zero, zero, x, z});
    catch_state_value(state, 3, 1.80, 4.04);
  }
}
