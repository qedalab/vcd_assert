#include "parse/internal/array_append.h"

#include <catch2/catch.hpp>

using namespace Parse;

constexpr std::array arr_1 {'a'};
constexpr std::array arr_2 {'b', 'c', 'd'};
constexpr std::array arr_3 {'e'};

constexpr std::array arr_123 {'a', 'b', 'c', 'd', 'e'};

TEST_CASE("Parse.Internal.ArrayAppend") {
  constexpr auto appended_arr = Internal::array_append(arr_1, arr_2, arr_3);
  REQUIRE(std::equal(arr_123.begin(), arr_123.end(), appended_arr.begin()));
}
