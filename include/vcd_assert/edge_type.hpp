// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

#ifndef VCD_ASSERT_2D_LUT_HPP
#define VCD_ASSERT_2D_LUT_HPP

#include <vcd/types/enums.hpp>
#include <string_view>

#include <cstdio>
#include <cstdlib>

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

constexpr std::string_view edge_type_to_string(EdgeType et)
{
  switch (et) {
  case EdgeType::NoEdge:
    return "NoEdge";
  case EdgeType::PosEdge:
    return "PosEdge";
  case EdgeType::NegEdge:
    return "NegEdge";
  case EdgeType::Edge:
    return "Edge";
  case EdgeType::_01:
    return "01";
  case EdgeType::_10:
    return "10";
  case EdgeType::_0z:
    return "0z";
  case EdgeType::_z1:
    return "z1";
  case EdgeType::_1z:
    return "1z";
  case EdgeType::_z0:
    return "z0";
  default:                                             // LCOV_EXCL_LINE
    std::puts("UNREACHABLE CODE: Invalid enum state"); // LCOV_EXCL_LINE
    std::abort();                                      // LCOV_EXCL_LINE
  }
}

EdgeType get_edge_type(VCD::Value from, VCD::Value to);
bool edge_type_matches(EdgeType type, VCD::Value from, VCD::Value to);

} // namespace VCDAssert

#endif // VCD_ASSERT_2D_LUT_HPP
