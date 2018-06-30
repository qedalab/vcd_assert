#include "vcd/serialize/version.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.Version", "[Serialize]") {
  std::string output;
  VCD::serialize_version(ranges::back_inserter(output), "my_version");
  CHECK(output == "$version my_version $end\n");
}
