#ifndef LIBVCD_SERIALIZE_DATE_HPP
#define LIBVCD_SERIALIZE_DATE_HPP

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

template<class OutputIterator>
void serialize_date(OutputIterator oi, std::string_view date) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("$date "sv, oi);
  ranges::copy(date, oi);
  ranges::copy(" $end\n"sv, oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_DATE_HPP
