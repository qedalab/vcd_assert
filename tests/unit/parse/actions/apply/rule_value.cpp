#include "parse/actions/apply/rule_value.hpp"

#include <catch2/catch.hpp>

#include <string>

using namespace Parse;

struct Rule {
  static constexpr auto value = 42;

  template <class Input, class... States>
  static bool match(Input& /*unused*/, States&&... /*unused*/) {return true;}
};

TEST_CASE("Parse.Actions.Apply.RuleValue", "[Actions][Apply]") {
  int state = 404;
  Apply::rule_value::apply0<Rule>(state);
  REQUIRE(state == 42);
}
