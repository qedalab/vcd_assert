#include "sdf/actions/delayfile.hpp"
#include "sdf/grammar/grammar.hpp"
#include "parse/test/parse.hpp"
// #include "../types/header.hpp"

#include <catch2/catch.hpp>

using namespace SDF;

auto constexpr sdf_header_str = 
R"###(
  (SDFVERSION "4.0")
  (DESIGN "system")
  (DATE "Saturday September 30 08:30:33 PST 1990")
  (VENDOR "Yosemite Semiconductor")
  (PROGRAM "delay_calc")
  (VERSION "1.5")
  (DIVIDER /)
  (VOLTAGE 5.5:5.0:4.5)
  (PROCESS "worst")
  (TEMPERATURE 55:85:125)
  (TIMESCALE 1ns)
)###";

// static Test::TestHeader sdf_header_example_header {
//     TimeScale {TimeNumber::_1, TimeUnit::ns},
//     "June 26, 1989 10:05:41",
//     "VERILOG-SIMULATOR 1.0a",
//     Test::TestScope {
//         ScopeType::module,
//         "top",
//         {
//             Test::TestScope {
//                 ScopeType::module,
//                 "m1",
//                 {
//                     // No modules in m1
//                 },
//                 {
//                     {VarType::trireg, 1, "*@", "net1"},
//                     {VarType::trireg, 1, "*#", "net2"},
//                     {VarType::trireg, 1, "*$", "net3"}
//                 }
//             },
//             Test::TestScope {
//                 ScopeType::task,
//                 "t1",
//                 {
//                     // modules in t1
//                 },
//                 {
//                     {VarType::reg, 32, "(k", "accumulator[31:0]"},
//                     {VarType::integer, 32, "{2", "index"}
//                 }
//             }
//         },
//         {
//             // No variables in top
//         }
//     }
// };

// TEST_CASE("VCD.Events.Header", "[VCD][Events][Header]") {
//   using Parse::Test::require_parse;

//   HeaderReader reader;
//   require_parse<Grammar::header_commands, Actions::HeaderAction>(
//       four_state_vcd_example_header_str, reader);

//   auto header_p = reader.release();
//   REQUIRE(header_p.operator bool());
//   auto &header = *header_p.get();
//   Test::catch_test_header(header, vcd_4_state_example_header);
// }

