#include "vcd_assert/edge_type.hpp"

bool VCDAssert::edge_type_matches(EdgeType type, VCD::Value from, VCD::Value to) {
  if(from == to)
    return type == EdgeType::NoEdge;

  if (from == VCD::Value::zero) {
    if (type == EdgeType::_01)
      return to == VCD::Value::one;

    if (type == EdgeType::_0z)
      return to == VCD::Value::z;

    return EdgeType::PosEdge == type || EdgeType::Edge == type;
  }

  if (from == VCD::Value::one) {
    if (type == EdgeType::_10)
      return to == VCD::Value::zero;

    if (type == EdgeType::_1z)
      return to == VCD::Value::z;

    return EdgeType::NegEdge == type || EdgeType::Edge == type;
  }

  if (from == VCD::Value::z) {
    if (type == EdgeType::_z0)
      return to == VCD::Value::zero;

    if (type == EdgeType::_z1)
      return to == VCD::Value::one;
  }

  if (to == VCD::Value::one)
    return type == EdgeType::PosEdge || type == EdgeType::Edge;

  if (to == VCD::Value::zero)
    return type == EdgeType::NegEdge || type == EdgeType::Edge;

  return type == EdgeType::NoEdge;
}

auto VCDAssert::get_edge_type(VCD::Value from, VCD::Value to) -> EdgeType
{
  if (from == to)
    return EdgeType::NoEdge;

  if (from == VCD::Value::zero || to == VCD::Value::one)
    return EdgeType::PosEdge;

  if (from == VCD::Value::one || to == VCD::Value::zero)
    return EdgeType::NegEdge;

  return EdgeType::NoEdge;
}
