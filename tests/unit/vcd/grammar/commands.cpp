#include "vcd/grammar/commands.hpp"

#include "parse/test/match.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;

// NOTE: comment_multiline has been made auto to work around false CLion error

constexpr char end_definitions_str[] = "$enddefinitions $end";
constexpr char upscope_str[] = "$upscope $end";
constexpr char scope_str[] = "$scope\n    module top\n$end";
constexpr char comment_line[] = "$comment This is a single line comment $end";
constexpr auto comment_multiline = "$comment This is a\n"
                                   "multiple-line comment\n$end";
constexpr char date_str[] = "$date\n  June 25, 1989 09:24:35\n$end";
constexpr auto version_str = "$version\n    VERILOG-SIMULATOR 1.0a\n"
                             "    $dumpfile(\"dump1.dump\")\n$end";
constexpr char timescale_str[] = "$timescale 10 ns $end";
constexpr char var_str[] = "$var\n  integer 32 (2 index\n$end";
constexpr char dumpall_str[] = "$dumpall 1*@ x*# 0*$ bx (k $end";
constexpr char dumpoff_str[] = "$dumpoff x*@ x*# x*$ bx (k $end";
constexpr char dumpon_str[] = "$dumpon x*@ 0*# x*$ b1 (k $end";
constexpr char dumpvars_str[] = "$dumpvars x*@ z*$ b0 (k $end";

TEST_CASE("VCD.Grammar.Commands", "[VCD][Grammar][Commands]")
{
  SECTION("Comment") {
    CHECK(match_exactly<comment_command>(comment_line));
    CHECK(match_exactly<comment_command>(comment_multiline));
  }

  SECTION("Version") {
    CHECK(match_exactly<version_command>(version_str));
  }

  SECTION("TimeScale") {
    CHECK(match_exactly<timescale_command>(timescale_str));
  }

  SECTION("Date") {
    CHECK(match_exactly<date_command>(date_str));
  }

  SECTION("EndDefinitions") {
    CHECK(match_exactly<end_definitions_command>(end_definitions_str));
  }

  SECTION("Scope") {
    CHECK(match_exactly<scope_command>(scope_str));
  }

  SECTION("UpScope") {
    CHECK(match_exactly<upscope_command>(upscope_str));
  }

  SECTION("Dump") {
    SECTION("All") {
      CHECK(match_exactly<dumpall_command>(dumpall_str));
    }

    SECTION("On") {
      CHECK(match_exactly<dumpon_command>(dumpon_str));
    }

    SECTION("Off") {
      CHECK(match_exactly<dumpoff_command>(dumpoff_str));
    }

    SECTION("Vars") {
      CHECK(match_exactly<dumpvars_command>(dumpvars_str));
    }
  }

  SECTION("Var") {
    SECTION("Reference") {
      CHECK(match_exactly<reference>("index"));
    }
    CHECK(match_exactly<var_command>(var_str));
  }

}
