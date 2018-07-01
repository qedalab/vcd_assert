#ifndef LIBSDF_ACTIONS_TIMESCALE_HPP_
#define LIBSDF_ACTIONS_TIMESCALE_HPP_

#include <sdf/actions/base.hpp>

#include <sdf/grammar/header.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/enums.hpp>

namespace SDF{
namespace Actions{

using namespace Parse;  
using namespace SDF::Types;  

struct TimeScaleNumberApply {
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, TimeScaleNumber &tn) {
    switch (input.size()) {
    case 1:
      tn = TimeScaleNumber::_1;
      break;
    case 2:
      tn = TimeScaleNumber::_10;
      break;
    case 3:
      tn = TimeScaleNumber::_100;
      break;
    default:
      throw std::runtime_error("InternalError");
    }

    return true;
  }
};

struct TimeScaleNumberAction : single_dispatch<
  Grammar::timescale_number, apply<TimeScaleNumberApply>
> {
  using state = TimeScaleNumber;
};

struct TimeScaleUnitAction : multi_dispatch<
  Grammar::timescale_unit_s,  apply0<Apply::value<TimeScaleUnit::s>>,
  Grammar::timescale_unit_ms, apply0<Apply::value<TimeScaleUnit::ms>>,
  Grammar::timescale_unit_us, apply0<Apply::value<TimeScaleUnit::us>>,
  Grammar::timescale_unit_ns, apply0<Apply::value<TimeScaleUnit::ns>>,
  Grammar::timescale_unit_ps, apply0<Apply::value<TimeScaleUnit::ps>>,
  Grammar::timescale_unit_fs, apply0<Apply::value<TimeScaleUnit::fs>>
> {
  using state = TimeScaleUnit;
};

struct TimeScaleAction : multi_dispatch<
  Grammar::timescale_number, inner_action<
      TimeScaleNumberAction, 
      Storage::member<&TimeScale::number>
  >,
  Grammar::timescale_unit, inner_action<
      TimeScaleUnitAction, 
      Storage::member<&TimeScale::unit>
  >
> {
  using state = TimeScale;
};

}
} 

#endif // SDF_ACTIONS_TIME_SCALE_HPP_
