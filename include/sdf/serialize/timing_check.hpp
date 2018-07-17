#ifndef LIBSDF_SERIALIZE_TIMINGCHECK_HPP
#define LIBSDF_SERIALIZE_TIMINGCHECK_HPP

#include <sdf/serialize/base.hpp>
#include <sdf/serialize/values.hpp>
#include <sdf/serialize/enum/base.hpp>
#include <sdf/serialize/timing.hpp>
#include <sdf/types/timing_check.hpp>
#include <sdf/types/enums.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {



/// Serialize timing check conditional content
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param cond The TimingCheckCondition check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_timing_check_condition_inner(
    OutputIterator oi, int indent,
    TimingCheckCondition cond) noexcept(noexcept(*oi++ = '!')) {
  Node node;
  if(std::holds_alternative<InvertedNode>(cond.value)){
    node = std::get<InvertedNode>(cond.value);
    ranges::copy(std::string_view("~"), oi);
  }else if(std::holds_alternative<NodeConstantEquality>(cond.value)){
    auto eq = std::get<NodeConstantEquality>(cond.value);
    node = eq.left;
    serialize_node(oi, indent, eq.left);
    if(eq.op == EqualityOperator::logic_equal){
      ranges::copy(std::string_view("=="), oi);
    }else if(eq.op == EqualityOperator::logic_inv){
      ranges::copy(std::string_view("!="), oi);
    }else if(eq.op == EqualityOperator::case_equal){
      ranges::copy(std::string_view("==="), oi);
    }else{
      ranges::copy(std::string_view("!=="), oi);
    }
    if(eq.right){
      ranges::copy(std::string_view("1"), oi);     
    }else{
      ranges::copy(std::string_view("0"), oi);    
    }
  }else{
    node = std::get<Node>(cond.value);
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
  if (port_tchk.timing_check_condition.has_value()) {
    serialize_indent(oi, indent);
    ranges::copy(std::string_view("(COND "), oi);
  }

  {
    if (port_tchk.symbolic_name.has_value()) {
      ranges::copy(port_tchk.symbolic_name.value(), oi);
      ranges::copy(std::string_view(" "), oi);
    }

    if (port_tchk.timing_check_condition.has_value()) {
      serialize_timing_check_condition_inner(oi, indent, port_tchk.timing_check_condition.value());
      ranges::copy(std::string_view(" "), oi);
    }

    if (port_tchk.port.edge.has_value()) {
      ranges::copy(std::string_view("("), oi);
      ranges::copy(edgetype_to_string(port_tchk.port.edge.value()), oi);
      ranges::copy(std::string_view(" "), oi);
    }

    serialize_node(oi, 0, port_tchk.port);

    if (port_tchk.port.edge.has_value()) {
      ranges::copy(std::string_view(")"), oi);
    }
  }

  if (port_tchk.timing_check_condition.has_value()) {
    ranges::copy(std::string_view(")"), oi);
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
  serialize_indent(oi, indent);
  ranges::copy(std::string_view("(HOLD "), oi);
  serialize_port_tchk(oi, 0, hold.input);
  ranges::copy(std::string_view(" "), oi);
  serialize_port_tchk(oi, 0, hold.output);
  ranges::copy(std::string_view(" "), oi);
  serialize_value(oi, 0, hold.value);
  ranges::copy(std::string_view(")\n"), oi);
}

/// Serialize SDF timing check definition
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param tc The SDF timing check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_timing_check(OutputIterator oi, int indent,
                            TimingCheck tc) noexcept(noexcept(*oi++ = '!')) {
  // only HOLD timing checks supported at the moment.
  assert(tc.get_enum_type() == TimingCheckType::hold);

  // serialize_indent(oi, indent);

  switch (tc.get_enum_type()) {
  case TimingCheckType::setup:
    throw std::runtime_error("InternalError");
    // serialize_setup_check(oi, indent + 1, tc);
    break;
  case TimingCheckType::hold:
    serialize_hold_check(oi, indent, std::get<Hold>(tc.value));
    break;
  default:
    throw std::runtime_error("InternalError");
  }

  // serialize_indent(oi, indent);
  // ranges::copy(")\n"sv, oi);
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
  for (auto &&tc : tcs) {
    serialize_timing_check(oi, indent, tc);
  }
}

} // namespace SDF

#endif // LIBSDF_SERIALIZE_TIMINGCHECK_HPP
