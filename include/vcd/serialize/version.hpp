#ifndef LIBVCD_SERIALIZE_VERSION_HPP
#define LIBVCD_SERIALIZE_VERSION_HPP

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

template<class OutputIterator>
void serialize_version(OutputIterator oi, std::string_view version) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("$version "sv, oi);
  ranges::copy(version, oi);
  ranges::copy(" $end\n"sv, oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_VERSION_HPP
