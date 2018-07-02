#include "parse/concepts/complex_rule.hpp"

#include <catch2/catch.hpp>

#include <tao/pegtl/rules.hpp>

using namespace Parse::Concepts;

struct FooComplexRule {
  using apply_mode = tao::pegtl::apply_mode;
  using rewind_mode = tao::pegtl::rewind_mode;

  template <apply_mode A, rewind_mode M, template<typename...> class Action, 
           template<typename...> class Control, class Input, class... States>
  static bool match(Input& input, States&&... states);
};

struct FooBad {};

TEST_CASE("Parse.Concepts.ComplexRule", "[Concepts]") {
  REQUIRE(ComplexRule<FooComplexRule>);
  REQUIRE_FALSE(ComplexRule<FooBad>);
}
