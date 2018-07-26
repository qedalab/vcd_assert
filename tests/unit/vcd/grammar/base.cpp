#include "vcd/grammar/base.hpp"

#include "parse/test/match.hpp"
#include "parse/test/error_rule.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;

constexpr char empty[] = "";
constexpr char seperator_1[] = "\n";
constexpr char seperator_2[] = "  ";
constexpr char nz_1[] = "1";

TEST_CASE("VCD.Grammar.Base", "[VCD][Grammar]") {
  SECTION("Plus Blank") {
    CHECK(is_valid_error_rule<plus_blank>());
  }

  SECTION("CommandSeperator") {
    CHECK(match_exactly<command_separator>(empty));
    CHECK(match_exactly<command_separator>(seperator_1));
    CHECK(match_exactly<command_separator>(seperator_2));
  }

  SECTION("Identifier") {
    CHECK_FALSE(match_exactly<identifier>(""));
    CHECK_FALSE(match_exactly<identifier>("!"));
    CHECK_FALSE(match_exactly<identifier>("!!"));
  }
}
