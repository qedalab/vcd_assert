#include "parse/actions/apply/value.hpp"

#include <catch2/catch.hpp>

#include <string>

using namespace Parse;

TEST_CASE("Parse.Actions.Apply.Value", "[Actions][Apply]") {
  int state = 404;
  Apply::value<42>::apply0<struct Rule>(state);
  REQUIRE(state == 42);
}
