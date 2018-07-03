#include "vcd/serialize/scope.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.Scope", "[Serialize]") {
  std::string output1;
  VCD::serialize_scope(ranges::back_inserter(output1),
                       {ScopeType::module, "my_scope"});
  CHECK(output1 == "$scope module my_scope $end\n");

  std::string output2;
  VCD::serialize_upscope(ranges::back_inserter(output2));
  CHECK(output2 == "$upscope $end\n");
}
