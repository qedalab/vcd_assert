#include "vcd/grammar/enums/value.hpp"
#include "vcd/types/enums.hpp"

#include "parse/test/match.h"

#include <catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;
using VCD::Value;

constexpr char zero_str[] = "0";
constexpr char one_str[] = "1";
constexpr char x_str[] = "x";
constexpr char X_str[] = "X";
constexpr char z_str[] = "z";
constexpr char Z_str[] = "Z";

TEST_CASE("VCD.Grammar.Enums.Value", "[VCD][Grammar][Enums][Value]") {
  SECTION("Individual") {
    CHECK(match_value_exactly<value_0>(zero_str, Value::zero));
    CHECK(match_value_exactly<value_1>(one_str, Value::one));
    CHECK(match_value_exactly<value_x>(x_str, Value::x));
    CHECK(match_value_exactly<value_x>(X_str, Value::x));
    CHECK(match_value_exactly<value_z>(z_str, Value::z));
    CHECK(match_value_exactly<value_z>(Z_str, Value::z));
  }

  SECTION("Together") {
    CHECK(match_value_exactly<value>(zero_str, Value::zero));
    CHECK(match_value_exactly<value>(one_str, Value::one));
    CHECK(match_value_exactly<value>(x_str, Value::x));
    CHECK(match_value_exactly<value>(X_str, Value::x));
    CHECK(match_value_exactly<value>(z_str, Value::z));
    CHECK(match_value_exactly<value>(Z_str, Value::z));

    CHECK(value::error() != nullptr);
  }
}
