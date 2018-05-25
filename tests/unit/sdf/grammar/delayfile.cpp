#include "./delayfile.hpp"

using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;

TEST_CASE("SDF.Grammar.Delayfile", "[SDF][Grammar][Delayfile]") {

  SECTION(fmt::format(
      "Testing Full SDF Example, Ex. 3, variation 1 : \n{}\n",
        sdf_delayfile_ex3_1_str)) {

      CHECK(match_exactly<delay_file>(sdf_delayfile_ex3_1_str));
  }
  SECTION(fmt::format(
      "Testing Full SDF Example, Ex. 3, variation 2 : \n{}\n",
        sdf_delayfile_ex3_2_str)) {

      CHECK(match_exactly<delay_file>(sdf_delayfile_ex3_2_str));
  }

  SECTION(fmt::format(
      "Testing Full SDF Example, Ex. 3, variation 3 : \n{}\n",
        sdf_delayfile_ex3_3_str)) {

      CHECK(match_exactly<delay_file>(sdf_delayfile_ex3_3_str));
  }

  SECTION(fmt::format(
      "Testing Full SDF Example, Ex. 3, variation 4 : \n{}\n",
        sdf_delayfile_ex3_4_str)) {

      CHECK(match_exactly<delay_file>(sdf_delayfile_ex3_4_str));
  }
  SECTION(fmt::format(
      "Testing Full SDF Example, Ex. 3, variation 5 : \n{}\n",
        sdf_delayfile_ex3_5_str)) {

      CHECK(match_exactly<delay_file>(sdf_delayfile_ex3_5_str));
  }
  SECTION(fmt::format(
      "Testing Full SDF Example, Ex. 3, variation 6 : \n{}\n",
        sdf_delayfile_ex3_6_str)) {

      CHECK(match_exactly<delay_file>(sdf_delayfile_ex3_6_str));
  }
}
