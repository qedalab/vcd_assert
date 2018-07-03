// #ifndef LIBSDF_ACTIONS_DELAYFILE_HPP
// #define LIBSDF_ACTIONS_DELAYFILE_HPP

// #include <sdf/actions/base.hpp>

// #include <sdf/actions/cell.hpp>
// #include <sdf/actions/time_scale.hpp>
// #include <sdf/actions/values.hpp>

// #include <sdf/grammar/cell.hpp>
// #include <sdf/grammar/delayfile.hpp>
// #include <sdf/grammar/header.hpp>

// #include <sdf/types/base.hpp>
// #include <sdf/types/delayfile.hpp>


// namespace SDF {
// namespace Actions {

// using namespace Parse;  


// // clang-format off
// struct DelayFileAction : multi_dispatch<
//   Grammar::sdf_version, inner_action<
//       QStringAction, 
//       Storage::member<&DelayFile::sdf_version>
//   >
//   Grammar::design_name, inner_action<
//       QStringAction, 
//       Storage::member<&DelayFile::design_name>
//   >,
//   Grammar::date, inner_action<
//       QStringAction, 
//       Storage::member<&DelayFile::date>
//   >,
//   Grammar::vendor, inner_action<
//       QStringAction, 
//       Storage::member<&DelayFile::vendor>
//   >,
//   Grammar::program_name, inner_action<
//       QStringAction, 
//       Storage::member<&DelayFile::program_name>
//   >,
//   Grammar::program_version, inner_action<
//       QStringAction, 
//       Storage::member<&DelayFile::program_version>
//   >,
//   Grammar::hierarchy_divider, inner_action<
//       HCharAction, 
//       Storage::member<&DelayFile::hierarchy_divider>
//   >,
//   Grammar::voltage, inner_action<
//       TripleAction, 
//       Storage::member<&DelayFile::voltage>
//   >,
//   Grammar::process, inner_action<
//       QStringAction, 
//       Storage::member<&DelayFile::process>
//   >,
//   Grammar::temperature, inner_action<
//       TripleAction, 
//       Storage::member<&DelayFile::temperature>
//   >,
//   Grammar::timescale, inner_action<
//       TimeScaleAction, 
//       Storage::member<&DelayFile::timescale>
//   >,
//   Grammar::cell, inner_action<
//       CellArrayAction, 
//       Storage::member<&DelayFile::cells>
//   >
// > {
//   using state = DelayFile;
// };
// // clang-format on

// }
// }
// #endif // LIBSDF_ACTIONS_DELAYFILE_HPP
