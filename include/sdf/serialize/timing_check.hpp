#ifndef LIBSDF_SERIALIZE_TIMINGCHECK_HPP
#define LIBSDF_SERIALIZE_TIMINGCHECK_HPP

#include <sdf/types/timing_check.hpp>
#include <sdf/types/enums.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {

/// Serialize port definition
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param pt The HOLD check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_hierarchical_identifier(
    OutputIterator oi, int indent,
    HierarchicalIdentifier hi) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  auto sep = hi.sep == HChar::dot ? "."sv : "/"sv;
  for(auto&& str : hi.value){
    ranges::copy(str, oi);
    ranges::copy(sep, oi);    
  }
}

/// Serialize port definition
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param pt The HOLD check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_node_spec(
    OutputIterator oi, int indent,
    Node node) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  auto hi = node.hierarchical_identifier;
  if(hi){
    serialize_hierarchical_identifier(oi,indent,hi);
  }
  serialize_indent(oi, indent);
  ranges::copy(node.basename_identifier, oi);
  if(node.size()){
    ranges::copy("["sv, oi);
    ranges::copy(node.basename_identifier, oi);
    ranges::copy("]"sv, oi);
  }
}

/// Serialize timing check conditional
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param pt The HOLD check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_timing_check_condition_inner(
    OutputIterator oi, int indent,
    TimingCheckCondition cond) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  Node node;
  if(std::holds_alternative<InvertedNode>(cond)){
    node = cond;
    ranges::copy("~"sv, oi);
  }else if(std::holds_alternative<NodeScalarEquality>(cond)){
    auto eq = std::get<NodeScalarEquality>(cond);
    node = eq.left;
    serialize_node(oi, indent, eq.left);
    if(eq.op == logic_equal){
      ranges::copy("=="sv, oi);
    }else if(eq.op == logic_inv){
      ranges::copy("!="sv, oi);
    }else if(eq.op == case_equal){
      ranges::copy("==="sv, oi);
    }else{
      ranges::copy("!=="sv, oi);
    }
    if(eq.right){
      ranges::copy("1"sv, oi);     
    }else{
      ranges::copy("0"sv, oi);    
    }
  }
  serialize_node(oi, indent, node);
}

/// Serialize timing check port check 
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param port_tchk The PortTimingCheck check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_port_tchk(
    OutputIterator oi, int indent,
    PortTimingCheck port_tchk) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  if (port_tchk.timing_check_condition) {
    serialize_indent(oi, indent);
    ranges::copy("(COND "sv, oi);
  }

  {
    if (port_tchk.symbolic_name) {
      ranges::copy(port_tchk.edge_identifier, oi);
      ranges::copy(" "sv, oi);
    }

    if (port_tchk.timing_check_condition) {
      serialize_timing_check_condition_inner(oi, indent, port_tchk.timing_check_condition)
    }

    if (port_tchk.edge_identifier) {
      ranges::copy("("sv, oi);
      ranges::copy(port_tchk.edge_identifier, oi);
      ranges::copy(" "sv, oi);
    }

    serialize_node_spec(oi, 0, port_tchk.port);

    if (port_tchk.edge_identifier) {
      ranges::copy(")"sv, oi);
    }
  }

  if (pt.timing_check_condition) {
    ranges::copy(" )"sv, oi);
  }
}
/// Serialize HOLD timing check
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param hold The HOLD check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_hold_check(OutputIterator oi, int indent,
                          Hold hold) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(HOLD "sv, oi);
  serialize_port_tchk(oi, 0, hold.input);
  ranges::copy(" "sv, oi);
  serialize_port_tchk(oi, 0, hold.output);
  ranges::copy(" "sv, oi);
  serialize_value(oi, 0, hold.value);
  ranges::copy(" )\n"sv, oi);
}

/// Serialize SDF timing check definition
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param tc The SDF timing check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_timing_check(OutputIterator oi, int indent,
                            TimingCheck tc) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  // only HOLD timing checks supported at the moment.
  assert(tc.get_enum_type() == TimingCheckType::hold);

  serialize_indent(oi, indent);

  switch (ts.get_enum_type()) {
  case TimingSpecType::delay:
    throw std::runtime_error("InternalError");
    // ranges::copy("(SETUP "sv, oi);
    // serialize_setup_checks(oi, indent + 1, ts);
    break;
  case TimingSpecType::timing_check:
    ranges::copy("(HOLD "sv, oi);
    serialize_hold_checks(oi, indent + 1, ts);
    break;
  default:
    throw std::runtime_error("InternalError");
  }

  serialize_indent(oi, indent);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF timing check specification
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param tcs The SDF timing check specification to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_timing_check_spec(
    OutputIterator oi, int indent,
    TimingCheckSpec tcs) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  for (auto &&tc : tcs) {
    serialize_timing_check(oi, indent, tc);
  }
}

} // namespace SDF

#endif // LIBSDF_SERIALIZE_TIMINGCHECK_HPP
