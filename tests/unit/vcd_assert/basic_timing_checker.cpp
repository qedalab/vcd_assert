#include "vcd_assert/basic_timing_checker.hpp"

#include <catch2/catch.hpp>

using namespace VCDAssert;

TEST_CASE("VCDAssert.BasicTimingChecker")
{

  constexpr std::size_t hold_port = 0;
  constexpr std::size_t setup_port = 1;

  SECTION("Hold")
  {
    BasicTimingChecker timing_checker(2);

    timing_checker.hold(hold_port, 2, 3);
    CHECK(timing_checker.event(hold_port, 6));

    timing_checker.hold(hold_port, 6, 2);
    CHECK(timing_checker.event(hold_port, 8));

    timing_checker.hold(hold_port, 8, 1);
    CHECK_FALSE(timing_checker.event(hold_port, 8));
  }

  SECTION("Setup")
  {
    BasicTimingChecker timing_checker(2);

    CHECK(timing_checker.setup(setup_port, 2, 10));
    CHECK(timing_checker.setup(setup_port, 2, 2));
    CHECK(timing_checker.setup(setup_port, 2, 1));

    REQUIRE(timing_checker.event(setup_port, 5));

    CHECK(timing_checker.setup(setup_port, 7, 1));
    CHECK(timing_checker.setup(setup_port, 7, 2));
    CHECK_FALSE(timing_checker.setup(setup_port, 7, 3));
  }
}
