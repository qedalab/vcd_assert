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

#ifndef LIBVCD_ACTIONS_VALUE_CHANGE_HPP
#define LIBVCD_ACTIONS_VALUE_CHANGE_HPP

#include "../grammar/value.hpp"
#include "../types/value_change.hpp"
#include "./identifier_code.hpp"

#include "parse/actions/apply/float.hpp"
#include "parse/actions/apply/marker.hpp"
#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/apply/string_view.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/marker.hpp"
#include "parse/actions/storage/member.hpp"
#include "parse/util/marker.hpp"

namespace VCD::Actions {

// clang-format off
struct RealAction : Parse::single_dispatch <
  Grammar::real_number, Parse::apply<Parse::Apply::float_value>
> {
  using state = double;
};

struct ValueAction : Parse::all_dispatch<Parse::apply0<Apply::rule_value>> {
  using state = Value;
};

struct UncheckedVectorValueAction : Parse::all_dispatch<Parse::apply<Apply::string_view>> {
  using state = std::string_view;
};

struct RealValueChangeAction : Parse::multi_dispatch<
  Parse::Grammar::marker, Parse::inner_action<Parse::MarkerAction,
    Parse::Storage::member<&RealValueChangeView::marker>>,
  Grammar::identifier_code, Parse::inner_action<IdentifierCodeAction,
    Parse::Storage::member<&RealValueChangeView::identifier_code>>,
  Grammar::real_number, Parse::inner_action<RealAction,
    Parse::Storage::member<&RealValueChangeView::value>>
> {
  using state = RealValueChangeView;
};

struct ScalarValueChangeAction : Parse::multi_dispatch<
  Parse::Grammar::marker, Parse::inner_action<Parse::MarkerAction,
    Parse::Storage::member<&ScalarValueChangeView::marker>>,
  Grammar::identifier_code, Parse::inner_action<IdentifierCodeAction,
    Parse::Storage::member<&ScalarValueChangeView::identifier_code>>,
  Grammar::value, Parse::inner_action<ValueAction,
    Parse::Storage::member<&ScalarValueChangeView::value>>
> {
  using state = ScalarValueChangeView;
};

struct UncheckedVectorValueChangeAction : Parse::multi_dispatch<
  Parse::Grammar::marker, Parse::inner_action<Parse::MarkerAction,
    Parse::Storage::member<&UncheckedVectorValueChangeView::marker>>,
  Grammar::identifier_code, Parse::inner_action<IdentifierCodeAction,
    Parse::Storage::member<&UncheckedVectorValueChangeView::identifier_code>>,
  Grammar::binary_value, Parse::inner_action<UncheckedVectorValueAction,
    Parse::Storage::member<&UncheckedVectorValueChangeView::values>>
> {
  using state = UncheckedVectorValueChangeView;
};
// clang-fomrmat on

} // namespace VCD

#endif // LIBVCD_ACTIONS_VALUE_CHANGE_HPP
