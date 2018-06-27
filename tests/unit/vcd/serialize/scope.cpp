#include "vcd/serialize/scope.hpp"

#include <catch2/catch.hpp>
#include <range/v3/utility/iterator.hpp>

using namespace VCD;

TEST_CASE("VCD.Serialize.Scope", "[Serialize]") {
  std::string output;
  VCD::serialize_scope(ranges::back_inserter(output),
                       {ScopeType::module, "my_scope"});
  CHECK(output == "$scope module my_scope $end\n");
}
