#include "vcd/serialize/date.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.Date", "[Serialize]") {
  std::string output;
  VCD::serialize_date(ranges::back_inserter(output), "my_date");
  CHECK(output == "$date my_date $end\n");
}
