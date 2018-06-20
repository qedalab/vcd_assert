#include "vcd/types/header_reader.hpp"
#include "./header.hpp"

#include <catch2/catch.hpp>

using namespace VCD;

Test::TestHeader vcd_empty_header {};

static Test::TestHeader vcd_4_state_example_header {
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

TEST_CASE("VCD.Types.VCDHeaderReader") {
  SECTION("Case 1: Empty") {
    //Write Header file with the same structure as the VCD example
    HeaderReader reader;
    Test::read_in_test_header(reader, vcd_empty_header);
    auto header_p = reader.release();
    REQUIRE(header_p.operator bool());
    auto &header = *header_p.get();
    Test::catch_test_header(header, vcd_empty_header);
  }

  SECTION("Case 2: From VCD Example") {
    //Write Header file with the same structure as the VCD example
    HeaderReader reader;
    Test::read_in_test_header(reader, vcd_4_state_example_header);
    auto header_p = reader.release();
    REQUIRE(header_p.operator bool());
    auto &header = *header_p.get();
    Test::catch_test_header(header, vcd_4_state_example_header);
  }
}


