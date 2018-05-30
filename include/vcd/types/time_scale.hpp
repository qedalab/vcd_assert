#ifndef LIBVCD_TYPES_TIME_SCALE_HPP
#define LIBVCD_TYPES_TIME_SCALE_HPP

#include "./enums.hpp"

namespace VCD {

class TimeScale {
  TimeUnit unit_;
  int number_;

public:
  constexpr TimeScale(int number, TimeUnit unit) :
      number_(number), unit_(unit) {}

  constexpr TimeUnit get_unit()
  {
    return unit_;
  }

  constexpr int get_number()
  {
    return number_;
  }
};

} // namespace VCD

#endif //LIBVCD_TYPES_TIME_SCALE_HPP
