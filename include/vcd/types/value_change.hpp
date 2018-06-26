#ifndef LIBVCD_TYPES_VALUE_CHANGE_HPP
#define LIBVCD_TYPES_VALUE_CHANGE_HPP

#include "./enums.hpp"

#include <string_view>
#include <range/v3/span.hpp>

namespace VCD {

struct ScalarValueChangeView {
  Value value;
  std::string_view identifier_code;
};

struct VectorValueChangeView {
  ranges::span<Value> values;
  std::string_view identifier_code;
};

struct RealValueChangeView {
  double value;
  std::string_view identifier_code;
};

} // namespace VCD

#endif // LIBVCD_TYPES_VALUE_CHANGE_HPP
