#ifndef LIBVCD_SERIALIZE_SCOPE_HPP
#define LIBVCD_SERIALIZE_SCOPE_HPP

#include "../types/scope.hpp"
#include "./enums.hpp"

#include <range/v3/algorithm/copy.hpp>

namespace VCD {

template<class OutputIterator>
void serialize_scope(OutputIterator oi, ScopeDataView ts) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("$scope "sv, oi);
  ranges::copy(scope_type_to_string(ts.type), oi);
  ranges::copy(" "sv, oi);
  ranges::copy(ts.identifier, oi);
  ranges::copy(" $end\n"sv, oi);
}

template<class OutputIterator>
void serialize_upscope(OutputIterator oi, ScopeDataView ts) {
  using std::literals::string_view_literals::operator""sv;
  ranges::copy("$upscope $end\n"sv);
}

} // namespace VCD

#endif // LIBVCD_SERIALIZE_SCOPE_HPP
