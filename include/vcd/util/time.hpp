#ifndef LIBVCD_UTIL_TIME_HPP
#define LIBVCD_UTIL_TIME_HPP

#include "../types/time_scale.hpp"

#include <string>

namespace VCD::Util {

std::string time_string(VCD::TimeScale scale, std::size_t time);

} // namespace VCD::Util

#endif // LIBVCD_UTIL_TIME_HPP
