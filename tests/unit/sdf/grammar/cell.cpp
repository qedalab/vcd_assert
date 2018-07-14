#include "cell.hpp"


using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;

TEST_CASE("SDF.Grammar.Cell", "[SDF][Grammar][Cell]") {


  SECTION(fmt::format(
      "Testing timing_spec_str  : \n{}\n",
        sdf_cell_ex1_str)) {
      REQUIRE(match_exactly<cell>(sdf_cell_ex1_str));
  }

  SECTION(fmt::format(
      "Testing timing_spec_str  : \n{}\n",
        sdf_cell_ex2_str)) {          
      REQUIRE(match_exactly<cell>(sdf_cell_ex2_str));
  }
}