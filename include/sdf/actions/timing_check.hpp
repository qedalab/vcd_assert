#ifndef LIBSDF_ACTIONS_TIMINGCHECK_HPP
#define LIBSDF_ACTIONS_TIMINGCHECK_HPP

#include <sdf/actions/base.hpp>
#include <sdf/actions/values.hpp>
#include <sdf/actions/timing.hpp>

#include <sdf/grammar/timing.hpp>

#include <sdf/types/timing_check.hpp>
#include <sdf/types/timing.hpp>


namespace SDF{
namespace Actions{

using namespace Parse;  

struct EqualityOperatorAction : multi_dispatch<
  Grammar::case_inequality, apply0<Apply::value<EqualityOperator::case_inv>>,
  Grammar::case_equality, apply0<Apply::value<EqualityOperator::case_equal>>,
  Grammar::logical_inequality, apply0<Apply::value<EqualityOperator::logic_inv>>,
  Grammar::logical_equality, apply0<Apply::value<EqualityOperator::logic_equal>>
>{
  using state = EqualityOperator;
};

struct NodeConstantEqualityAction : multi_dispatch<
  Grammar::scalar_node, inner_action<
    PortInstanceAction, Storage::member<&NodeConstantEquality::left>
  >,
  Grammar::equality_operator, inner_action<
    EqualityOperatorAction, Storage::member<&NodeConstantEquality::op>
  >,
  Grammar::scalar_constant, inner_action<
    NumberAction, Storage::member<&NodeConstantEquality::right>
  >
>{
  using state = NodeConstantEquality;
};

struct InvertedNodeStorage{
  static bool store(InvertedNode &in, Node n) {
    in = InvertedNode{n};
    return true;
  }
};

struct InvertedNodeAction : single_dispatch<
  Grammar::scalar_node, inner_action<
    PortInstanceAction,
    InvertedNodeStorage
  >
>{
  using state = InvertedNode;
};

struct TimingCheckConditionAction : multi_dispatch<
  Grammar::inversion_condition, inner_action<
    InvertedNodeAction, Storage::member<&TimingCheckCondition::value>
  >,
  Grammar::node_constant_equality_condition, inner_action<
    NodeConstantEqualityAction, Storage::member<&TimingCheckCondition::value>
  >,
  Grammar::scalar_node, inner_action<
    NodeAction, Storage::member<&TimingCheckCondition::value>
  >
>{
  using state = TimingCheckCondition;
};


// struct PortCheckPortStorage {
//   // static bool store(PortTimingCheck &ptc, EdgeType edge, Node port) {
//   static bool store(PortTimingCheck &ptc, Node inner) {
//     // ptc.edge = std::move(inner.edge);
//     ptc.port = std::move(inner);
//     return true;
//   }
// };

struct PortCheckAction : multi_dispatch<
  Grammar::qstring, inner_action<
    QStringAction, Storage::member<&PortTimingCheck::symbolic_name>
  >,
  Grammar::timing_check_condition, inner_action<
   TimingCheckConditionAction, 
   Storage::member<&PortTimingCheck::timing_check_condition>
  >,
  Grammar::port_spec, inner_action<
    PortSpecAction, Storage::member<&PortTimingCheck::port>
  >
>{
  using state = PortTimingCheck;
};

struct HoldPortTchkStorage  {
  static bool store(Hold &h, std::vector<PortTimingCheck> ps) {
    
    h.input = std::move(ps[0]);
    h.output = std::move(ps[1]);
      // throw std::runtime_error("InternalError");      
    return true;
  }
};

struct HoldPortTchkArrayAction : single_dispatch<
  Grammar::port_tchk, inner_action<
    PortCheckAction, Storage::push_back
  >
>{
  using state = std::vector<PortTimingCheck>;
};

struct HoldTimingCheckAction : multi_dispatch<
  Grammar::port_tchk, inner_action<
    HoldPortTchkArrayAction, HoldPortTchkStorage>,
  Grammar::value, inner_action<
    ValueAction, Storage::member<&Hold::value>>
>{
  using state = Hold;
};

// struct HoldTimingCheckStorage : 

struct TimingCheckAction : single_dispatch<
  // Grammar::setup_timing_check, inner_action<
  //   SetupTimingCheckAction, SetupTimingCheckStorage >,
  Grammar::hold_timing_check, inner_action<
    HoldTimingCheckAction, Storage::member<&TimingCheck::value> > // HoldTimingCheckStorage >
  // Grammar::setuphold_timing_check, inner_action<
  //   SetupholdTimingCheckAction, SetupholdTimingCheckStorage >,
  // Grammar::recovery_timing_check, inner_action<
  //   RecoveryTimingCheckAction, RecoveryTimingCheckStorage >,
  // Grammar::removal_timing_check, inner_action<
  //   RemovalTimingCheckAction, RemovalTimingCheckStorage >,
  // Grammar::recrem_timing_check, inner_action<
  //   RecremTimingCheckAction, RecremTimingCheckStorage >,
  // Grammar::skew_timing_check, inner_action<
  //   SkewTimingCheckAction, SkewTimingCheckStorage >,
  // Grammar::bidirectskew_timing_check, inner_action<
  //   BidirectskewTimingCheckAction, BidirectskewTimingCheckStorage >,
  // Grammar::width_timing_check, inner_action<
  //   WidthTimingCheckAction, WidthTimingCheckStorage >,
  // Grammar::period_timing_check, inner_action<
  //   PeriodTimingCheckAction, PeriodTimingCheckStorage >,
  // Grammar::nochange_timing_check, inner_action<
  //   NochangeTimingCheckAction, NochangeTimingCheckStorage >
> {
  using state = TimingCheck;
};

struct TimingCheckArrayAction : single_dispatch<
  Grammar::tchk_def, inner_action<
    TimingCheckAction,
    Storage::push_back
  >
> {
  using state = std::vector<TimingCheck>;
};

}

}

#endif // LIBSDF_ACTIONS_TIMINGSPEC_HPP