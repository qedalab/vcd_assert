#ifndef LIBSDF_SERIALIZE_CELL_HPP
#define LIBSDF_SERIALIZE_CELL_HPP

// #include <sdf/serialize/enum/time_scale.hpp>
#include <sdf/serialize/base.hpp>
#include <sdf/serialize/timing_spec.hpp>

#include <sdf/types/cell.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {

/// Serialize SDF cell type
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param timescale The SDF file timescale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_cell_type(OutputIterator oi, int indent,
                     std::string_view cell_type) noexcept(noexcept(*oi++ = '!')) {
  serialize_indent(oi, indent);
  ranges::copy(std::string_view("(CELLTYPE "), oi);
  serialize_quoted(oi, cell_type);
  ranges::copy(std::string_view(")\n"), oi);
}

/// Serialize SDF cell type
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param timescale The SDF file timescale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_cell_instance(OutputIterator oi, int indent,
                     CellInstance cell_instance) noexcept(noexcept(*oi++ = '!')) {
  serialize_indent(oi, indent);
  ranges::copy(std::string_view("(INSTANCE "), oi);
  if(std::holds_alternative<Star>(cell_instance)){
    ranges::copy(std::string_view("*"), oi);
  }else{
    serialize_hierarchical_identifier(oi, indent, std::get<HierarchicalIdentifier>(cell_instance));
  }
  // serialize_quoted(oi, cell_instance);
  ranges::copy(std::string_view(")\n"), oi);
}

/// Serialize SDF cells
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param timescale The SDF file timescale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_cell(OutputIterator oi, int indent,
                     Cell cell) noexcept(noexcept(*oi++ = '!')) {
  serialize_indent(oi, indent);
  ranges::copy(std::string_view("(CELL \n"), oi);
  serialize_cell_type(oi, indent+1, cell.cell_type);
  serialize_cell_instance(oi, indent+1, cell.cell_instance);

  for (auto &&timing_spec : cell.timing_specs) {
    serialize_timing_spec(oi, indent+1, timing_spec);
  }
  serialize_indent(oi, indent);
  ranges::copy(std::string_view(")\n"), oi);
}

/// Serialize SDF cells
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param timescale The SDF file timescale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_cells(OutputIterator oi, int indent,
                     std::vector<Cell> cells) noexcept(noexcept(*oi++ = '!')) {
  for (auto &&cell : cells) {
    serialize_cell(oi, indent, cell);
  }
}


} // namespace SDF

#endif // LIBSDF_SERIALIZE_CELL_HPP
