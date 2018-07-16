#ifndef LIBVCD_SERIALIZE_DATE_HPP
#define LIBVCD_SERIALIZE_DATE_HPP

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

/// Serialize VCD date
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param date The date to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_date(OutputIterator oi,
                    std::string_view date) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("$date "), oi);
  ranges::copy(date, oi);
  ranges::copy(std::string_view(" $end\n"), oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_DATE_HPP
