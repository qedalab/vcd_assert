#ifndef LIBVCD_SERIALIZE_VARIABLE_HPP
#define LIBVCD_SERIALIZE_VARIABLE_HPP

#include "../types/variable.hpp"
#include "./enums.hpp"

#include <range/v3/algorithm/copy.hpp>

namespace VCD {

template<class OutputIterator>
void serialize_variable(OutputIterator oi, VariableView vv) {
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