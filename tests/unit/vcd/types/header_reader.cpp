#include "vcd/types/header_reader.hpp"

#include "../test/header.hpp"

#include "vcd/util/size.hpp"
#include "vcd/test/header.hpp"

#include <catch2/catch.hpp>

using namespace VCD;

Test::TestHeader vcd_empty_header {};

TEST_CASE("VCD.Types.VCDHeaderReader") {
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

  SECTION("Case 1: Empty") {
    //Write Header file with the same structure as the VCD example
    HeaderReader reader;
    Test::read_in_test_header(reader, vcd_empty_header);
    auto header = reader.release();
    Test::catch_test_header(header, vcd_empty_header);
    CHECK(Util::get_max_var_size(header) == 0);
  }

  SECTION("Case 2: From VCD Example") {
    //Write Header file with the same structure as the VCD example
    HeaderReader reader;
    Test::read_in_test_header(reader, vcd_4_state_example_header);
    auto header = reader.release();
    Test::catch_test_header(header, vcd_4_state_example_header);
    CHECK(Util::get_max_var_size(header) == 32);
  }

  SECTION("Case 3: More than one base scope") {
    HeaderReader reader;
    reader.scope(ScopeType::begin, "scope_1");
    reader.upscope();
    CHECK_THROWS(reader.scope(ScopeType::begin, "scope_2"));
  }

  SECTION("Case 4: Duplicate scope name") {
    HeaderReader reader;
    reader.scope(ScopeType::begin, "base");
    reader.scope(ScopeType::begin, "duplicate");
    reader.upscope();
    CHECK_THROWS(reader.scope(ScopeType::begin, "duplicate"));
  }

  SECTION("Case 5: Upscope on no scope") {
    HeaderReader reader;
    CHECK_THROWS(reader.upscope());
  }

  SECTION("Case 6: Variable without scope") {
    HeaderReader reader;
    CHECK_THROWS(reader.var(VarType::reg, 1 , "id", "ref"));
  }

  SECTION("Case 7: Overwrites") {
    SECTION("Version") {
      HeaderReader reader;
      reader.version("string_1");
      REQUIRE_THROWS(reader.version("string_2"));
      auto header = reader.release();
      auto string_1 = header.get_version();

      REQUIRE(string_1.has_value());
      CHECK(string_1.value() == "string_1");

      reader.version("string_1");
      reader.overwrite_version("string_2");
      header = reader.release();
      auto string_2 = header.get_version();

      REQUIRE(string_2.has_value());
      CHECK(string_2.value() == "string_2");
    }

    SECTION("Date") {
      HeaderReader reader;
      reader.date("string_1");
      REQUIRE_THROWS(reader.date("string_2"));
      auto header = reader.release();
      auto string_1 = header.get_date();

      REQUIRE(string_1.has_value());
      CHECK(string_1.value() == "string_1");

      reader.date("string_1");
      reader.overwrite_date("string_2");
      header = reader.release();
      auto string_2 = header.get_date();

      REQUIRE(string_2.has_value());
      CHECK(string_2.value() == "string_2");
    }

    SECTION("TimeScale") {
      HeaderReader reader;
      reader.timescale(TimeNumber::_1, TimeUnit::s);
      REQUIRE_THROWS(reader.timescale(TimeNumber::_10, TimeUnit::ps));
      auto header = reader.release();
      auto ts_1 = header.get_time_scale();

      REQUIRE(ts_1.has_value());
      CHECK(ts_1.value().get_number() == TimeNumber::_1);
      CHECK(ts_1.value().get_unit() == TimeUnit::s);

      reader.timescale(TimeNumber::_1, TimeUnit::s);
      reader.overwrite_timescale(TimeNumber::_10, TimeUnit::ps);
      header = reader.release();
      auto ts_2 = header.get_time_scale();

      REQUIRE(ts_2.has_value());
      CHECK(ts_2.value().get_number() == TimeNumber::_10);
      CHECK(ts_2.value().get_unit() == TimeUnit::ps);
    }
  }

  SECTION("Case 8: Same identifiers") {
    SECTION("Matches") {
      HeaderReader reader;
      reader.scope(ScopeType::begin, "scope");
      reader.var(VarType::reg, 1, "id_code", "ref_1");
      reader.var(VarType::reg, 1, "id_code", "ref_2");
      reader.upscope();

      auto header = reader.release();

      CHECK(header.num_id_codes() == 1);
    }

    SECTION("Doesn't match") {
      HeaderReader reader;
      reader.scope(ScopeType::begin, "scope");
      reader.var(VarType::reg, 1, "id_code", "ref_1");
      CHECK_THROWS(reader.var(VarType::reg, 2, "id_code", "ref_2"));
    }
  }

  SECTION("Case 9: Release with scope") {
    HeaderReader reader;
    reader.scope(ScopeType::begin, "scope");
    CHECK_THROWS(reader.release());
  }
}


