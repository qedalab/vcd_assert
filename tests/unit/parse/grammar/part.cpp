#include "parse/grammar/part.h"
#include "parse/test/match.h"

#include <catch.hpp>

#include <parse/test/error.h>

using namespace Parse::Grammar;
using namespace Parse::Test;

TEST_CASE("Parse.Grammar.Part","[Parse][Parse.Grammar][Parse.Grammar.Base]") {

  SECTION("Sign") {
    CHECK(match_exactly<sign>("+"));
    CHECK(match_exactly<sign>("-"));
    CHECK(!match_exactly<sign>("?"));
    CHECK(has_member_static_fun_error<sign>);
  }

  SECTION("NonZero") {
    CHECK(match_exactly<non_zero>("1"));
    CHECK(match_exactly<non_zero>("9"));
    CHECK(!match_exactly<non_zero>("0"));
    CHECK(has_member_static_fun_error<non_zero>);
  }

}
