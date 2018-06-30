#ifndef LIBPARSE_ACTIONS_STORAGE_FUNCTION_HPP
#define LIBPARSE_ACTIONS_STORAGE_FUNCTION_HPP

#include <utility>

#include "parse/util/dependant_value.hpp"

namespace Parse::Storage {

template <auto Invalid>
struct function {
  static_assert(Parse::Util::dependant_value<false, decltype(Invalid)>,
                "Not a class member function");
};

template <class Class, class Type, class Return, Return (Class::*Member)(Type)>
struct function<Member> {
  static bool store(Class &parent, Type child) {
    (parent.*Member)(std::move(child));
    return true;
  }
};

} // namespace Parse::Storage

#endif // LIBPARSE_ACTIONS_STORAGE_FUNCTION_HPP
