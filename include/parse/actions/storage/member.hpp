#ifndef LIBPARSE_ACTIONS_STORAGE_MEMBER_HPP
#define LIBPARSE_ACTIONS_STORAGE_MEMBER_HPP

#include <utility>

#include "../../internal/dependant_value.hpp"

namespace Parse::Storage {

template <auto Invalid>
struct member {
  static_assert(Parse::Internal::dependant_value<false, decltype(Invalid)>,
                "Not a class member");
};

template <class Class, class Type, Type Class::*Member>
struct member<Member> {
  static bool store(Class &parent, Type child) {
    parent.*Member = std::move(child);
    return true;
  }
};

} // namespace Parse::Storage

#endif // LIBPARSE_ACTIONS_STORAGE_MEMBER_HPP
