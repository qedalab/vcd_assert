#ifndef LIBVCD_SERIALIZE_TIME_SCALE_HPP
#define LIBVCD_SERIALIZE_TIME_SCALE_HPP

#include "../types/time_scale.hpp"
#include "./enums.hpp"

#include <range/v3/algorithm/copy.hpp>

namespace VCD {

template<class OutputIterator>
void serialize_time_scale(OutputIterator oi, TimeScale ts) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("$timescale "sv, oi);
  ranges::copy(time_number_to_string(ts.get_number()), oi);
  ranges::copy(time_unit_to_string(ts.get_unit()), oi);
  ranges::copy(" $end\n"sv, oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_TIME_SCALE_HPP
