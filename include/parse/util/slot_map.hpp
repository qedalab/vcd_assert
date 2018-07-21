#ifndef LIBPARSE_UTIL_SLOT_MAP_HPP
#define LIBPARSE_UTIL_SLOT_MAP_HPP

#include <vector>

namespace Parse::Util {

template <typename T>
class SlotMap
{
public:
  using index_t = std::size_t;

  // Moveable
  SlotMap(SlotMap<T> &&other) noexcept {
    element_storage_ = std::move(other.element_storage_);
    slot_storage_ = std::move(other.slot_storage_);
  }

  SlotMap<T> &operator=(SlotMap<T> &&other) noexcept {
    element_storage_ = std::move(other.element_storage_);
    slot_storage_ = std::move(other.slot_storage_);
    return *this;
  }

  // Non-Copyable
  SlotMap(const SlotMap<T> &other) = delete;
  SlotMap<T>& operator=(const SlotMap<T> &other) = delete;

  // Cloneable
  SlotMap<T> clone() const {
    SlotMap<T> tmp;
    tmp.element_storage_ = element_storage_;
    tmp.slot_storage_ = slot_storage_;
    return tmp;
  }

  T& operator[](index_t index) noexcept {
    return element_storage_[index];
  }

  T& operator[](index_t index) const noexcept {
    return element_storage_[index];
  }

  std::size_t insert(T&& other) {
    std::size_t index;

    if (slot_storage_.empty()) {
      index = element_storage_.size();
      element_storage_.emplace_back(other);
      return index;
    }

    index = slot_storage_.back();
    slot_storage_.pop_back();
    element_storage_[index] = other;
    return index;
  }

  std::size_t insert(const T& other) {
    std::size_t index;

    if (slot_storage_.empty()) {
      index = element_storage_.size();
      element_storage_.emplace_back(other);
      return index;
    }

    index = slot_storage_.back();
    slot_storage_.pop_back();
    element_storage_[index] = other;
    return index;
  }

  void remove(std::size_t index) {
    slot_storage_[index];
  }

private:
  std::vector<T> element_storage_;
  std::vector<index_t> slot_storage_;
};

} // namespace Parse::Util

#endif // LIPARSE_UTIL_SLOT_MAP_HPP
