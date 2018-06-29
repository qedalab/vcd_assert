#include "vcd/serialize/simulation_time.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.SimulationTime", "[Serialize]") {
  std::string output;
  VCD::serialize_simulation_time(ranges::back_inserter(output), 42);
  CHECK(output == "#42\n");
}
