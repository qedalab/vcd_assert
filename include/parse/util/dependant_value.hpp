#ifndef LIBPARSE_UTIL_DEPENDANT_VALUE_HPP
#define LIBPARSE_UTIL_DEPENDANT_VALUE_HPP

namespace Parse::Util {

template <auto Value, typename... Args>
constexpr auto dependant_value = Value;

} // namespace Parse::Util

#endif // LIBPARSE_UTIL_DEPENDANT_VALUE_HPP
