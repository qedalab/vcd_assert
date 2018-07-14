#ifndef LIBSDF_ACTIONS_TIMESCALE_HPP
#define LIBSDF_ACTIONS_TIMESCALE_HPP

#include <sdf/actions/base.hpp>

#include <sdf/grammar/header.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/time_scale.hpp>


namespace SDF{
namespace Actions{

using namespace Parse;  

struct TimeScaleNumberAction : multi_dispatch<
  Grammar::timescale_number_1, apply0<Apply::value<TimeScaleNumber::_1>>,
  Grammar::timescale_number_10, apply0<Apply::value<TimeScaleNumber::_10>>,
  Grammar::timescale_number_100, apply0<Apply::value<TimeScaleNumber::_100>>
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
      Storage::member<&TimeScaleView::number>
  >,
  Grammar::timescale_unit, inner_action<
      TimeScaleUnitAction, 
      Storage::member<&TimeScaleView::unit>
  >
> {
  using state = TimeScaleView;
};

}
} 

#endif // SDF_ACTIONS_TIME_SCALE_HPP
