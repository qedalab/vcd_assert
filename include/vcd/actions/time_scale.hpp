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

#ifndef VCD_EVENT_TIME_SCALE_HPP
#define VCD_EVENT_TIME_SCALE_HPP

#include "../types/enums.hpp"
#include "../types/time_scale.hpp"

#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/apply/value.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/command/pegtl_action.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/storage/member.hpp"

#include <tao/pegtl/nothing.hpp>
#include <vcd/grammar/enums/time.hpp>

namespace VCD::Actions {

using namespace Parse;

struct TimeUnitAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = TimeUnit;
};

struct TimeNumberApply {
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, TimeNumber &tn)
  {
    switch (input.size()) {
    case 1:
      tn = TimeNumber::_1;
      break;
    case 2:
      tn = TimeNumber::_10;
      break;
    case 3:
      tn = TimeNumber::_100;
      break;
    default:                                                  // LCOV_EXCL_LINE
      std::puts("INTERNAL ERROR: Invalid grammar succeeded"); // LCOV_EXCL_LINE
      std::abort();                                           // LCOV_EXCL_LINE
    }

    return true;
  }
};

// clang-format off
struct TimeNumberAction : single_dispatch<
  Grammar::time_number, apply<TimeNumberApply>
> {
  using state = TimeNumber;
};
// clang-format on

// clang-format off
struct TimeScaleAction : multi_dispatch <
    Grammar::time_number, inner_action<
      TimeNumberAction, Storage::member<&TimeScaleView::number>>,
    Grammar::time_unit, inner_action<
      TimeUnitAction, Storage::member<&TimeScaleView::unit>>
> {
  using state = TimeScaleView;
};
// clang-format on

} // namespace VCD::Actions

#endif // VCD_EVENT_TIME_SCALE_HPP
