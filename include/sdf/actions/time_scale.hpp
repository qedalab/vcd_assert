#ifndef LIBSDF_EVENT_TIME_SCALE_HPP
#define LIBSDF_EVENT_TIME_SCALE_HPP

#include <sdf/types/enums.hpp>
#include <sdf/grammar/enums/time.hpp>

namespace SDF {


struct TimeScale {
  TimescaleNumber number;
  TimescaleUnit unit;
};

struct TimescaleNumberAction : single_dispatch<
    Grammar::number, apply0<Apply::value<TimescaleNumber>>
> {
  using state = TimescaleNumber;
};

struct TimescaleUnitAction : single_dispatch<
    Grammar::number, apply0<Apply::value<TimescaleUnit>>
> {
  using state = TimescaleUnit;
};

struct TimeScaleAction : multi_dispatch<
  Grammar::timescale_number, inner_action<
      TimescaleNumberAction, 
      Storage::member<&TimeScale::number>
  >,
  Grammar::timescale_unit, inner_action<
      TimescaleUnitAction, 
      Storage::member<&TimeScale::unit>
  >
> {
  using state = TimeScale;
};

} // namespace SDF

#endif // SDF_EVENT_TIME_SCALE_HPP
