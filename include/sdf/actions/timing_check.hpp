#ifndef LIBSDF_ACTIONS_TIMINGCHECK_HPP
#define LIBSDF_ACTIONS_TIMINGCHECK_HPP

#include <sdf/actions/base.hpp>
#include <sdf/actions/constants.hpp>
#include <sdf/actions/values.hpp>
#include <sdf/actions/timing.hpp>

#include <sdf/grammar/timing.hpp>

#include <sdf/types/timing_check.hpp>
#include <sdf/types/timing.hpp>

#include <fmt/format.h>

using namespace fmt::literals;

namespace SDF{
namespace Actions{

using namespace Parse;  

struct EqualityOperatorAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = EqualityOperator;
};

struct NodeConstantEqualityAction : multi_dispatch<
  Grammar::scalar_node, inner_action<
    ScalarNodeAction, Storage::member<&NodeConstantEquality::left>
  >,
  Grammar::equality_operator, inner_action<
    EqualityOperatorAction, Storage::member<&NodeConstantEquality::op>
  >,
  Grammar::scalar_constant, inner_action<
    BinaryAction, Storage::member<&NodeConstantEquality::right>
  >
>{
  using state = NodeConstantEquality;
};

struct InvertedNodeStorage{
  static bool store(InvertedNode &in, Node n) {
    in.type = std::move(n.type);
    in.basename_identifier = std::move(n.basename_identifier);
    
    if(n.edge.has_value()){
      in.edge = std::move(n.edge);
    }
    if(n.hierarchical_identifier.has_value()){
      in.hierarchical_identifier = std::move(n.hierarchical_identifier);
    }
    if(n.start.has_value()){
      in.start = std::move(n.start);
    }
    if(n.end.has_value()){
      in.end = std::move(n.end);
    }
    return true;
  }
};

struct InvertedNodeAction : single_dispatch<
  Grammar::scalar_node, inner_action<
    ScalarNodeAction, InvertedNodeStorage
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
    ScalarNodeAction, Storage::member<&TimingCheckCondition::value>
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

struct HoldTimingCheckAction : multi_dispatch<
  Grammar::port_tchk_0, inner_action<
    PortCheckAction, Storage::member<&Hold::input>>,
  Grammar::port_tchk_1, inner_action<
    PortCheckAction, Storage::member<&Hold::output>>,
  Grammar::value, inner_action<
    ValueAction, Storage::member<&Hold::value>>
>{
  using state = Hold;
};

struct TimingCheckAction : single_dispatch<
  // Grammar::setup_timing_check, inner_action<
  //   SetupTimingCheckAction, SetupTimingCheckStorage >,
  Grammar::hold_timing_check, inner_action<
    HoldTimingCheckAction, Storage::member<&TimingCheck::value> > 
> {
  using state = TimingCheck;
};

struct TimingCheckArrayAction : single_dispatch<
  Grammar::tchk_def, inner_action<
    TimingCheckAction,
    Storage::push_back
  >
> {
  using state = TimingCheckSpec;
};

}

}

#endif // LIBSDF_ACTIONS_TIMINGSPEC_HPP
