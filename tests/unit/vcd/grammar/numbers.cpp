#include "vcd/grammar/numbers.hpp"

#include "parse/test/match.h"

#include <catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;

constexpr char empty[] = "";
constexpr char nz_1[] = "32";

TEST_CASE("VCD.Grammar.Numbers", "[VCD][Grammar]") {
  SECTION("NonZeroUnsignedNumber") {
    CHECK(!match_exactly<non_zero_unsigned_number>(empty));
    CHECK(match_exactly<non_zero_unsigned_number>(nz_1));
  }

}
