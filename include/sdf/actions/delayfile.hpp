#ifndef LIBSDF_ACTIONS_DELAYFILE_HPP
#define LIBSDF_ACTIONS_DELAYFILE_HPP


#include <sdf/action/base.hpp>
#include <sdf/action/cell.hpp>
#include <sdf/action/time_scale.hpp>

#include <sdf/grammar/cell.hpp>
#include <sdf/grammar/delayfile.hpp>
#include <sdf/grammar/header.hpp>

#include <sdf/types/delayfile.hpp>
#include <sdf/types/header.hpp>

namespace SDF {

// clang-format off
struct DelayFileAction : multi_dispatch<
  Grammar::sdf_version, inner_action<
      QStringAction, 
      Storage::member<&Delayfile::version>
  >
  Grammar::design_name, inner_action<
      QStringAction, 
      Storage::member<&Delayfile::design_name>
  >,
  Grammar::date, inner_action<
      QStringAction, 
      Storage::member<&Delayfile::date>
  >,
  Grammar::vendor, inner_action<
      QStringAction, 
      Storage::member<&Delayfile::vendor>
  >,
  Grammar::program_name, inner_action<
      QStringAction, 
      Storage::member<&Delayfile::program_name>
  >,
  Grammar::program_version, inner_action<
      QStringAction, 
      Storage::member<&Delayfile::program_version>
  >,
  Grammar::hierarchy_divider, inner_action<
      CharAction, 
      Storage::member<&Delayfile::hierarchy_divider>
  >,
  Grammar::voltage, inner_action<
      TripleAction, 
      Storage::member<&Delayfile::voltage>
  >,
  Grammar::process, inner_action<
      QStringAction, 
      Storage::member<&Delayfile::process>
  >,
  Grammar::temperature, inner_action<
      TripleAction, 
      Storage::member<&Delayfile::temperature>
  >,
  Grammar::time_scale, inner_action<
      TimeScaleAction, 
      Storage::member<&Delayfile::time_scale>
  >,
  Grammar::cell, inner_action<
      CellAction, 
      Storage::push_back<&Delayfile::cells>
  >
> {
  using state = DelayFile;
};
// clang-format on

}
#endif LIBSDF_ACTIONS_DELAYFILE_HPP
