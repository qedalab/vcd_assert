#include "vcd_assert/triggered_timing_checker.hpp"

#include "catch2/catch.hpp"

using namespace VCDAssert;

TEST_CASE("VCDAssert.TriggeredTimingChecker")
{
  SECTION("Update Simulation time")
  {
    TriggeredTimingChecker checker(0);
    CHECK(checker.get_sim_time() == 0);

    checker.set_sim_time(42);
    CHECK(checker.get_sim_time() == 42);

    checker.set_sim_time(144);
    CHECK(checker.get_sim_time() == 144);
  }
}
