#include "vcd/grammar/numbers.hpp"

#include "parse/test/match.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Test;
using namespace VCD::Grammar;

constexpr char empty[] = "";
constexpr char nz_1[] = "32";

TEST_CASE("VCD.Grammar.Numbers", "[VCD][Grammar]") {
  SECTION("NonZeroUnsignedNumber") {
    CHECK(!match_exactly<non_zero_unsigned_number>(empty));
    CHECK(match_exactly<non_zero_unsigned_number>(nz_1));
  }

  SECTION("Real") {
    CHECK(match_exactly<real_number>("2"));
    CHECK(match_exactly<real_number>("3.14"));
    CHECK(match_exactly<real_number>("1e2"));
    CHECK(match_exactly<real_number>("1.5e2"));
    CHECK(match_exactly<real_number>("1e-2"));
    CHECK(match_exactly<real_number>("1.5E-2"));
  }
}
