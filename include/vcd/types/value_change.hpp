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

#ifndef LIBVCD_TYPES_VALUE_CHANGE_HPP
#define LIBVCD_TYPES_VALUE_CHANGE_HPP

#include "./enums.hpp"
#include "parse/util/marker.hpp"

#include <range/v3/span.hpp>
#include <string_view>

namespace VCD {

/// View of scalar value change
/// \todo ensure identifier code correctness
struct ScalarValueChangeView {
  Value value{};                    /// scalar value
  std::string_view identifier_code; /// identifier code
  Parse::Util::Marker marker = {0,0};
};

/// View of vector value change
/// \todo ensure identifier code correctness
struct VectorValueChangeView {
  ranges::span<Value> values;       /// view of vector values
  std::string_view identifier_code; /// identifier code
  Parse::Util::Marker marker = {0,0};
};

/// View of vector value change
struct UncheckedVectorValueChangeView {
  std::string_view values;
  std::string_view identifier_code;
  Parse::Util::Marker marker = {0,0};
};

/// View of real value change
/// \todo ensure identifier code correctness
struct RealValueChangeView {
  double value;                     /// real value
  std::string_view identifier_code; /// identifier code
  Parse::Util::Marker marker = {0,0};
};

} // namespace VCD

#endif // LIBVCD_TYPES_VALUE_CHANGE_HPP
