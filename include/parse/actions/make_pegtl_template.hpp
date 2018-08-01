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

#ifndef LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP
#define LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP

namespace Parse {

template <typename Type>
struct make_pegtl_template {
  template <typename Rule>
  using type = Type;
};

template <class Apply0>
struct make_pegtl_apply0 {
  template <typename Rule>
  struct type {

    template<typename State>
    static bool apply0(State &state) {
      return Apply0::template apply0<Rule>(state);
    }
  };
};

template <class Apply>
struct make_pegtl_apply {
  template <typename Rule>
  struct type {

    template<typename Input, typename State>
    static bool apply(const Input& input, State &state) {
      return Apply::template apply0<Rule>(input, state);
    }
  };
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_MAKE_PEGTL_TEMPLATE_HPP
