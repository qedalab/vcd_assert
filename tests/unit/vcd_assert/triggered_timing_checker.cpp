#include "vcd_assert/triggered_timing_checker.hpp"

#include "catch2/catch.hpp"

using namespace VCDAssert;

TEST_CASE("VCDAssert.TriggeredTimingChecker")
{
  constexpr auto one = VCD::Value::one;
  constexpr auto zero = VCD::Value::zero;

  SECTION("Update Simulation time")
  {
    TriggeredTimingChecker checker(0);
    CHECK(checker.get_sim_time() == 0);

    checker.set_sim_time(42);
    CHECK(checker.get_sim_time() == 42);

    checker.set_sim_time(144);
    CHECK(checker.get_sim_time() == 144);
  }

  SECTION("Empty") {
    TriggeredTimingChecker checker(2);

    checker.set_sim_time(1);
    CHECK_FALSE(checker.event(0, one, zero));
    CHECK_FALSE(checker.event(1, zero, one));

    checker.set_sim_time(2);
    CHECK_FALSE(checker.event(0, zero, one));
    CHECK_FALSE(checker.event(1, one, zero));
  }

  SECTION("Triggered") {

    TriggeredEvent trigger_one {
      VCD::Value::zero,
      EdgeType::PosEdge,
      0,
      5
    };

    TriggeredEvent trigger_two {
      VCD::Value::one,
      EdgeType::PosEdge,
      1,
      6
    };

    TriggeredTimingChecker checker(2);

    checker.set_sim_time(2);
    checker.hold(trigger_one, 0);
    checker.hold(trigger_two, 1);

    CHECK_FALSE(checker.event(0, one, zero));
    CHECK_FALSE(checker.event(1, one, zero));

    checker.set_sim_time(6);
    CHECK_FALSE(checker.event(0, zero, one));
    CHECK(checker.event(1, zero, one));

    checker.set_sim_time(9);
    CHECK_FALSE(checker.event(0, one, zero));
    CHECK_FALSE(checker.event(1, one, zero));

    checker.set_sim_time(12);
    CHECK_FALSE(checker.event(0, zero, one));
    CHECK_FALSE(checker.event(1, zero, one));
  }
}
