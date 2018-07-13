#ifndef VCD_ASSERT_2D_LUT_HPP
#define VCD_ASSERT_2D_LUT_HPP

#include <vcd/types/enums.hpp>

namespace VCDAssert {

enum class EdgeType {NoEdge, PosEdge, NegEdge};

EdgeType get_edge_type(VCD::Value from, VCD::Value to);

} // namespace VCDAssert

#endif // VCD_ASSERT_2D_LUT_HPP
