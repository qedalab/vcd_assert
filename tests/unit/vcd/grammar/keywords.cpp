#include "vcd/grammar/keywords.hpp"

#include "parse/test/match.h"

#include <catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;

constexpr char comment_str[] = "$comment";
constexpr char date_str[] = "$date";
constexpr char dumpall_str[] = "$dumpall";
constexpr char dumpoff_str[] = "$dumpoff";
constexpr char dumpon_str[] = "$dumpon";
constexpr char dumpvars_str[] = "$dumpvars";
constexpr char end_str[] = "$end";
constexpr char end_definitions_str[] = "$enddefinitions";
constexpr char scope_str[] = "$scope";
constexpr char timescale_str[] = "$timescale";
constexpr char upscope_str[] = "$upscope";
constexpr char var_str[] = "$var";
constexpr char version_str[] = "$version";

TEST_CASE("VCD.Grammar.Keywords", "[VCD][Grammar][Keywords]") {
  CHECK(match_exactly<comment_keyword>(comment_str));
  CHECK(match_exactly<date_keyword>(date_str));
  CHECK(match_exactly<dumpall_keyword>(dumpall_str));
  CHECK(match_exactly<dumpoff_keyword>(dumpoff_str));
  CHECK(match_exactly<dumpon_keyword>(dumpon_str));
  CHECK(match_exactly<dumpvars_keyword>(dumpvars_str));
  CHECK(match_exactly<end_keyword>(end_str));
  CHECK(match_exactly<end_definitions_keyword>(end_definitions_str));
  CHECK(match_exactly<scope_keyword>(scope_str));
  CHECK(match_exactly<timescale_keyword>(timescale_str));
  CHECK(match_exactly<upscope_keyword>(upscope_str));
  CHECK(match_exactly<var_keyword>(var_str));
  CHECK(match_exactly<version_keyword>(version_str));
}
