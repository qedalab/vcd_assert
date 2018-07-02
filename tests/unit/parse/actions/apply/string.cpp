#include "parse/actions/apply/string.hpp"

#include <catch2/catch.hpp>

#include <string>

// TODO Improve with proper ActionInput

using namespace Parse;

struct StringActionInput {
  std::string string() const { return "action_input"; }
};

struct Rule;

TEST_CASE("Parse.Actions.Apply.String", "[Actions][Apply]") {
  StringActionInput input;
  std::string state;
  Apply::string::apply<Rule>(input, state);
  REQUIRE(state == "action_input");
}
