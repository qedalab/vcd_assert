#ifndef LIBPARSE_TEST_PARSE_HPP
#define LIBPARSE_TEST_PARSE_HPP

#include <string_view>

#include "../actions/control.hpp"
#include "../actions/make_pegtl_template.hpp"

#include <catch2/catch.hpp>
#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>


namespace Parse::Test {

template <class Rule, class Action, class... States>
void require_parse(std::string_view input_str, States &... states) {
  using tao::pegtl::memory_input;
  using tao::pegtl::parse;

  memory_input<> input(input_str.begin(), input_str.end(), "require_parse");
  REQUIRE(parse<Rule, make_pegtl_template<Action>::template type,
                Parse::capture_control>(input, states...));
}

} // namespace Parse::Test

#endif // LIBPARSE_TEST_PARSE_HPP
