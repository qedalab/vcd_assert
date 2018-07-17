#ifndef LIBVCD_SERIALIZE_VERSION_HPP
#define LIBVCD_SERIALIZE_VERSION_HPP

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

/// Serialize VCD version
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param version The version to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_version(OutputIterator oi, std::string_view version) noexcept(
    noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("$version "), oi);
  ranges::copy(version, oi);
  ranges::copy(std::string_view(" $end\n"), oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_VERSION_HPP
