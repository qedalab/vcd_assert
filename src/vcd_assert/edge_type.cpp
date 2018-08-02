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
