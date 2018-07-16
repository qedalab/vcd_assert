#ifndef LIBVCD_SERIALIZE_TIME_SCALE_HPP
#define LIBVCD_SERIALIZE_TIME_SCALE_HPP

#include "../types/time_scale.hpp"
#include "./enums.hpp"

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

/// Serialize VCD time scale
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param ts The time scale to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_time_scale(OutputIterator oi,
                          TimeScale ts) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("$timescale "), oi);
  ranges::copy(time_number_to_string(ts.get_number()), oi);
  ranges::copy(time_unit_to_string(ts.get_unit()), oi);
  ranges::copy(std::string_view(" $end\n"), oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_TIME_SCALE_HPP
