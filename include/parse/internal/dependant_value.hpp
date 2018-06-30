#ifndef LIBPARSE_INTERNAL_DEPENDANT_VALUE_HPP
#define LIBPARSE_INTERNAL_DEPENDANT_VALUE_HPP

namespace Parse::Internal {

template<auto Value, typename... Args>
constexpr auto dependant_value = Value;

} // namespace Parse::Internal

#endif // LIBPARSE_INTERNAL_DEPENDANT_VALUE_HPP
