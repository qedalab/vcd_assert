#ifndef LIBVCD_SERIALIZE_VALUE_CHANGE_HPP
#define LIBVCD_SERIALIZE_VALUE_CHANGE_HPP

#include "./enums.hpp"
#include "../types/value_change.hpp"

#include <range/v3/algorithm/copy.hpp>

namespace VCD {

template<class OutputIterator>
void serialize_value_change(OutputIterator oi, ScalarValueChangeView svcv) {
  using std::literals::string_view_literals::operator""sv;

  *oi++ = value_to_char(svcv.value);
  ranges::copy(svcv.identifier_code, oi);
  ranges::copy("\n"sv, oi);
}

template<class OutputItertator>
void serialize_value_change(OutputItertator oi, VectorValueChangeView vvcv) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("b"sv, oi);
  for(auto value: vvcv.values)
    *oi++ = value_to_char(value);
  ranges::copy(" "sv, oi);
  ranges::copy(vvcv.identifier_code, oi);
  ranges::copy("\n"sv, oi);
}

template<class OutputIterator>
void serialize_value_change(OutputIterator oi, RealValueChangeView rvcv) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("r"sv, oi);
  ranges::copy(std::to_string(rvcv.value), oi);
  ranges::copy(" "sv, oi);
  ranges::copy(rvcv.identifier_code, oi);
  ranges::copy("\n"sv, oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_VALUE_CHANGE_HPP
