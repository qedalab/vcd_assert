#ifndef LIBVCD_SERIALIZE_SIMULATION_TIME_HPP
#define LIBVCD_SERIALIZE_SIMULATION_TIME_HPP

#include <cstdint>
#include <range/v3/algorithm/copy.hpp>

namespace VCD {

template<class OutputIterator>
void serialize_simulation_time(OutputIterator oi, std::size_t time)
{
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("#"sv, oi);
  ranges::copy(std::to_string(time), oi);
  ranges::copy("\n"sv, oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_SIMULATION_TIME_HPP
