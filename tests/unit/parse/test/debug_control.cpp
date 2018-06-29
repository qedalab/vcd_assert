#include "parse/test/debug_control.h"

#include "parse/test/match.h"
#include "parse/grammar/base.h"

#include <catch2/catch.hpp>

using namespace Parse::Test;
using namespace Parse;
using namespace Parse::Grammar;

auto expected_out =
    "Debug Trace:\n"
    "  level_fail failed\n"
    "\n"
    "  tao::pegtl::must<level_fail> at (1:3)\n"
    "  level_three at (1:2)\n"
    "  level_two at (1:1)\n"
    "  level_one at (1:0)\n";

struct level_fail : not_at<one<'-'>> {
  static constexpr auto error() {
    return "level_fail failed";
  }
};

struct level_three : seq<one<'('>, must<level_fail>, one<')'>> {};
struct level_two : seq<one<'('>, level_three, one<')'>> {};
struct level_one : seq<one<'('>, level_two, one<')'>> {};

TEST_CASE("DebugControl") {
  REQUIRE_THROWS_AS(match_exactly<level_one>("(((-)))"), DebugException);
  CHECK_THROWS_WITH(match_exactly<level_one>("(((-)))"), expected_out);

}
