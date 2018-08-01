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

#ifndef LIBSDF_SERIALIZE_TIMING_HPP
#define LIBSDF_SERIALIZE_TIMING_HPP

#include <sdf/serialize/base.hpp>
#include <sdf/serialize/enum/base.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {



/// Serialize node definition
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param pt The HOLD check definition to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_node(
    OutputIterator oi, int indent,
    Node node) noexcept(noexcept(*oi++ = '!')) {

  serialize_indent(oi, indent);

  // auto hi = static_cast<Port>(node).hierarchical_identifier;
  auto hi = node.hierarchical_identifier;
  if(hi.has_value()){
    serialize_hierarchical_identifier(oi, indent, hi.value());
  }

  ranges::copy(node.basename_identifier, oi);

  if(node.start.has_value()){
    ranges::copy(std::string_view("["), oi);
    if(node.end.has_value()){
      ranges::copy(std::to_string(node.end.value()), oi);
      ranges::copy(std::string_view(":"), oi);
    }
    ranges::copy(std::to_string(node.start.value()), oi);
    ranges::copy(std::string_view("]"), oi);
  }
}

/// Serialize edge type specifier
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param edge The EdgeType to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_port_edge(
    OutputIterator oi, int indent,
    EdgeType edge) noexcept(noexcept(*oi++ = '!')) {
    serialize_indent(oi, indent);
    ranges::copy(edgetype_to_string(edge), oi);

}

/// Serialize port definition
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param port The Port node to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_port(
    OutputIterator oi, int indent,
    Node port) noexcept(noexcept(*oi++ = '!')) {
  auto edge = port.edge;
  if(edge.has_value()){
    ranges::copy(std::string_view("( "), oi);
    serialize_indent(oi, indent);
    serialize_port_edge(oi, indent, edge.value());
  }
  serialize_node(oi, 0, port);

  if(edge.has_value()){
    ranges::copy(std::string_view(")"), oi);
  }

}


} // namespace SDF

#endif // LIBSDF_SERIALIZE_TIMING_HPP
