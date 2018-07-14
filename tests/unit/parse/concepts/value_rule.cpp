#include "parse/concepts/value_rule.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Concepts;

struct FooSimpleRule {
  template <class Input, class... States>
  static bool match(Input& /*unused*/, States&&... /*unused*/) {return true;}
};

struct FooValueRule : FooSimpleRule {
  static constexpr auto value = true;
};

TEST_CASE("Parse.Concepts.ValueRule", "[Concepts]") {
  REQUIRE(ValueRule<FooValueRule>);
  REQUIRE_FALSE(ValueRule<FooSimpleRule>);
}
