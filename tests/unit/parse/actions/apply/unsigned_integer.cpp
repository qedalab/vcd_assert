#include "parse/actions/apply/unsigned_integer.hpp"

#include <catch2/catch.hpp>

#include <string>

// TODO Improve with proper ActionInput

using namespace Parse;

struct UnsignedIntegerActionInput {
  std::string string() const { return "42"; }
};

struct Rule;

TEST_CASE("Parse.Actions.Apply.UnsignedInteger", "[Actions][Apply]") {
  UnsignedIntegerActionInput input;
  unsigned int state;
  Apply::unsigned_integer::apply<Rule>(input, state);
  REQUIRE(state == Approx(42));
}
