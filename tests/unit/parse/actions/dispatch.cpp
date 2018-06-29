#include "parse/actions/dispatch.hpp"

#include <catch2/catch.hpp>

using namespace Parse;

struct Rule;
struct Dispatch;

struct HasDispatch {
  static Dispatch dispatch(Parse::Internal::Tag<Rule>);
};

struct Empty {};

TEST_CASE("Parse.Capture.Dispatch", "[Capture]") {
  SECTION("action_has_tag_dispatch") {
    CHECK(action_has_tag_dispatch<HasDispatch, Rule>);
    CHECK_FALSE(action_has_tag_dispatch<Empty, Rule>);
  }

  SECTION("action_tag_dispatch_decl") {
    using dispatch_decl = action_tag_dispatch_decl<HasDispatch, Rule>;
    CHECK(std::is_same_v<Dispatch, dispatch_decl>);
  }

  // TODO single_dispatch tests
  // TODO multi_dispatch tests
}
