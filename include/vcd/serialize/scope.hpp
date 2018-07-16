#ifndef LIBVCD_SERIALIZE_SCOPE_HPP
#define LIBVCD_SERIALIZE_SCOPE_HPP

#include "../types/scope.hpp"
#include "./enums.hpp"

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

/// Serialize VCD scope
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param scope The scope to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_scope(OutputIterator oi,
                     ScopeDataView ts) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("$scope "), oi);
  ranges::copy(scope_type_to_string(ts.type), oi);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(ts.identifier, oi);
  ranges::copy(std::string_view(" $end\n"), oi);
}

/// Serialize VCD upscope
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_upscope(OutputIterator oi) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("$upscope $end\n"), oi);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_SCOPE_HPP
