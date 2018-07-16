#ifndef LIBSDF_TYPES_TIMING_HPP
#define LIBSDF_TYPES_TIMING_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>

#include <variant>
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
  NodeType type; //could make ScalarNet, ScalarPort, BusNet, BusPort
  std::string basename_identifier;
  std::optional<EdgeType> edge; //only allowed if node is port spec
  std::optional<HierarchicalIdentifier> hierarchical_identifier;
  std::optional<std::size_t> start;
  std::optional<std::size_t> end;

  bool operator==(const Node &other) const noexcept {
    if ((basename_identifier == other.basename_identifier) &&
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
