#ifndef LIBVCD_SERIALIZE_SIMULATION_TIME_HPP
#define LIBVCD_SERIALIZE_SIMULATION_TIME_HPP

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

#include <cstdint>

namespace VCD {

/// Serialize VCD simulation time
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param time The simulation time to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_simulation_time(OutputIterator oi, std::size_t time) noexcept(
    noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("#"sv, oi);
  ranges::copy(std::to_string(time), oi);
  ranges::copy("\n"sv, oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_SIMULATION_TIME_HPP
