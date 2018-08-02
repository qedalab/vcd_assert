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

#ifndef LIBPARSE_ACTIONS_COMMAND_APPLY_HPP
#define LIBPARSE_ACTIONS_COMMAND_APPLY_HPP

#include <tao/pegtl/apply_mode.hpp>
#include <tao/pegtl/internal/action_input.hpp>
#include <tao/pegtl/internal/duseltronik.hpp>
#include <tao/pegtl/rewind_mode.hpp>

// TODO don't rely on pegtl::internal

namespace Parse {

template <typename Apply>
struct apply {
  using rewind_mode = tao::pegtl::rewind_mode;
  using apply_mode = tao::pegtl::apply_mode;

  template <typename Rule, rewind_mode M, template <typename...> class Action,
            template <typename...> class Control, class Input,
            typename... States>
  static bool command(Input &input, States &... states) {
    using duseltronik =
        tao::pegtl::internal::duseltronik<Rule, apply_mode::NOTHING, M, Action,
                                          Control>;
    auto start = input.iterator();

    if (duseltronik::match(input, states...)) {
      tao::pegtl::internal::action_input ai(start, input);
      return Apply::template apply<Rule>(ai, states...);
    }

    return false;
  }
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_COMMAND_APPLY_HPP
