#include "vcd/grammar/value.hpp"

#include "parse/test/match.hpp"

#include <catch2/catch.hpp>

constexpr char scalar_str[] = "1*@";
constexpr char vector_str[] = "b1100x01z (k";
constexpr char binary_number_str[] = "b1100x01z";
constexpr char binary_value_str[] = "1100x01z";
constexpr char binary_base_str[] = "b";

using namespace Parse::Test;
using namespace VCD::Grammar;

TEST_CASE("VCD.Grammar.Value","[VCD][Grammar]") {
  SECTION("BinaryValue") {
    CHECK(match_exactly<binary_value>(binary_value_str));
  }

  SECTION("BinaryBase") {
    CHECK(match_exactly<binary_base>(binary_base_str));
  }

  SECTION("BinaryNumber") {
    CHECK(match_exactly<binary_number>(binary_number_str));
  }

  SECTION("BinaryValueChange") {
    CHECK(match_exactly<binary_value_change>(vector_str));
  }

  SECTION("Individual ValueChange") {
    CHECK(match_exactly<scalar_value_change>(scalar_str));
    CHECK(match_exactly<vector_value_change>(vector_str));
  }

  SECTION("Together ValueChange") {
    CHECK(match_exactly<value_change>(scalar_str));
    CHECK(match_exactly<value_change>(vector_str));
  }
}
