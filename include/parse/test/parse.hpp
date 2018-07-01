#ifndef PARSE_TEST_PARSE_HPP
#define PARSE_TEST_PARSE_HPP

#include <string_view>
#include "../control/scoped.h"

#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>
#include <catch2/catch.hpp>
#include "parse/actions/control.hpp"
#include "parse/actions/make_pegtl_template.hpp"

namespace Parse::Test {

using namespace Parse;
 

template<class Rule, class Action, class... States>
void require_parse(std::string_view input_str, States&... states)
{
  using tao::pegtl::memory_input;
  using tao::pegtl::parse;

  memory_input<> input(input_str.begin(), input_str.end(), "require_parse");
  REQUIRE(parse<Rule, make_pegtl_template<Action>::template type, Parse::capture_control>(input, states...));
};

} // namespace Test

#endif // PARSE_TEST_PARSE_HPP
