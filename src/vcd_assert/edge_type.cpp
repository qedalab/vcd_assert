#include "vcd_assert/edge_type.hpp"

auto VCDAssert::get_edge_type(VCD::Value from, VCD::Value to) -> EdgeType {
  if(from == to)
    return EdgeType::NoEdge;

  if(from == VCD::Value::zero || to == VCD::Value::one)
    return EdgeType::PosEdge;

  if(from == VCD::Value::one || to == VCD::Value::zero)
    return EdgeType::NegEdge;

  return EdgeType::NoEdge;
}
