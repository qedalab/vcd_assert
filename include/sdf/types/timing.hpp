#ifndef LIBSDF_TYPES_TIMING_HPP
#define LIBSDF_TYPES_TIMING_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>

#include <variant>

namespace SDF {

namespace Unsupported {} // namespace Unsupported

// struct NodeType{};
// struct Port : public NodeType{};
// struct Net : public NodeType{};

// using NodeVariant = std::variant<
//   Port,
//   Net
// >;

struct Node {
  NodeType type;
  std::string basename_identifier;
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

} // namespace SDF

#endif // LIBSDF_TYPES_TIMING_HPP
