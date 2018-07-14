#ifndef LIBSDF_TYPES_CELL_HPP
#define LIBSDF_TYPES_CELL_HPP

#include <sdf/types/base.hpp>
#include <sdf/types/timing_spec.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/values.hpp>

#include <variant>

#include <unordered_map>
#include <string>
#include <array>
#include <array>

namespace SDF {
 
using CellInstanceVariant = std::variant<Star,HierarchicalIdentifier>;

struct CellInstance : public CellInstanceVariant {
  using CellInstanceVariant::CellInstanceVariant;
};

struct Cell {
  std::string cell_type;                /// The cell type
  CellInstance cell_instance;           /// The cell instance

  std::vector<TimingSpec> timing_specs; /// The cell data
};
 
} // namespace SDF

#endif // LIBSDF_TYPES_CELL_HPP
