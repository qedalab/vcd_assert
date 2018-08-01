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

#ifndef LIBSDF_SERIALIZE_ENUM_BASE_HPP
#define LIBSDF_SERIALIZE_ENUM_BASE_HPP

#include <sdf/types/enums.hpp>
#include <string_view>
#include <cassert>
#include <cstdlib>

namespace SDF{

/// Convert HChar enum to string representation
/// \param h The HChar to convert.
///           Must be in valid enum state undefined behaviour otherwise
/// \returns static view of HChar string
constexpr std::string_view hierarchy_divider_to_string(HChar h) noexcept {
  switch (h) {
  case HChar::dot:
    return ".";
  case HChar::slash:
    return "/";
  default:                                           // LCOV_EXCL_LINE
    std::puts("INTERNAL ERROR: Invalid enum state"); // LCOV_EXCL_LINE
    std::abort();                                    // LCOV_EXCL_LINE
  }
}

/// Convert EdgeType enum to string representation
/// \param e The EdgeType to convert.
///           Must be in valid enum state undefined behaviour otherwise
/// \returns static view of EdgeType string
constexpr std::string_view edgetype_to_string(EdgeType e) noexcept {
  switch (e) {
  case EdgeType::posedge:
    return "posedge";
  case EdgeType::negedge:
    return "negedge";
  case EdgeType::_01:
      return "01";
  case EdgeType::_10:
      return "10";
  case EdgeType::_0z:
      return "0z";
  case EdgeType::_z1:
      return "z1";
  case EdgeType::_1z:
      return "1z";
  case EdgeType::_z0:
      return "z0";
  default:                                           // LCOV_EXCL_LINE
    std::puts("INTERNAL ERROR: Invalid enum state"); // LCOV_EXCL_LINE
    std::abort();                                    // LCOV_EXCL_LINE
  }
}

}

#endif // LIBSDF_SERIALIZE_ENUM_HIERARCHY_HPP
