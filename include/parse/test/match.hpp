// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

#ifndef LIBPARSE_TEST_MATCH_HPP
#define LIBPARSE_TEST_MATCH_HPP

#include "../actions/apply/rule_value.hpp"
#include "../actions/make_pegtl_template.hpp"
#include "./debug_control.hpp"

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
}

} // namespace Parse::Test

#endif // LIBPARSE_TEST_MATCH_HPP
