#include "vcd/actions/header.hpp"

#include "parse/test/parse.hpp"
#include "vcd/grammar/grammar.hpp"
#include "vcd/test/header.hpp"

#include <catch2/catch.hpp>

using namespace VCD;

constexpr auto four_state_vcd_example_header_str =
    "$date June 26, 1989 10:05:41\n"
    "$end\n"
    "$version VERILOG-SIMULATOR 1.0a\n"
    "$end\n"
    "$timescale 1 ns\n"
    "$end\n"
    "$scope module top $end\n"
    "$scope module m1 $end\n" // Error here?
    "$var trireg 1 *@ net1 $end\n"
    "$var trireg 1 *# net2 $end\n"
    "$var trireg 1 *$ net3 $end\n"
    "$upscope $end\n"
    "$scope task t1 $end\n"
    "$var reg 32 (k accumulator[31:0] $end\n"
    "$var integer 32 {2 index $end\n"
    "$upscope $end\n"
    "$upscope $end\n"
    "$enddefinitions $end\n";

TEST_CASE("VCD.Events.Header", "[VCD][Events][Header]") {
  Test::TestHeader vcd_4_state_example_header {
      TimeScale {TimeNumber::_1, TimeUnit::ns},
      "June 26, 1989 10:05:41",
      "VERILOG-SIMULATOR 1.0a",
      Test::TestScope {
          ScopeType::module,
          "top",
          {
              Test::TestScope {
                  ScopeType::module,
                  "m1",
                  {
                      // No modules in m1
                  },
                  {
                      {VarType::trireg, 1, "*@", "net1"},
                      {VarType::trireg, 1, "*#", "net2"},
                      {VarType::trireg, 1, "*$", "net3"}
                  }
              },
              Test::TestScope {
                  ScopeType::task,
                  "t1",
                  {
                      // modules in t1
                  },
                  {
                      {VarType::reg, 32, "(k", "accumulator[31:0]"},
                      {VarType::integer, 32, "{2", "index"}
                  }
              }
          },
          {
              // No variables in top
          }
      }
  };

  using Parse::Test::require_parse;

  HeaderReader reader;
  require_parse<Grammar::header_commands, Actions::HeaderAction>(
      four_state_vcd_example_header_str, reader);

  auto header_p = reader.release();
  REQUIRE(header_p.operator bool());
  Test::catch_test_header(*header_p, vcd_4_state_example_header);
}

