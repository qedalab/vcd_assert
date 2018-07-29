#include "vcd_assert/timing_checker.hpp"
#include "../vcd/test/header.hpp"

#include <catch2/catch.hpp>

using namespace VCDAssert;
using namespace VCD;

TEST_CASE("VCDAssert.TimingChecker") {

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
                {VarType::integer, 32, "{k", "index"}
            }
          }
      },
      {
        // No variables in top
      }
    }
  };


  SECTION("Empty") {
    auto header = std::make_shared<VCD::Header>();
    auto design = std::make_shared<Verilog::Design>();
    TimingChecker ttc(header, design);
  }

  SECTION("No SDF") {
    HeaderReader reader;
    Test::read_in_test_header(reader, vcd_4_state_example_header);
    auto header = std::make_shared<Header>(reader.release());
    auto design = std::make_shared<Verilog::Design>(); //required to be the same?

    TimingChecker ttc(header,design);
  }

  // TODO: Not sure how to check this in isolation
}

