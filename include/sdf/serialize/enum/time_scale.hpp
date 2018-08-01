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

#ifndef LIBSDF_SERIALIZE_ENUM_TIMESCALE_HPP
#define LIBSDF_SERIALIZE_ENUM_TIMESCALE_HPP

#include <sdf/types/time_scale.hpp>

#include <string_view>
#include <cassert>
#include <cstdlib>

namespace SDF {

/// Convert TimeScaleUnit enum to string representation
/// \param tu The TimeScaleUnit to convert.
///           Must be in valid enum state undefined behaviour otherwise
/// \returns static view of TimeScaleUnit string
constexpr std::string_view timescale_unit_to_string(TimeScaleUnit tu) noexcept {
  switch (tu) {
  case TimeScaleUnit::s:
    return "s";
  case TimeScaleUnit::ms:
    return "ms";
  case TimeScaleUnit::us:
    return "us";
  case TimeScaleUnit::ns:
    return "ns";
  case TimeScaleUnit::ps:
    return "ps";
  case TimeScaleUnit::fs:
    return "fs";
  default:                                           // LCOV_EXCL_LINE
    std::puts("INTERNAL ERROR: Invalid enum state"); // LCOV_EXCL_LINE
    std::abort();                                    // LCOV_EXCL_LINE
  }
}

/// Convert TimeScaleNumber enum to string representation
/// \param tn The TimeScaleNumber to convert.
///           Must be in valid enum state undefined behaviour otherwise
/// \returns static view of TimeNumber string
constexpr std::string_view timescale_number_to_string(TimeScaleNumber tn) noexcept {
  switch (tn) {
  case TimeScaleNumber::_1:
    return "1";
  case TimeScaleNumber::_10:
    return "10";
  case TimeScaleNumber::_100:
    return "100";
  default:                                           // LCOV_EXCL_LINE
    std::puts("INTERNAL ERROR: Invalid enum state"); // LCOV_EXCL_LINE
    std::abort();                                    // LCOV_EXCL_LINE
  }
}


} // namespace SDF

#endif // LIBSDF_SERIALIZE_ENUM_TIMESCALE_HPP
