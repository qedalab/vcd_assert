#ifndef LIBSDF_TYPES_TIMING_HPP
#define LIBSDF_TYPES_TIMING_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>

#include <variant>

namespace SDF {
  
 
namespace Unsupported{
  
} // namespace Unsupported

struct NodeType{
  std::string basename_identifier;
  std::optional<HierarchicalIdentifier> hierarchical_identifier;
  std::optional<std::size_t> size; //scalar if 0 or 1?
};

struct Port : NodeType{
  using NodeType::NodeType;
};
struct Net : NodeType{
  using NodeType::NodeType;
};

using NodeVariant = std::variant<
  Port,
  Net
>;
 

struct Node : public NodeVariant {
  using NodeVariant::NodeVariant;
};

} // namespace SDF


#endif // LIBSDF_TYPES_TIMING_HPP

