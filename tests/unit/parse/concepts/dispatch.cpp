#include "parse/concepts/dispatch.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Concepts;

struct FooRule {};
struct FooNotRule {};
struct FooCommand {};

struct FooDispatchRule {
  static FooCommand dispatch(Parse::Util::Tag<FooRule>);
};

struct FooDispatchNotRule {
  static FooCommand dispatch(Parse::Util::Tag<FooNotRule>);
};

TEST_CASE("Parse.Concepts.Dispatch", "[Concepts]") {
  SECTION("DispatchRule") {
    REQUIRE(DispatchRule<FooDispatchRule, FooRule>);
    REQUIRE_FALSE(DispatchRule<FooDispatchNotRule, FooRule>);
  }
}
