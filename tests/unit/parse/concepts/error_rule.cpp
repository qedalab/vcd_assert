#include "parse/concepts/error_rule.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Concepts;

struct FooSimpleRule {
  template <class Input, class... States>
  static bool match(Input& /*unused*/, States&&... /*unused*/) {return true;}
};

struct FooErrorRule : FooSimpleRule {
  static constexpr auto error() { return "error_string"; }
};

TEST_CASE("Parse.Concepts.ErrorRule", "[Concepts]") {
  REQUIRE(ErrorRule<FooErrorRule>);
  REQUIRE_FALSE(ErrorRule<FooSimpleRule>);
}
