#ifndef LIBVCD_ACTIONS_SIMULATION_TIME_HPP
#define LIBVCD_ACTIONS_SIMULATION_TIME_HPP

#include "../grammar/grammar.hpp"
#include "../types/simulation_time.hpp"

#include "parse/actions/apply/unsigned_integer.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/storage/member.hpp"

namespace VCD {

struct SimulationTimeAction : Parse::single_dispatch<
  Grammar::decimal_number, Parse::apply<Parse::Apply::unsigned_integer>
> {
  using state = SimulationTime;
};

} // namespace

#endif // LIBVCD_ACTIONS_SIMULATION_TIME_HPP
