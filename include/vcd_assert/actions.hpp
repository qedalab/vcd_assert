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

#ifndef VCD_ASSERT_ACTIONS_HPP
#define VCD_ASSERT_ACTIONS_HPP

#include "vcd/grammar/grammar.hpp"
#include "vcd/actions/simulation_time.hpp"
#include "vcd/actions/value_change.hpp"

#include "./timing_checker.hpp"

#include "parse/actions/dispatch.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/storage/function.hpp"

namespace VCDAssert {

struct PlaceHolderAction {};

// clang-format off
struct TimingCheckerAction : Parse::multi_dispatch<
  VCD::Grammar::simulation_time, Parse::inner_action< VCD::SimulationTimeAction,
    Parse::Storage::function<&TimingChecker::simulation_time>>,
  VCD::Grammar::vector_value_change, Parse::inner_action<VCD::Actions::UncheckedVectorValueChangeAction,
    Parse::Storage::function<&TimingChecker::vector_value_change>>,
  VCD::Grammar::scalar_value_change, Parse::inner_action<VCD::Actions::ScalarValueChangeAction,
    Parse::Storage::function<&TimingChecker::scalar_value_change>>,
  VCD::Grammar::real_value_change, Parse::inner_action<VCD::Actions::RealValueChangeAction,
    Parse::Storage::function<&TimingChecker::real_value_change>>
> {
  using state = TimingChecker;
};
// clang-format on

} // namespace VCDAssert

#endif // VCD_ASSERT_ACTIONS_HPP
