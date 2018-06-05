#ifndef PARSE_TEST_MATCH_H_
#define PARSE_TEST_MATCH_H_

#include "parse/action/enum.h"
#include "./debug_control.h"

#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>
#include <tao/pegtl/rules.hpp>

namespace Parse {
namespace Test {

template<class Rule>
bool match_exactly(const std::string_view str) {
  tao::pegtl::memory_input<> input(str.begin(), str.end(), "match_exactly");

  bool success = tao::pegtl::parse<Rule, tao::pegtl::nothing, debug_control>(input);
  bool end_of_str = tao::pegtl::parse<tao::pegtl::eof>(input);

  return success and end_of_str;
}

template<class Rule, class Enum>
bool match_value_exactly(const std::string_view str, Enum value) {
  auto state = static_cast<Enum>(0);
  if(state == value) state = static_cast<Enum>(1);

  tao::pegtl::memory_input<> input(str.begin(), str.end(), "match_value_exactly");

  bool success = tao::pegtl::parse<Rule, ValueAction, debug_control>(input, state);
  bool end_of_str = tao::pegtl::parse<tao::pegtl::eof>(input);
  bool value_match = state == value;

  return success and end_of_str and value_match;
};

} // namespace
} // namespace

#endif //PARSE_TEST_MATCH_H_
