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
