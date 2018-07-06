#include "sdf/serialize/delayfile.hpp"
#include "sdf/types/delayfile.hpp"
// #include "sdf/serialize/time_scale.hpp"

#include "../types/delayfile.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace SDF;
using namespace SDF::Test;


TEST_CASE("SDF.Serialize.DELAYFILE", "[Serialize]") {
  std::string output;
  DelayFileTester dft = DelayFileTester();
  auto delayfile_p = dft.get_test_delayfile(test_delayfile_1);
  serialize_delayfile(ranges::back_inserter(output), delayfile_p);
  CHECK(output == basic_example_delayfile);
}
