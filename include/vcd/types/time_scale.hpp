#ifndef LIBVCD_TYPES_TIME_SCALE_HPP
#define LIBVCD_TYPES_TIME_SCALE_HPP

#include "./enums.hpp"

namespace VCD {

struct TimeScaleView {
  TimeNumber number;
  TimeUnit unit;
};

class TimeScale {
  TimeNumber number_;
  TimeUnit unit_;

public:
  constexpr TimeScale(TimeNumber number, TimeUnit unit) :
      number_(number), unit_(unit) {}

  constexpr TimeUnit get_unit()
  {
    return unit_;
  }

  constexpr TimeNumber get_number()
  {
    return number_;
  }
};

} // namespace VCD

#endif //LIBVCD_TYPES_TIME_SCALE_HPP
