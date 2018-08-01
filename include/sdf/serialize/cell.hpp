// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

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
