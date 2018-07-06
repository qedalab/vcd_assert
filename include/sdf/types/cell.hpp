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

// /// View of cell data
// struct CellView {

//   std::string cell_type_;
//   CellInstance cell_instance_;

//   std::vector<TimingSpec> timing_specs_;
// };

/// SDF Cell object
/// This object is defined in terms of the DelayFile it is contained in and can
/// therefore only be populated alongside the DelayFile with DelayFileReader
/// \related DelayFileReader
struct Cell {
  
  std::string cell_type;                /// The cell type
  CellInstance cell_instance;           /// The cell instance

  std::vector<TimingSpec> timing_specs; /// The cell data

//   // friend class DelayFileReader; 
// // public:
// //   /// The cell constructor
// //   /// \param type The cell type
// //   /// \param instance The cell instance
// //   /// \param specs The timing specs
// //   Cell(std::string cell_type, CellInstance cell_instance, std::vector<TimingSpec> timing_specs) noexcept;

  /// Get cell instance
  /// \returns CellInstance of either HierarchialIdentifier or Star.
  // CellInstance get_cell_instance() const noexcept;

//   /// Get cell type
//   /// \returns The cell type
//   std::string_view get_cell_type() const noexcept;

//   /// Get all timing spec indices of the specified type 
//   /// \param cell_type The cell type string
//   /// \returns The timing spec indices
//   // std::vector<std::size_t> get_timing_spec_indices_by_type(std::string &timing_spec_type) const noexcept;
    
//   // /// Get all timing spec indices of the specified type 
//   // /// \param type The cell type enum
//   // /// \returns The timing spec indices
//   std::vector<std::size_t> get_timing_spec_indices_by_type(TimingSpecType &type) const;

//   /// Get timing spec by index
//   /// \returns The timing spec
//   TimingSpec& get_timing_spec(std::size_t index); //todo: rather output CellView?

//   /// Number of timing_specs in cell
//   /// \returns The number of timing_specs directly in this cell
//   std::size_t num_timing_specs() const noexcept;

//   /// Get all timing specs
//   /// \returns The timing spec
//   std::vector<TimingSpec> get_timing_specs() const noexcept; //todo return View


  /// Convert to CellView
  /// \returns CellView of Cell
  // operator CellView() const noexcept;
};


 
} // namespace SDF

#endif // LIBSDF_TYPES_CELL_HPP
