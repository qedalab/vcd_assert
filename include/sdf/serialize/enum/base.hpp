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
  default:
    assert(false && "Invalid enum state");
    abort();
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
  default:
    assert(false && "Invalid enum state");
    abort();
  }
}

}

#endif // LIBSDF_SERIALIZE_ENUM_HIERARCHY_HPP