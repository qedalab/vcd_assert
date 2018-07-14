
#include "./timing_spec.hpp"

using namespace SDF;
using namespace SDF::Test;

void SDF::Test::catch_test_timingspec(TimingSpec wanted, TimingSpec test) {
  SECTION("Timing Spec Type"){
    REQUIRE(wanted.get_enum_type() == test.get_enum_type());
  }

  switch (wanted.get_enum_type()) {
  case TimingSpecType::delay:
    FAIL("Timing Spec of type 'delay' is not supported");
    break;
  case TimingSpecType::timing_check:
    catch_test_timingcheckspec(std::get<TimingCheckSpec>(wanted.value),
                              std::get<TimingCheckSpec>(test.value));
    break;
  case TimingSpecType::timing_env:
    FAIL("Timing Spec of type 'timing_env' is not supported");
    break;
  case TimingSpecType::label:
    FAIL("Timing Spec of type 'label' is not supported");
    break;
  default:
    FAIL("InternalError : Timing Spec Type Error");
  }
  
}