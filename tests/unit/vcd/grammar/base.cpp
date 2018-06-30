#include "vcd/grammar/base.hpp"

#include "parse/test/match.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;

constexpr char empty[] = "";
constexpr char seperator_1[] = "\n";
constexpr char seperator_2[] = "  ";
constexpr char nz_1[] = "1";

TEST_CASE("VCD.Grammar.Base", "[VCD][Grammar]") {
  SECTION("CommandSeperator") {
    CHECK(match_exactly<command_separator>(empty));
    CHECK(match_exactly<command_separator>(seperator_1));
    CHECK(match_exactly<command_separator>(seperator_2));
  }
}
