#include "timing.hpp"
#include "grammar.hpp"
#include "delayfile.hpp"

using namespace Parse::Test;
using namespace SDF::Grammar;
using namespace Test::SDF::Grammar;

TEST_CASE("SDF.Grammar.Timing", "[SDF][Grammar][Timing]") {


  SECTION(fmt::format(
      "Testing timing_spec_str check : \n{}\n",
        tc_spec_str)) {
          
      REQUIRE(match_exactly<timing_spec>(tc_spec_str));
  }
  SECTION(fmt::format(
      "Testing tc_spec_str check : \n{}\n",
        tc_spec_str)) {
          
      REQUIRE(match_exactly<tc_spec>(tc_spec_str));
  }
  SECTION(fmt::format(
      "Testing setup_timing_check_str check : \n{}\n",
        setup_timing_check_str)) {
          
      REQUIRE(match_exactly<setup_timing_check>(setup_timing_check_str));
  }
  SECTION(fmt::format(
      "Testing hold_timing_check_str check : \n{}\n",
        hold_timing_check_str)) {
          
      REQUIRE(match_exactly<hold_timing_check>(hold_timing_check_str));
  }
  SECTION(fmt::format(
      "Testing setuphold_timing_check_str check : {}",
        setuphold_timing_check_str)
        ) {
          
      REQUIRE(match_exactly<setuphold_timing_check>(setuphold_timing_check_str));
  }
  SECTION(fmt::format(
      "Testing recovery_timing_check_str check : \n{}\n",
        recovery_timing_check_str)) {
          
      REQUIRE(match_exactly<recovery_timing_check>(recovery_timing_check_str));
  }
  SECTION(fmt::format(
      "Testing width_timing_check_str check : \n{}\n",
        width_timing_check_str)) {
          
      REQUIRE(match_exactly<width_timing_check>(width_timing_check_str));
  }
  SECTION(fmt::format(
      "Testing port_tchk_str  : \n{}\n",
        port_tchk_str)) {
          
      REQUIRE(match_exactly<port_tchk>(port_tchk_str));
  }

}