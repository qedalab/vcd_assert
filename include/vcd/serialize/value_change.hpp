#ifndef LIBVCD_SERIALIZE_VALUE_CHANGE_HPP
#define LIBVCD_SERIALIZE_VALUE_CHANGE_HPP

#include "../types/value_change.hpp"
#include "./enums.hpp"

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

/// Serialize VCD scalar value change
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param svcv The scalar value change to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_value_change(
    OutputIterator oi,
    ScalarValueChangeView svcv) noexcept(noexcept(*oi++ = '!')) {
  *oi++ = value_to_char(svcv.value);
  ranges::copy(svcv.identifier_code, oi);
  ranges::copy(std::string_view("\n"), oi);
}

/// Serialize VCD vector value change
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param vvcv The vector value change to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputItertator>
void serialize_value_change(OutputItertator oi,
                            VectorValueChangeView vvcv) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("b"), oi);
  for (auto value : vvcv.values)
    *oi++ = value_to_char(value);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(vvcv.identifier_code, oi);
  ranges::copy(std::string_view("\n"), oi);
}

/// Serialize VCD real value change
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param rvcv The vector value change to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_value_change(OutputIterator oi,
                            RealValueChangeView rvcv) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("r"), oi);
  ranges::copy(std::to_string(rvcv.value), oi);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(rvcv.identifier_code, oi);
  ranges::copy(std::string_view("\n"), oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_VALUE_CHANGE_HPP
