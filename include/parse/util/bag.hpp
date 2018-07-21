#ifndef LIBPARSE_UTIL_BAG_HPP
#define LIBPARSE_UTIL_BAG_HPP

#include <vector>

namespace Parse::Util {

template <typename T>
class Bag
{
public:
  using index_t = std::size_t;

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
  T &operator[](index_t index) noexcept { return storage_[index]; }

  T &operator[](index_t index) const noexcept { return storage_[index]; }

  bool is_empty() const noexcept {}

  // Get item with exception
  T &at(index_t index) { return storage_.at(index); }

  T &at(index_t index) const { return storage_.at(index); }

  void insert(T &&t) { storage_.emplace_back(t); }

  void insert(const T &t) { storage_.emplace_back(t); }

  void remove(index_t index) noexcept
  {
    storage_[index] = std::move(storage_.back());
    storage_.pop_back();
  }

  void remove(T *pointer) noexcept
  {
    auto index = pointer - begin();
    remove(index);
  };

  // Make range
  T *begin() { return storage_.begin(); }

  T *end() { return storage_.end(); }

private:
  std::vector<T> storage_;
};

}; // namespace Parse::Util

#endif // namespace LIBPARSE_UTIL_BAG_HPP
