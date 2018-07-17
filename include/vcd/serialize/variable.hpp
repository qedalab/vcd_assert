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
  ranges::copy(std::string_view("$var "), oi);
  ranges::copy(var_type_to_string(vv.type), oi);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(std::to_string(vv.size), oi);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(vv.identifier_code, oi);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(vv.reference, oi);
  ranges::copy(std::string_view(" $end\n"), oi);
}

} // namespace VCD

#endif //LIBVCD_SERIALIZE_VARIABLE_HPP
