#include "parse/capture/dispatch.hpp"

#include "parse/capture/apply.hpp"
#include "parse/capture/apply0.hpp"
#include "parse/capture/inner_action.hpp"

#include <catch2/catch.hpp>

struct Rule;
struct Dispatch;
struct Action;
struct Storage;
struct Apply;

struct HasDispatch {
  static Dispatch dispatch(Parse::Internal::Tag<Rule>);
};

struct Empty {};

TEST_CASE("Parse.Capture.Dispatch", "[Capture]") {
  //decltype(Action::dispatch(Internal::Tag<Rule>{});
  CHECK(Parse::action_has_tag_dispatch<HasDispatch, Rule>);
  CHECK_FALSE(Parse::action_has_tag_dispatch<Empty, Rule>);
}
