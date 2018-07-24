#include "parse/input/memory.h"

#include <catch2/catch.hpp>
#include <string>
#include <vector>

using namespace Parse;

TEST_CASE("MemoryInput", "[Input]")
{
  std::vector<std::string_view> test_data {
    "qwer",
    "asdf\nzxcv",
    "a\fbs"
  };

  SECTION("Data")
  {
    for(const auto test_case: test_data) {
      MemoryInput parser{test_case};
      REQUIRE(parser.size() == test_case.size());
      REQUIRE(std::equal(test_case.begin(), test_case.end(), parser.data()));
      REQUIRE_FALSE(std::string(parser.source()).empty());
    }
  }
}
