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
