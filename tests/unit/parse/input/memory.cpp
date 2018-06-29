#include "parse/input/memory.h"

#include <catch2/catch.hpp>
#include <string>
#include <vector>

using namespace Parse;

TEST_CASE("MemoryInput", "[Input]")
{
  std::vector<std::string> test_data {
    "qwer",
    "asdf\nzxcv",
    "a\0bs"
  };

  SECTION("Data")
  {
    for(const auto test_case: test_data) {
      MemoryInput parser{test_case};
      REQUIRE(parser.size() == test_case.size());
      REQUIRE(std::equal(test_case.begin(), test_case.end(), parser.data()));
    }
  }
}
