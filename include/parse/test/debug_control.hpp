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

#ifndef PARSE_TEST_DEBUG_CONTROL_H
#define PARSE_TEST_DEBUG_CONTROL_H

#include "../concepts/error_rule.hpp"
#include "./debug_exception.hpp"

#include <tao/pegtl/normal.hpp>

namespace Parse::Test {

template<class Rule>
struct debug_control : public tao::pegtl::normal<Rule> {
  using apply_mode = tao::pegtl::apply_mode;
  using rewind_mode = tao::pegtl::rewind_mode;

  using normal_rule = tao::pegtl::normal<Rule>;

  template <typename Input, typename... States>
  static void raise(const Input & /*unused*/, States &&... /*unused*/) {
    // throw ParseException(Rule::error(), in.position()));
    if constexpr (Concepts::ErrorRule<Rule>) {
      throw DebugException(Rule::error());
    } else {
      auto demangled = std::string(tao::pegtl::internal::demangle<Rule>());
      throw DebugException("Failed parsing Rule without error: " + demangled);
    }
  }

  template <apply_mode A, rewind_mode M, template <typename...> class Action,
      template <typename...> class Control, typename Input,
      typename... States>
  static bool match(Input &in, States &&... states) {
    auto position = in.position();

    DebugState trace {
      tao::pegtl::internal::demangle<Rule>(),
      position.line,
      position.byte_in_line,
    };

    try {
      return normal_rule::template match<A, M, Action, debug_control>(in, states...);
    } catch (DebugException& de){
      de.add_trace(std::move(trace));
      throw;
    }
  }

};

} // namespace Parse::Test

#endif //PARSE_DEBUG_H
