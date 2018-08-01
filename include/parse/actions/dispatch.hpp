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

#ifndef LIBPARSE_ACTIONS_DISPATCH_HPP
#define LIBPARSE_ACTIONS_DISPATCH_HPP

#include "parse/util/tag.hpp"

namespace Parse {

template<class Rule, class Command>
struct single_dispatch {
  static Command dispatch(Util::Tag<Rule>);
};

template<class Rule, class Command, class... Rest>
struct multi_dispatch : single_dispatch<Rule, Command>, multi_dispatch<Rest...> {
  using multi_dispatch<Rest...>::dispatch;
  using single_dispatch<Rule, Command>::dispatch;
};

template<class Rule, class Command>
struct multi_dispatch<Rule, Command> : single_dispatch<Rule, Command> {
  using single_dispatch<Rule, Command>::dispatch;
};

template<class Command>
struct all_dispatch {
  template<class Rule>
  static Command dispatch(Util::Tag<Rule>);
};

} // namespace Parse

#endif // LIBPARSE_ACTIONS_DISPATCH_HPP
