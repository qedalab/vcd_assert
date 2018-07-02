#include "parse/actions/storage/function.hpp"

#include <catch2/catch.hpp>

using namespace Parse;

struct Return {};
struct State {};

struct HasFunction {
  int called =0;

  Return function([[maybe_unused]] State state) {
    called++;
    return {};
  }
};

TEST_CASE("Parse.Actions.Storage.Function", "[Parse][Actions][Storage]") {
  using function_storage = Storage::function<&HasFunction::function>;

  HasFunction parent;
  State child;

  REQUIRE(parent.called == 0);
  function_storage::store(parent, child);
  REQUIRE(parent.called == 1);
}
