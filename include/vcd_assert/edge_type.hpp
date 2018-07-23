#ifndef VCD_ASSERT_2D_LUT_HPP
#define VCD_ASSERT_2D_LUT_HPP

#include <vcd/types/enums.hpp>

namespace VCDAssert {

enum class EdgeType {
  NoEdge,
  PosEdge,
  NegEdge,
  Edge,
  _01,
  _10,
  _0z,
  _z1,
  _1z,
  _z0
};

EdgeType get_edge_type(VCD::Value from, VCD::Value to);
bool edge_type_matches(EdgeType type, VCD::Value from, VCD::Value to);

} // namespace VCDAssert

#endif // VCD_ASSERT_2D_LUT_HPP
