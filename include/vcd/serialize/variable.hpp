#ifndef LIBVCD_SERIALIZE_VARIABLE_HPP
#define LIBVCD_SERIALIZE_VARIABLE_HPP

#include "../types/variable.hpp"
#include "./enums.hpp"

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

/// Serialize VCD variable declaration
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param vv The variable to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_variable(OutputIterator oi,
                        VariableView vv) noexcept(noexcept(*oi++ = '!')) {
  using std::literals::string_view_literals::operator""sv;

  ranges::copy("$var "sv, oi);
  ranges::copy(var_type_to_string(vv.type), oi);
  ranges::copy(" "sv, oi);
  ranges::copy(std::to_string(vv.size), oi);
  ranges::copy(" "sv, oi);
  ranges::copy(vv.identifier_code, oi);
  ranges::copy(" "sv, oi);
  ranges::copy(vv.reference, oi);
  ranges::copy(" $end\n"sv, oi);
}

} // namespace VCD

#endif //LIBVCD_SERIALIZE_VARIABLE_HPP