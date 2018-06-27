#ifndef LIBVCD_TYPES_VALUE_CHANGE_HPP
#define LIBVCD_TYPES_VALUE_CHANGE_HPP

#include "./enums.hpp"

#include <string_view>
#include <range/v3/span.hpp>

namespace VCD {

/// View of scalar value change
/// \todo ensure identifier code correctness
struct ScalarValueChangeView {
  Value value;                      /// scalar value
  std::string_view identifier_code; /// identifier code
};

/// View of vector value change
/// \todo ensure identifier code correctness
struct VectorValueChangeView {
  ranges::span<Value> values;       /// view of vector values
  std::string_view identifier_code; /// identifier code
};

/// View of real value change
/// \todo ensure identifier code correctness
struct RealValueChangeView {
  double value;                     /// real value
  std::string_view identifier_code; /// identifier code
};

} // namespace VCD

#endif // LIBVCD_TYPES_VALUE_CHANGE_HPP
