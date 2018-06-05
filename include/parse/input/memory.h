#ifndef PARSE_INPUT_MEMORY_H_
#define PARSE_INPUT_MEMORY_H_

#include <algorithm>
#include <range/v3/distance.hpp>
#include <string_view>
#include <memory>

namespace Parse {
class MemoryInput {
  std::unique_ptr<char[]> data_;
  size_t size_;

public:
  template <class Range> MemoryInput(Range range) {
    size_ = ranges::distance(range);
    data_ = std::move(std::make_unique<char[]>(size_));
    std::copy_n(range.begin(), size_, data_.get());
  }

  const char *data() const noexcept;
  size_t size() const noexcept;
  std::string_view source() const noexcept;
};
} // namespace Parse

#endif // PARSE_BASE_H_
