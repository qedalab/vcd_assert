#ifndef LIBSDF_SERIALIZE_DELAYFILE_HPP
#define LIBSDF_SERIALIZE_DELAYFILE_HPP

// #include <sdf/serialize/enum/time_scale.hpp>

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
                     Cell cell) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(CELLTYPE "sv, oi);
  serialize_quoted(oi, cell.cell_type);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF cell type
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param timescale The SDF file timescale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_cell_instance(OutputIterator oi, int indent,
                     Cell cell) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(CELLINSTANCE "sv, oi);
  serialize_quoted(oi, cell.cell_type);
  ranges::copy(")\n"sv, oi);
}

/// Serialize SDF cells
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param timescale The SDF file timescale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_cell(OutputIterator oi, int indent,
                     Cell cell) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  serialize_indent(oi, indent);
  ranges::copy("(CELL \n"sv, oi);
  serialize_cell_type(oi, indent+1, cell.cell_type);
  serialize_cell_instance(oi, indent+1, cell.cell_type);

  for (auto &&timing_spec : cell.timing_specs) {
    serialize_timing_spec(oi, indent+1, timing_spec);
  }
  serialize_indent(oi, indent);
  ranges::copy(")\n"sv, oi);
}


/// Serialize SDF cells
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param timescale The SDF file timescale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_cells(OutputIterator oi, int indent,
                     std::vector<Cell> cells) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  for (auto &&cell : cells) {
    serialize_cell(oi, indent, cell);
  }
}


} // namespace SDF

#endif // LIBSDF_SERIALIZE_HEADER_HPP
