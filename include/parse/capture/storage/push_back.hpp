#ifndef LIBPARSE_CAPTURE_STORAGE_PUSH_BACK_HPP
#define LIBPARSE_CAPTURE_STORAGE_PUSH_BACK_HPP

#include <utility>

namespace Parse::Storage {

struct push_back {
  template<class Parent, class Type>
  static bool store(Parent &parent, Type&& child) {
    parent.emplace_back(std::move(child));
    return true;
  }
};

} // namespace Parse::Storage

#endif // LIBPARSE_PUSH_BACK_HPP
