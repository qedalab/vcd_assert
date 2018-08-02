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

#ifndef LIBVCD_TYPES_EVENT_SCOPE_HPP
#define LIBVCD_TYPES_EVENT_SCOPE_HPP

#include "../grammar/commands.hpp"
#include "../grammar/enums/scope_type.hpp"
#include "../types/enums.hpp"
#include "../types/scope.hpp"

#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/apply/string_view.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/command/pegtl_action.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/storage/member.hpp"

#include <string_view>

namespace VCD::Actions {

using namespace Parse;

struct UpscopeApply {
  template<class Rule, class Parent>
  static bool apply0(Parent& parent) {
    parent.upscope();
    return true;
  }
};

struct ScopeTypeAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = ScopeType;
};

struct ScopeIdentifierAction : Parse::single_dispatch<
    Grammar::scope_identifier, Parse::apply<Parse::Apply::string_view>
> {
  using state = std::string_view;
};

struct ScopeAction
    : Parse::multi_dispatch<
          Grammar::scope_type,
          Parse::inner_action<ScopeTypeAction,
                              Parse::Storage::member<&ScopeDataView::type>>,
          Grammar::scope_identifier,
          Parse::inner_action<ScopeIdentifierAction,
                              Parse::Storage::member<&ScopeDataView::identifier>>
> {
  using state = ScopeDataView;
};

} // namespace VCD::Actions

#endif //PARSE_SCOPE_HPP
