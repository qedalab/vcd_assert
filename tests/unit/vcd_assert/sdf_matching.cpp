#include "vcd_assert/sdf_matching.hpp"

#include <catch2/catch.hpp>

using namespace VCDAssert;

template <SDF::EqualityOperator SDF_OP, VCDAssert::EqualityOperator OP>
bool check_sdf_cvp_helper(VCD::Value left, VCD::Value right)
{
  auto eval_1 = ConditionalOperator<OP>(left, right).call();
  auto eval_2 = get_sdf_conditional_ptr_helper(SDF_OP, left, right).value();

  return eval_1 == eval_2;
}

TEST_CASE("VCDAssert.SDFMatching")
{
  constexpr auto one = VCD::Value::one;
  constexpr auto x = VCD::Value::x;
  constexpr auto z = VCD::Value::z;
  constexpr auto zero = VCD::Value::zero;

  SECTION("GetSDFConditionalPtrHelper")
  {
    for (auto left : {one, zero, x, z}) {
      for (auto right : {one, zero, x, z}) {
        CHECK(check_sdf_cvp_helper<SDF::EqualityOperator::case_equal,
                                   EqualityOperator::case_equal>(left, right));
        CHECK(check_sdf_cvp_helper<SDF::EqualityOperator::case_inv,
                                   EqualityOperator::case_not_equal>(left, right));
        CHECK(check_sdf_cvp_helper<SDF::EqualityOperator::logic_equal,
                                   EqualityOperator::logical_equal>(left, right));
        CHECK(check_sdf_cvp_helper<SDF::EqualityOperator::logic_inv,
                                   EqualityOperator::logical_not_equal>(left, right));
      }
    }
  }
}
