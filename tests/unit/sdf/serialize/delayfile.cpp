#include "sdf/serialize/delayfile.hpp"
// #include "sdf/serialize/time_scale.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace SDF;

TEST_CASE("SDF.Serialize.DELAYFILE", "[Serialize]") {
  std::string output;
  SDF::serialize_delayfile(ranges::back_inserter(output), "my_delayfile");
  CHECK(output == "(DELAYFILE my_delayfile )\n");
}
