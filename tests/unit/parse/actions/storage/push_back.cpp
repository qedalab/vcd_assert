#include "parse/actions/storage/push_back.hpp"

#include <catch2/catch.hpp>

#include <vector>

using namespace Parse;

TEST_CASE("Parse.Actions.Storage.PushBack", "[Actions][Storage]") {
  using function_storage = Storage::push_back;

  std::vector<int> parent;

  function_storage::store(parent, 42);
  REQUIRE(parent.size() == 1);
  REQUIRE(parent[0] == 42);
}
