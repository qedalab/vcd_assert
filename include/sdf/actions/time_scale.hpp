#ifndef LIBSDF_ACTIONS_TIMESCALE_HPP
#define LIBSDF_ACTIONS_TIMESCALE_HPP

#include <sdf/grammar/time_scale.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/time_scale.hpp>

#include <parse/actions/dispatch.hpp>
#include <parse/actions/command/inner_action.hpp>
#include <parse/actions/command/apply0.hpp>
#include <parse/actions/storage/member.hpp>
#include <parse/actions/apply/value.hpp>
#include <parse/actions/apply/rule_value.hpp>

namespace SDF::Actions {

using namespace Parse;

// =======================================================
// Commenting this back in causes compilation failure WTF!
// =======================================================
struct TimeScaleNumberAction : all_dispatch<apply0<Apply::rule_value>>
{
  using state = TimeScaleNumber;
};

struct TimeScaleUnitAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = TimeScaleUnit;
};

struct TimeScaleAction : multi_dispatch<
   Grammar::timescale_number, inner_action<
       TimeScaleNumberAction, 
       Storage::member<&TimeScaleView::number>
   >
   ,
  Grammar::timescale_unit, inner_action<
      TimeScaleUnitAction, 
      Storage::member<&TimeScaleView::unit>
  >
> {
  using state = TimeScaleView;
};

} // namespace SDF::Actions

#endif // SDF_ACTIONS_TIME_SCALE_HPP
