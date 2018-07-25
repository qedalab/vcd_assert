#include <parse/actions/apply/rule_value.hpp>
#include <parse/actions/make_pegtl_template.hpp>
#include <parse/test/debug_control.hpp>

#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>
#include <tao/pegtl/rules.hpp>


template <class Rule>
bool match_exactly(const std::string_view str) {
  tao::pegtl::memory_input<> input(str.begin(), str.end(), "match_exactly");

  bool success =
      tao::pegtl::parse_tree<Rule, tao::pegtl::nothing, debug_control>(input);
      // tao::pegtl::parse<Rule, tao::pegtl::nothing, debug_control>(input);
  bool end_of_str = tao::pegtl::parse<tao::pegtl::eof>(input);

  return success and end_of_str;
}