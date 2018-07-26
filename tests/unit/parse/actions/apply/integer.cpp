#include "parse/actions/apply/integer.hpp"

#include <catch2/catch.hpp>

#include <string>

// TODO Improve with proper ActionInput

using namespace Parse;

struct IntegerActionInput {
  std::string string() const { return "42"; }
};

struct Rule;

TEST_CASE("Parse.Actions.Apply.Integer", "[Actions][Apply]") {
  IntegerActionInput input;
  int state;
  Apply::integer::apply<Rule>(input, state);
  REQUIRE(state == Approx(42));
}
