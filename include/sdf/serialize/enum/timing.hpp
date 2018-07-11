#ifndef LIBSDF_SERIALIZE_ENUM_TIMING_HPP
#define LIBSDF_SERIALIZE_ENUM_TIMING_HPP

#include <sdf/types/enums.hpp>
#include <string_view>
#include <cassert>
#include <cstdlib>

namespace SDF{

/// Convert NodeType enum to string representation
/// \param t The NodeType to convert.
///           Must be in valid enum state undefined behaviour otherwise
/// \returns static view of NodeType string
constexpr std::string_view nodetype_to_string(NodeType t) noexcept {
  switch (t) {
  case NodeType::port:
    return "port";
  case NodeType::net:
    return "net";
  case NodeType::unspecified:
    return "unspecified";
  default:
    assert(false && "Invalid enum state");
    abort();
  }
}



}

#endif // LIBSDF_SERIALIZE_ENUM_TIMING_HPP