#ifndef LIBSDF_TYPES_TIME_SCALE_HPP
#define LIBSDF_TYPES_TIME_SCALE_HPP

#include "./enums.hpp"

namespace SDF {

/// View of Time Scale
struct TimeScaleView {
  TimeScaleNumber number; /// Time scale number
  TimeScaleUnit unit;     /// Time scale unit
};

/// Immutable time scale object
class TimeScale
{
  TimeScaleNumber number_; /// Time scale number
  TimeScaleUnit unit_;     /// Time scale unit

public:
  /// Constructs time scale object
  /// \param number the time scale number
  /// \param unit the time scale unit
  constexpr TimeScale(TimeScaleNumber number, TimeScaleUnit unit) noexcept :
      number_(number),
      unit_(unit) {}

  bool operator==(const TimeScale& ts) const noexcept {
    return (number_ == ts.get_number() && unit_ == ts.get_unit());
  }

  /// Returns the time scale unit
  /// \returns The time scale unit
  constexpr TimeScaleUnit get_unit() const noexcept { return unit_; }

  /// Returns the time scale number
  /// \returns the time scale number
  constexpr TimeScaleNumber get_number() const noexcept { return number_; }
};

} // namespace SDF

#endif //LIBSDF_TYPES_TIME_SCALE_HPP
