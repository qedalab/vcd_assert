#include "sdf/serialize/delayfile.hpp"
// #include "sdf/serialize/time_scale.hpp"

#include "../types/delayfile.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace SDF;



TEST_CASE("SDF.Serialize.DELAYFILE", "[Serialize]") {
  std::string output;
  SDF::serialize_delayfile(ranges::back_inserter(output), SDF::Test::test_delayfile_1);
  CHECK(output == SDF::Test::basic_example_delayfile);
}
