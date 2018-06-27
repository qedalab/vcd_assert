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
