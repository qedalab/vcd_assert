#ifndef LIBSDF_TYPES_CELL_HPP_
#define LIBSDF_TYPES_CELL_HPP_

#include <sdf/types/base.hpp>
#include <sdf/types/timingspec.hpp>

#include <sdf/types/enums.hpp>
#include <sdf/types/values.hpp>
#include <sdf/types/variant.hpp>

#include <variant>

namespace SDF {
namespace Types {

using CellInstanceVariant = std::variant<Star,Path>;

struct CellInstance : public CellInstanceVariant {
  using CellInstanceVariant::CellInstanceVariant;
};

struct Cell {
  std::string celltype;
  CellInstance cell_instance;
  std::vector<TimingSpec> timing_specs;
};

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_CELL_HPP_
