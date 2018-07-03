#include "parse/actions/apply/float.hpp"

#include <catch2/catch.hpp>

#include <string>

// TODO Improve with proper ActionInput

using namespace Parse;

struct FloatActionInput {
  std::string string() const { return "3.14"; }
};

struct Rule;

TEST_CASE("Parse.Actions.Apply.Float", "[Actions][Apply]") {
  FloatActionInput input;
  double state;
  Apply::float_value::apply<Rule>(input, state);
  REQUIRE(state == Approx(3.14));
}
