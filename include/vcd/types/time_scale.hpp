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

#ifndef LIBVCD_TYPES_TIME_SCALE_HPP
#define LIBVCD_TYPES_TIME_SCALE_HPP

#include "./enums.hpp"

namespace VCD {

/// View fo Time Scale
struct TimeScaleView {
  TimeNumber number; /// Time scale number
  TimeUnit unit;     /// Time scale unit
};

/// Immutable time scale object
class TimeScale
{
  TimeNumber number_; /// Time scale number
  TimeUnit unit_;     /// Time scale unit

public:
  /// Constructs time scale object
  /// \param number the time scale number
  /// \param unit the time scale unit
  constexpr TimeScale(TimeNumber number, TimeUnit unit) noexcept :
      number_(number),
      unit_(unit) {}

  /// Returns the time scale unit
  /// \returns The time scale unit
  constexpr TimeUnit get_unit() const noexcept { return unit_; }

  /// Returns the time scale number
  /// \returns the time scale number
  constexpr TimeNumber get_number() const noexcept { return number_; }
};

} // namespace VCD

#endif //LIBVCD_TYPES_TIME_SCALE_HPP
