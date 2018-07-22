#ifndef LIBPARSE_UTIL_BAG_HPP
#define LIBPARSE_UTIL_BAG_HPP

#include <cassert>
#include <vector>

#include <range/v3/span.hpp>

namespace Parse::Util {

template <typename T>
class Bag
{
public:
  using index_t = std::size_t;

  // Default constructable
  Bag() = default;

  // Moveable
  Bag(Bag<T> &&other) noexcept { storage_ = std::move(other.storage_); }

  Bag<T> &operator=(Bag<T> &&other) noexcept
  {
    storage_ = std::move(other.storage_);
    return *this;
  }

  // Not copyable by accident
  Bag(const Bag<T> &other) = delete;
  Bag<T> &operator=(const Bag<T> &other) = delete;

  // Copyable by clone only
  Bag<T> clone() const
  {
    Bag<T> tmp;
    tmp.storage_ = storage_;
    return tmp;
  }

  // Get item
  T &operator[](index_t index) noexcept
  {
    assert(index < get_size());
    return storage_[index];
  }

  T &operator[](index_t index) const noexcept
  {
    assert(index < get_size());
    return storage_[index];
  }

  bool is_empty() const noexcept { return storage_.empty(); }

  auto get_size() const noexcept { return storage_.size(); }

  void insert(T &&t) { storage_.emplace_back(std::forward<T>(t)); }

  void insert(const T &t) { storage_.emplace_back(t); }

  void remove(index_t index) noexcept
  {
    storage_[index] = std::move(storage_.back());
    storage_.pop_back();
  }

  void remove(T *pointer) noexcept
  {
    auto index = pointer - std::addressof(storage_.front());
    remove(index);
  };

  auto as_range() {
    return ranges::span(storage_);
  }

private:
  std::vector<T> storage_;
};

} // namespace Parse::Util

#endif // namespace LIBPARSE_UTIL_BAG_HPP
