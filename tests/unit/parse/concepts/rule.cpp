#include "parse/concepts/rule.hpp"

#include <catch2/catch.hpp>

using namespace Parse::Concepts;

struct FooComplexRule {
  using apply_mode = tao::pegtl::apply_mode;
  using rewind_mode = tao::pegtl::rewind_mode;

  template <apply_mode A, rewind_mode M, template<typename...> class Action, 
           template<typename...> class Control, class Input, class... States>
  static bool match(Input& input, States&&... states);
};

struct FooSimpleRule {
  using apply_mode = tao::pegtl::apply_mode;
  using rewind_mode = tao::pegtl::rewind_mode;

  template <class Input, class... States>
  static bool match(Input& input, States&&... states);
};

struct FooBad {};

TEST_CASE("Parse.Concepts.Rule", "[Concepts]") {
  REQUIRE(Rule<FooComplexRule>);
  REQUIRE(Rule<FooSimpleRule>);
  REQUIRE_FALSE(Rule<FooBad>);
}
