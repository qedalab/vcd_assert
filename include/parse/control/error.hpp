#ifndef LIBPARSE_CONTROL_ERROR_HPP
#define LIBPARSE_CONTROL_ERROR_HPP

#include "../internal/detected.h"
#include <stdexcept>

#include <tao/pegtl/internal/demangle.hpp>
#include <tao/pegtl/normal.hpp>

namespace Parse {

namespace Internal {
  template<class T>
  using member_error_decl = decltype(T::error());
}

template<class Rule>
struct error_control : public tao::pegtl::normal<Rule> {
  template <typename Input, typename... States>
  static void raise(const Input &in, States &&... /*unused*/) {
    // throw ParseException(Rule::error(), in.position()));
    constexpr bool has_error = Internal::is_detected<Internal::member_error_decl, Rule>;
    if constexpr (has_error) {
      throw std::runtime_error(Rule::error());
    } else {
      throw std::runtime_error("Failed parsing Rule without error: " + tao::pegtl::internal::demangle<Rule>());
    }
  }
};

}

#endif //PARSE_ERROR_HPP
