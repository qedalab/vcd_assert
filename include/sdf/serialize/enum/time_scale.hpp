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
