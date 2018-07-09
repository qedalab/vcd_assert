// #ifndef LIBSDF_ACTIONS_TIMINGCHECK_HPP
// #define LIBSDF_ACTIONS_TIMINGCHECK_HPP

// #include <sdf/actions/base.hpp>
// #include <sdf/actions/values.hpp>
// #include <sdf/actions/timing.hpp>
// #include <sdf/actions/util.hpp>

// #include <sdf/grammar/timing.hpp>
// // #include <sdf/grammar/cell.hpp>

// #include <sdf/types/timing_check.hpp>
// #include <sdf/types/cell.hpp>


// namespace SDF{
// namespace Actions{

// using namespace Parse;  

// struct TimingCheckCondAction : multi_dispatch<
//   Grammar::scalar_node inner_action<
//     PortCheckAction, Storage::push_back
//   >,
//   Grammar::inversion_operator inner_action<
//     PortCheckAction, Storage::push_back
//   >,
//   Grammar::equality_operator inner_action<
//     PortCheckAction, Storage::push_back
//   >
// >{
//   using state = std::array<Port, 2>;
// };
// struct PortSpecAction : single_dispatch<
//   Grammar::port_tchk inner_action<
//     PortCheckAction, Storage::push_back
//   >
// >{
//   using state = std::array<Port, 2>;
// };

// struct PortCheckAction : single_dispatch<
//   Grammar::port_tchk inner_action<
//     PortCheckAction, Storage::push_back
//   >
// >{
//   using state = std::array<Port, 2>;
// };


// struct HoldPortStorage  {
//   static bool store(std::tuple<Port, Port> &tup, std::array<Port, 2> arr) {
//     tup = as_tuple<Port, Port>(arr); //maybe no move 
//     return true;
//   }
// };

// struct HoldPortTupleAction : single_dispatch<
//   Grammar::port_tchk inner_action<
//     PortCheckAction, Storage::push_back
//   >
// >{
//   using state = std::array<Port, 2>;
// };

// struct HoldPortAction : single_dispatch<
//   Grammar::port_tchk inner_action<
//     HoldPortTupleAction, HoldPortStorage
//   >
// >{
//   using state = std::tuple<Port, Port>;
// };

// struct HoldTimingCheckAction : multi_dispatch<
//   Grammar::port_tchk, inner_action<
//     HoldPortAction, Storage::member<&Hold::value>>,
//   Grammar::value, inner_action<
//     ValueAction, Storage::member<&Hold::value>>
// >{
//   using state = Hold;
// };


// struct TimingCheckAction : single_dispatch<
//   // Grammar::setup_timing_check, inner_action<
//   //   SetupTimingCheckAction, SetupTimingCheckStorage >,
//   Grammar::hold_timing_check, inner_action<
//     HoldTimingCheckAction, HoldTimingCheckStorage >
//   // Grammar::setuphold_timing_check, inner_action<
//   //   SetupholdTimingCheckAction, SetupholdTimingCheckStorage >,
//   // Grammar::recovery_timing_check, inner_action<
//   //   RecoveryTimingCheckAction, RecoveryTimingCheckStorage >,
//   // Grammar::removal_timing_check, inner_action<
//   //   RemovalTimingCheckAction, RemovalTimingCheckStorage >,
//   // Grammar::recrem_timing_check, inner_action<
//   //   RecremTimingCheckAction, RecremTimingCheckStorage >,
//   // Grammar::skew_timing_check, inner_action<
//   //   SkewTimingCheckAction, SkewTimingCheckStorage >,
//   // Grammar::bidirectskew_timing_check, inner_action<
//   //   BidirectskewTimingCheckAction, BidirectskewTimingCheckStorage >,
//   // Grammar::width_timing_check, inner_action<
//   //   WidthTimingCheckAction, WidthTimingCheckStorage >,
//   // Grammar::period_timing_check, inner_action<
//   //   PeriodTimingCheckAction, PeriodTimingCheckStorage >,
//   // Grammar::nochange_timing_check, inner_action<
//   //   NochangeTimingCheckAction, NochangeTimingCheckStorage >
// > {
//   using state = std::vector<TimingCheck>;
// };

// struct TimingCheckArrayAction : single_dispatch<
//   Grammar::tchk_def, inner_action<
//     TimingCheckAction,
//     Storage::push_back
//   >
// > {
//   using state = std::vector<TimingCheck>;
// };

// }

// }

// #endif // LIBSDF_ACTIONS_TIMINGSPEC_HPP