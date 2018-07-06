#ifndef LIBSDF_TYPES_TIMING_HPP
#define LIBSDF_TYPES_TIMING_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>

#include <variant>

namespace SDF {
  
 
namespace Unsupported{
  
} // namespace Unsupported

// struct NodeType{};
// struct Port : public NodeType{};
// struct Net : public NodeType{};

// using NodeVariant = std::variant<
//   Port,
//   Net
// >;

struct Node  {
  NodeType type;
  std::string basename_identifier;
  std::optional<HierarchicalIdentifier> hierarchical_identifier;
  std::optional<std::size_t> size; //scalar if 0 or 1?
};

} // namespace SDF


#endif // LIBSDF_TYPES_TIMING_HPP

