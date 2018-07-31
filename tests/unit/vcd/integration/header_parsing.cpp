#include "vcd/grammar/grammar.hpp"
#include "vcd/types/header_reader.hpp"
#include "vcd/actions/header.hpp"
#include "vcd/test/header.hpp"

#include "../test/header.hpp"

#include "parse/actions/control.hpp"

#include <catch2/catch.hpp>
#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>

constexpr auto dro_example_input = R"($date
	Tue Jul 31 10:34:04 2018
$end
$version
	Icarus Verilog
$end
$timescale
	100fs
$end
$scope module tb_basic_dro $end
$var wire 1 ! out $end
$var reg 1 " reset $end
$var reg 1 # set $end
$scope module DUT $end
$var wire 1 " reset $end
$var wire 1 # set $end
$var wire 1 ! out $end
$var wire 1 $ internal_state_1 $end
$var wire 1 % internal_state_0 $end
$var reg 1 & internal_out $end
$var integer 32 ' state [31:0] $end
$upscope $end
$upscope $end
$enddefinitions $end)";

using namespace VCD;

TEST_CASE("VCD.Integration.HeaderParsing") {
  Test::TestHeader dro_example_test_header {
    TimeScale {TimeNumber::_100, TimeUnit::fs},
    "Tue Jul 31 10:34:04 2018",
    "Icarus Verilog",
    Test::TestScope {
      ScopeType::module,
      "tb_basic_dro",
      {
        Test::TestScope {
          ScopeType::module,
          "DUT",
          {
            // No modules in DUR
          },
          {
            {VarType::wire, 1, "\"", "reset"},
            {VarType::wire, 1, "#", "set"},
            {VarType::wire, 1, "!", "out"},
            {VarType::wire, 1, "$", "internal_state_1"},
            {VarType::wire, 1, "%", "internal_state_0"},
            {VarType::reg, 1, "&", "internal_out"},
            {VarType::integer, 32, "\'", "state [31:0]"},
          }
        }
      },
      {
        {VarType::wire, 1, "!", "out"},
        {VarType::reg, 1, "\"", "reset"},
        {VarType::reg, 1, "#", "set"}
      }
    }
  };

  VCD::HeaderReader vcd_reader{};
  tao::pegtl::memory_input<> vcd_input(dro_example_input, "dro_example");
  tao::pegtl::parse<
      VCD::Grammar::header_commands,
      Parse::make_pegtl_template<VCD::Actions::HeaderAction>::type,
      Parse::capture_control>(vcd_input, vcd_reader);

  auto header = vcd_reader.release();
  Test::catch_test_header(header, dro_example_test_header);
}
