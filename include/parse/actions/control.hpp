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

#ifndef LIBPARSE_ACTIONS_CONTROL_HPP
#define LIBPARSE_ACTIONS_CONTROL_HPP

#include "../concepts/dispatch.hpp"
#include "../concepts/error_rule.hpp"

#include <tao/pegtl/normal.hpp>

#include <type_traits>

namespace Parse {

template <class Rule>
struct capture_control : public tao::pegtl::normal<Rule> {
  using apply_mode = tao::pegtl::apply_mode;
  using rewind_mode = tao::pegtl::rewind_mode;

  template <typename Input, typename... States>
  static void raise(const Input & /*unused*/, const States &... /*unused*/) {
    // throw ParseException(Rule::error(), in.position()));
    if constexpr (Concepts::ErrorRule<Rule>) {
      throw std::runtime_error(Rule::error());
    } else {
      throw std::runtime_error("Failed parsing Rule without error: " +
                               tao::pegtl::internal::demangle<Rule>());
    }
  }

  template <apply_mode A, rewind_mode M, template <typename...> class Action,
            template <typename...> class Control, typename Input,
            typename... States>
  static bool match(Input &in, States &... states) {
    if constexpr (Concepts::DispatchRule<Action<Rule>, Rule>) {
      using Command = decltype(Action<Rule>::dispatch(Util::Tag<Rule>{}));
      return Command::template command<Rule, M, Action, Control>(in, states...);
    } else {
      // Just a normal matcher
      // TODO handle the case of getting a PEGTL action properly
      // TODO reverse inputs so that it is sensible for matchers
      return tao::pegtl::internal::duseltronik<Rule, A, M, Action,
                                               Control>::match(in, states...);
    }
  }
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_CONTORL_HPP
