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

#ifndef LIBSDF_SERIALIZE_DELAYFILE_HPP
#define LIBSDF_SERIALIZE_DELAYFILE_HPP

#include <sdf/serialize/base.hpp>
#include <sdf/serialize/cell.hpp>
#include <sdf/serialize/header.hpp>
#include <sdf/serialize/enum/time_scale.hpp>

#include <sdf/types/delayfile.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace SDF {

/// Serialize SDF header
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param sdf_version The sdf_version to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_delayfile(OutputIterator oi,
                         DelayFile df) noexcept(noexcept(*oi++ = '!')) {
                           
  ranges::copy(std::string_view("(DELAYFILE \n"), oi);
  serialize_sdf_version(oi, 1, df.get_sdf_version());

  if (df.has_design_name()) {
    serialize_design_name(oi, 1, df.get_design_name().value());
  }
  
  if (df.has_date()) {
    serialize_date(oi, 1, df.get_date().value());
  }
  
  if (df.has_vendor()) {
    serialize_vendor(oi, 1, df.get_vendor().value());
  }
  
  if (df.has_program_name()) {
    serialize_program_name(oi, 1, df.get_program_name().value());
  }
  
  if (df.has_program_version()) {
    serialize_program_version(oi, 1, df.get_program_version().value());
  }
  
  if (df.has_hierarchy_divider()) {
    serialize_hierarchy_divider(oi, 1, df.get_hierarchy_divider().value());
  }
  
  if (df.has_voltage()) {
    serialize_voltage(oi, 1, df.get_voltage().value());
  }
  
  if (df.has_process()) {
    serialize_process(oi, 1, df.get_process().value());
  }
  
  if (df.has_temperature()) {
    serialize_temperature(oi, 1, df.get_temperature().value());
  }
  
  if (df.has_timescale()) {
    serialize_timescale(oi, 1, df.get_timescale().value());
  }
  
  serialize_cells(oi, 1, df.get_cells());
  ranges::copy(std::string_view(")\n"), oi);
}

} // namespace SDF

#endif // LIBSDF_SERIALIZE_DELAYFILE_HPP
