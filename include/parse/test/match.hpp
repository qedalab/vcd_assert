#ifndef LIBPARSE_TEST_MATCH_HPP
#define LIBPARSE_TEST_MATCH_HPP

#include "./debug_control.hpp"
#include "../actions/apply/rule_value.hpp"
#include "../actions/make_pegtl_template.hpp"

#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>
#include <tao/pegtl/rules.hpp>

namespace Parse::Test {

template <class Rule>
bool match_exactly(const std::string_view str) {
  tao::pegtl::memory_input<> input(str.begin(), str.end(), "match_exactly");

  bool success =
      tao::pegtl::parse<Rule, tao::pegtl::nothing, debug_control>(input);
  bool end_of_str = tao::pegtl::parse<tao::pegtl::eof>(input);

  return success and end_of_str;
}

template <class Rule, class Enum>
bool match_value_exactly(const std::string_view str, Enum value) {
  auto state = static_cast<Enum>(0);
  if (state == value)
    state = static_cast<Enum>(1);

  tao::pegtl::memory_input<> input(str.begin(), str.end(),
                                   "match_value_exactly");

  using rule_action = make_pegtl_apply0<Apply::rule_value>;
  bool success = tao::pegtl::parse
      <Rule, rule_action::template type, debug_control>(input, state);

  bool end_of_str = tao::pegtl::parse<tao::pegtl::eof>(input);
  bool value_match = state == value;

  return success and end_of_str and value_match;
};

} // namespace Parse::Test

#endif // LIBPARSE_TEST_MATCH_HPP
