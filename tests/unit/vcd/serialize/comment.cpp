#include "vcd/serialize/comment.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.Comment", "[Serialize]") {
  std::string output;
  VCD::serialize_comment(ranges::back_inserter(output), "my_comment");
  CHECK(output == "$comment my_comment $end\n");
}
