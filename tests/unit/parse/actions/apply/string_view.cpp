#include "parse/actions/apply/string_view.hpp"

#include <catch2/catch.hpp>

#include <string_view>

// TODO Improve with proper ActionInput

using namespace Parse;

constexpr char action_input_cstr[] = "action_input";

struct StringViewActionInput {
  const char *begin() const { return action_input_cstr; }
  std::size_t size() const { return sizeof(action_input_cstr) - 1; }
};

struct Rule;

TEST_CASE("Parse.Actions.Apply.StringView", "[Actions][Apply]") {
  StringViewActionInput input;
  std::string state;
  Apply::string_view::apply<Rule>(input, state);
  REQUIRE(state == action_input_cstr);
}
