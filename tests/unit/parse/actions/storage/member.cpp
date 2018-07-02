#include "parse/actions/storage/member.hpp"

#include <catch2/catch.hpp>

using namespace Parse;

struct Return {};

struct HasMember {
  int member = 404;
};

TEST_CASE("Parse.Actions.Storage.Member", "[Actions][Storage]") {
  using function_storage = Storage::member<&HasMember::member>;

  HasMember parent;

  REQUIRE(parent.member != 42);
  function_storage::store(parent, 42);
  REQUIRE(parent.member == 42);
}
