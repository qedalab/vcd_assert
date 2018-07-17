#ifndef LIBSDF_ACTIONS_DELAYFILE_HPP
#define LIBSDF_ACTIONS_DELAYFILE_HPP

#include <sdf/actions/base.hpp>

#include <sdf/actions/cell.hpp>
#include <sdf/actions/time_scale.hpp>
#include <sdf/actions/values.hpp>

#include <sdf/grammar/cell.hpp>
#include <sdf/grammar/delayfile.hpp>
#include <sdf/grammar/header.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/delayfile.hpp>
#include <sdf/types/delayfile_reader.hpp>


namespace SDF {
namespace Actions {

using namespace Parse;  

using TimeScaleFunctionType = void (DelayFileReader::*)(TimeScaleView);

// clang-format off
struct DelayFileAction : multi_dispatch<
  Grammar::sdf_version, inner_action<
      QStringAction, 
      Storage::function<&DelayFileReader::sdf_version>
  >,
  Grammar::design_name, inner_action<
      QStringAction, 
      Storage::function<&DelayFileReader::design_name>
  >,
  Grammar::date, inner_action<
      QStringAction, 
      Storage::function<&DelayFileReader::date>
  >,
  Grammar::vendor, inner_action<
      QStringAction, 
      Storage::function<&DelayFileReader::vendor>
  >,
  Grammar::program_name, inner_action<
      QStringAction, 
      Storage::function<&DelayFileReader::program_name>
  >,
  Grammar::program_version, inner_action<
      QStringAction, 
      Storage::function<&DelayFileReader::program_version>
  >,
  Grammar::hierarchy_divider, inner_action<
      HCharAction, 
      Storage::function<&DelayFileReader::hierarchy_divider>
  >,
  Grammar::voltage, inner_action<
      TripleAction<Grammar::signed_real_number>, 
      Storage::function<&DelayFileReader::voltage>
  >,
  Grammar::process, inner_action<
      QStringAction, 
      Storage::function<&DelayFileReader::process>
  >,
  Grammar::temperature, inner_action<
      TripleAction<Grammar::signed_real_number>, 
      Storage::function<&DelayFileReader::temperature>
  >,
  Grammar::timescale, inner_action<
      TimeScaleAction, 
      Storage::function<
        static_cast<TimeScaleFunctionType>(&DelayFileReader::timescaleview)
      >
  >,
  Grammar::cell, inner_action<
      CellArrayAction, 
      Storage::function<&DelayFileReader::cells>
  >
> {
  using state = DelayFileReader;
};
// clang-format on

}
}
#endif // LIBSDF_ACTIONS_DELAYFILE_HPP
