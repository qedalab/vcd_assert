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

namespace SDF {
 
using CellInstanceVariant = std::variant<Star,HierarchicalIdentifier>;

struct CellInstance : public CellInstanceVariant {
  using CellInstanceVariant::CellInstanceVariant;
};

/// View of cell data
struct CellView {

  std::string cell_type;
  CellInstance cell_instance;

  std::vector<TimingSpec> timing_specs;
};

/// SDF Cell object
/// This object is defined in terms of the DelayFile it is contained in and can
/// therefore only be populated alongside the DelayFile with DelayFileReader
/// \related DelayFileReader
class Cell {
  
  std::string cell_type_;                /// The cell type
  CellInstance cell_instance_;           /// The cell instance

  std::vector<TimingSpec> timing_specs_; /// The cell data

  friend class DelayFileReader; 
public:
  /// The cell constructor
  /// \param type The cell type
  /// \param instance The cell instance
  /// \param specs The timing specs
  Cell(std::string type, CellInstance instance, std::vector<TimingSpec> specs) noexcept;

  /// Get the timing spec indices by type
  /// \param type The cell type
  /// \returns The cell index
  /// \todo change to iterator/range-view
  std::vector<std::size_t> get_timing_specs_indices(std::string &celltype) const;
  std::vector<std::size_t> get_timing_specs_indices(TimingSpecType &type) const;

  /// Number of timing_specs in cell
  /// \returns The number of timing_specs directly in this cell
  std::size_t num_timing_specs() const noexcept;

  /// Get cell instance
  /// \returns CellInstance of either HierarchialIdentifier or Star.
  CellInstance get_cell_instance() const noexcept;

  /// Get cell type
  /// \returns The cell type
  std::string_view get_cell_type() const noexcept;

  /// Convert to CellView
  /// \returns CellView of Cell
  operator CellView() const noexcept;
};


 
} // namespace SDF

#endif // LIBSDF_TYPES_CELL_HPP
