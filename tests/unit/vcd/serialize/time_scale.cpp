#include "vcd/serialize/time_scale.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.TimeScale", "[Serialize]") {
  std::string output;
  VCD::serialize_time_scale(ranges::back_inserter(output), {TimeNumber::_1, TimeUnit::ns} );
  CHECK(output == "$timescale 1ns $end\n");
}
