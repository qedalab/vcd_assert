#include "vcd/types/simulation_time.hpp"

#include <catch2/catch.hpp>

using namespace VCD;

TEST_CASE("VCD.Types.SimulationTime") {
  SimulationTime test;

  test = 3;
  CHECK(test.number == 3);

  test = 7;
  CHECK(test.number == 7);
}
