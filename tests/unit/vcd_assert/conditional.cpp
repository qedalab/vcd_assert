#include "vcd_assert/conditional.hpp"

#include <catch2/catch.hpp>

using namespace VCDAssert;

template<EqualityOperator Op>
void test_op(VCD::Value left, VCD::Value right, VCD::Value result) {
  ConditionalValuePointer left_p = left;
  ConditionalValuePointer right_p = right;

  auto op = ConditionalOperator<Op>(left_p, right_p);

  CHECK(op.call() == result);

  auto value_ptr = ConditionalValuePointer(&op);

  CHECK(value_ptr.value() == result);
}

TEST_CASE("VCDAssert.Conditional") {
  constexpr auto one = VCD::Value::one;
  constexpr auto x = VCD::Value::x;
  constexpr auto z = VCD::Value::z;
  constexpr auto zero = VCD::Value::zero;

  constexpr auto case_equal = EqualityOperator::case_equal;
  constexpr auto case_not_equal = EqualityOperator::case_not_equal;
  constexpr auto logical_equal = EqualityOperator::logical_equal;
  constexpr auto logical_not_equal = EqualityOperator::logical_not_equal;

  SECTION("ConditionalValuePointer") {
    SECTION("Value pointer") {
      VCD::Value value = VCD::Value::one;
      auto value_ptr = ConditionalValuePointer(&value);
      value = VCD::Value::zero;
      CHECK(value_ptr.value() == VCD::Value::zero);
      value = VCD::Value::z;
      CHECK(value_ptr.value() == VCD::Value::z);
    }

    SECTION("Value") {
      auto value_ptr = ConditionalValuePointer(one);
      CHECK(value_ptr.value() == one);

      value_ptr = ConditionalValuePointer(zero);
      CHECK(value_ptr.value() == zero);
    }
  }

  SECTION("Operators and their value pointers") {
    SECTION("Case equality") {
      for(auto left: {one, zero, x, z}) {
        for(auto right: {one, zero, x, z}) {
          auto result = (left == right) ? one : zero;
          test_op<case_equal>(left, right, result);
        }
      }
    }

    SECTION("Case inequality") {
      for(auto left: {one, zero, x, z}) {
        for(auto right: {one, zero, x, z}) {
          auto result = (left == right) ? zero : one;
          test_op<case_not_equal>(left, right, result);
        }
      }
    }

    SECTION("Logical equality") {
      for(auto left: {one, zero}) {
        for(auto right: {one, zero}) {
          auto result = (left == right) ? one : zero;
          test_op<logical_equal>(left, right, result);
        }
      }

      for(auto left: {one, zero})
        for(auto right: {z, x})
          test_op<logical_equal>(left, right, x);

      for(auto left: {z, x})
        for(auto right: {z, x})
          test_op<logical_equal>(left, right, x);

      for(auto left: {z, x})
        for(auto right: {one, zero})
          test_op<logical_equal>(left, right, x);
    }

    SECTION("Logical inequality") {
      for(auto left: {one, zero}) {
        for(auto right: {one, zero}) {
          auto result = (left == right) ? zero : one;
          test_op<logical_not_equal>(left, right, result);
        }
      }

      for(auto left: {one, zero})
        for(auto right: {z, x})
          test_op<logical_not_equal>(left, right, x);

      for(auto left: {z, x})
        for(auto right: {z, x})
          test_op<logical_not_equal>(left, right, x);

      for(auto left: {z, x})
        for(auto right: {one, zero})
          test_op<logical_not_equal>(left, right, x);
    }
  }
}
