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

struct TimeUnitAction : all_dispatch<apply0<Apply::rule_value>>
{
  using state = TimeUnit;
};

// struct TimeUnitAction : multi_dispatch<
//   Grammar::time_s, apply0<Apply::value<TimeUnit::s>>,
//   Grammar::time_ms, apply0<Apply::value<TimeUnit::ms>>,
//   Grammar::time_us, apply0<Apply::value<TimeUnit::us>>,
//   Grammar::time_ns, apply0<Apply::value<TimeUnit::ns>>,
//   Grammar::time_ps, apply0<Apply::value<TimeUnit::ps>>,
//   Grammar::time_fs, apply0<Apply::value<TimeUnit::fs>>
// > {
//   using state = TimeUnit;
// };

struct TimeNumberApply {
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, TimeNumber &tn) {
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
    default:
      throw std::runtime_error("InternalError");
    }

    return true;
  }
};

struct TimeNumberAction : single_dispatch <
    Grammar::time_number, apply<TimeNumberApply>
> {
  using state = TimeNumber;
};

struct TimeScaleAction : multi_dispatch <
    Grammar::time_number, inner_action<TimeNumberAction, Storage::member<&TimeScaleView::number>>,
    Grammar::time_unit, inner_action<TimeUnitAction, Storage::member<&TimeScaleView::unit>>
> {
  using state = TimeScaleView;
};

} // namespace VCD::Actions

#endif // VCD_EVENT_TIME_SCALE_HPP
