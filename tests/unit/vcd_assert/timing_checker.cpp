#include "vcd_assert/timing_checker.hpp"
#include "../vcd/test/header.hpp"

#include <catch2/catch.hpp>

using namespace VCDAssert;
using namespace Verilog;
using namespace VCD;
using namespace SDF;

// TEST_CASE("VCDAssert.TimingChecker") {

//   VCD::Test::TestHeader vcd_4_state_example_header {
//     VCD::TimeScale {VCD::TimeNumber::_1, VCD::TimeUnit::ns},
//     "June 26, 1989 10:05:41",
//     "VERILOG-SIMULATOR 1.0a",
//     VCD::Test::TestScope {
//       ScopeType::module,
//       "top",
//       {
//           VCD::Test::TestScope {
//             ScopeType::module,
//             "m1",
//             {
//               // No modules in m1
//             },
//             {
//                 {VarType::trireg, 1, "*@", "net1"},
//                 {VarType::trireg, 1, "*#", "net2"},
//                 {VarType::trireg, 1, "*$", "net3"}
//             }
//           },
//           VCD::Test::TestScope {
//             ScopeType::task,
//             "t1",
//             {
//               // modules in t1
//             },
//             {
//                 {VarType::reg, 32, "(k", "accumulator[31:0]"},
//                 {VarType::integer, 32, "{k", "index"}
//             }
//           }
//       },
//       {
//         // No variables in top
//       }
//     }
//   };


//   SECTION("Empty") {
//     auto header = std::make_shared<Header>();
//     auto design = std::make_shared<Design>();
//     TimingChecker ttc(header, design);
//   }

//   // SECTION("Without SDF annotation"){
//   //   SECTION("No Design") {
//   //     HeaderReader reader;
//   //     Test::read_in_test_header(reader, vcd_4_state_example_header);
//   //     auto header = std::make_shared<Header>(reader.release());
//   //     auto design = std::make_shared<Design>(); //required to be the same?

//   //     TimingChecker ttc(header,design);
//   //   }

//   //   SECTION("Matching Design") {
//   //     HeaderReader h_reader;
//   //     DesignReader d_reader;
//   //     Test::read_in_test_header(reader, vcd_4_state_example_header);
//   //     Test::read_in_test_design(reader, vcd_4_state_example_header);
//   //     auto header = std::make_shared<Header>(reader.release());
//   //     auto design = std::make_shared<Design>(reader.release()); 

//   //     TimingChecker ttc(header,design);
//   //   }
//   // }

//   // SECTION("With SDF Annotation"){

//   //   SECTION("No Design supplied") {
//   //     HeaderReader h_reader;
//   //     DesignReader d_reader;
//   //     Test::read_in_test_header(reader, vcd_4_state_example_header);
//   //     Test::read_in_test_design(reader, vcd_4_state_example_header);
//   //     auto header = std::make_shared<Header>(reader.release());
//   //     auto design = std::make_shared<Verilog::Design>(); //required to be the same?

//   //     TimingChecker ttc(header,design);
//   //   }

//   //   SECTION("Matching Design and VCD Header"){

//   //     SECTION("Verilog embedded annotation commands") {
//   //       HeaderReader h_reader;
//   //       DesignReader d_reader;
//   //       Test::read_in_test_header(reader, vcd_4_state_example_header);
//   //       Test::read_in_test_design(reader, vcd_4_state_example_header);
//   //       auto header = std::make_shared<Header>(reader.release());
//   //       auto design = std::make_shared<Verilog::Design>(); //required to be the same?

//   //       TimingChecker ttc(header,design);
//   //     }

//   //     SECTION("Externally supplied SDF annotation") {
//   //       HeaderReader h_reader;
//   //       DesignReader d_reader;
//   //       Test::read_in_test_header(reader, vcd_4_state_example_header);
//   //       Test::read_in_test_design(reader, vcd_4_state_example_header);
//   //       auto header = std::make_shared<Header>(reader.release());
//   //       auto design = std::make_shared<Verilog::Design>(); //required to be the same?

//   //       TimingChecker ttc(header,design);
//   //     }
//   //   }

//   //   SECTION("Non-matching Design and VCD Header"){

//   //     //SHOULD FAIL ? TODO: REVISE REQUIREMENTS..
//   //     SECTION("Verilog embedded annotation commands (should fail)") {
//   //       HeaderReader h_reader;
//   //       DesignReader d_reader;
//   //       Test::read_in_test_header(reader, vcd_4_state_example_header);
//   //       Test::read_in_test_design(reader, vcd_4_state_example_header);
//   //       auto header = std::make_shared<Header>(reader.release());
//   //       auto design = std::make_shared<Verilog::Design>(); //required to be the same?

//   //       TimingChecker ttc(header,design);
//   //     }

//   //     SECTION("Externally supplied SDF annotation") {
//   //       HeaderReader h_reader;
//   //       DesignReader d_reader;
//   //       Test::read_in_test_header(reader, vcd_4_state_example_header);
//   //       Test::read_in_test_design(reader, vcd_4_state_example_header);
//   //       auto header = std::make_shared<Header>(reader.release());
//   //       auto design = std::make_shared<Verilog::Design>(); //required to be the same?

//   //       // REQUIRE_THROW(
//   //       TimingChecker ttc(header,design);

//   //     }
//   //   }
//   // }


//   // TODO: Not sure how to check this in isolation
// }

