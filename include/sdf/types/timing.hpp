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

#ifndef LIBSDF_TYPES_TIMING_HPP
#define LIBSDF_TYPES_TIMING_HPP

#include "./base.hpp"
#include "./values.hpp"

#include <optional>

namespace SDF {

namespace Unsupported {} // namespace Unsupported

// struct NodeType{};
// struct Port : public NodeType{};
// struct Net : public NodeType{};

// using NodeVariant = std::variant<
//   Port,
//   Net
// >;

// Technically a node is a net_instance or port_instance as they are interchangeable
struct Node {
  NodeType type = NodeType::unspecified; //could make ScalarNet, ScalarPort, BusNet, BusPort
  std::string basename_identifier;
  std::optional<EdgeType> edge = {}; //only allowed if node is port spec
  std::optional<HierarchicalIdentifier> hierarchical_identifier = {};
  std::optional<std::size_t> start {};
  std::optional<std::size_t> end {};

  bool operator==(const Node &other) const noexcept {
    if ((basename_identifier == other.basename_identifier) &&
        (edge == other.edge) &&
        (hierarchical_identifier == other.hierarchical_identifier) &&
        (type == other.type) && (start == other.start) && (end == other.end)){
      return true;
    } else {
      return false;
    }
  }

};

// //FOR DELAY
// //port_spec shall be an input or a bidirectional port and can have an edge identifier.
// //port_instance shall be an output or a bidirectional port.
// struct Bussed {
//   std::size_t start;
//   std::size_t end;
// }

// struct Indexed {
//   std::size_t index;
// }

// struct PortInstance : Node{};
// struct NetInstance : Node{};

// struct BusPort : PortInstance + Bussed{};
// struct ScalarPort : PortInstance + Indexed{};

// struct BusNet : NetInstance + Bussed{};
// struct ScalarNet : NetInstance + Indexed{};

// using ScalarNode = std::variant<
//   ScalarPort,
//   ScalarNet
// >;
// using BusNode = std::variant<
//   BusPort,
//   BusNet
// >;
// using VectorNode = BusNode; 

// using Port = std::variant<
//   ScalarPort,
//   BusPort
// >;

// using Net = std::variant<
//   ScalarNet,
//   BusNet
// >;

// struct PortSpec : Port{
//   using Port::Port
//   std::optional<EdgeType> edge;
// };

// struct NetSpec : NetInstance{};

} // namespace SDF

#endif // LIBSDF_TYPES_TIMING_HPP
