#include "parse/concepts/simple_rule.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Concepts;

struct FooSimpleRule {
  template <class Input, class... States>
  static bool match(Input&, States&&...) {return true;}
};

struct FooBad {};

TEST_CASE("Parse.Concepts.SimpleRule", "[Concepts]") {
  REQUIRE(SimpleRule<FooSimpleRule>);
  REQUIRE_FALSE(SimpleRule<FooBad>);
}
