#ifndef LIBSDF_TYPES_CELL_HPP
#define LIBSDF_TYPES_CELL_HPP

#include "./base.hpp"
#include "./enums.hpp"
#include "./timing_spec.hpp"
#include "./values.hpp"

#include <string>
#include <variant>

namespace SDF {

using CellInstanceVariant = std::variant<Star, HierarchicalIdentifier>;

struct CellInstance : public CellInstanceVariant {
  using CellInstanceVariant::CellInstanceVariant;
};

struct Cell {
  std::string cell_type;      /// The cell type
  CellInstance cell_instance; /// The cell instance

  std::vector<TimingSpec> timing_specs; /// The cell data
};

} // namespace SDF

#endif // LIBSDF_TYPES_CELL_HPP
