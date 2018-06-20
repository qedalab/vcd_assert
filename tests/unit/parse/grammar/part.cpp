#include "parse/grammar/part.h"
#include "parse/test/match.h"

#include <catch2/catch.hpp>

using namespace Parse::Grammar;
using namespace Parse::Test;

TEST_CASE("Parse.Grammar.Part","[Parse][Parse.Grammar][Parse.Grammar.Base]") {

  SECTION("Sign") {
    CHECK(match_exactly<sign>("+"));
    CHECK(match_exactly<sign>("-"));
    CHECK(!match_exactly<sign>("?"));
  }

  SECTION("NonZero") {
    CHECK(match_exactly<non_zero>("1"));
    CHECK(match_exactly<non_zero>("9"));
    CHECK(!match_exactly<non_zero>("0"));
  }

}
