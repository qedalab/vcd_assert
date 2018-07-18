#ifndef LIBPARSE_UTIL_STATIC_STRING_HPP
#define LIBPARSE_UTIL_STATIC_STRING_HPP

#include <string>
#include <string_view>

#include <range/v3/algorithm/copy.hpp>

namespace Parse::Util {

template <std::size_t Size>
class static_string
{
  char data_[Size] = {};
  static_assert(Size > 0);
  static_assert(sizeof(data_) == Size);

public:
  constexpr static_string(const char(&data)[Size+1]) noexcept
  {
    // Ignores last charcter
    ranges::copy(std::string_view(&data[0], Size), std::begin(data_));
  }

  constexpr std::string_view to_string_view() const noexcept
  {
    return {data_, Size};
  }

  constexpr const char* to_cstr() const noexcept
  {
    return data_;
  }

  std::string to_string() const { return {data_, data_ + Size}; }

  [[nodiscard]] constexpr std::size_t get_size() const noexcept
  {
    return Size;
  };

  constexpr const char *begin() const noexcept { return data_; }

  constexpr const char *end() const noexcept { return data_ + Size; }
};

template <std::size_t Size>
static_string(const char (&)[Size])->static_string<Size - 1>;

template <std::size_t LeftSize, std::size_t RightSize>
constexpr auto operator+(const static_string<LeftSize> &left,
                         const char (&right)[RightSize]) noexcept
{
  constexpr std::size_t NewSize = LeftSize + RightSize;
  char data[NewSize] = {};

  ranges::copy(left.to_string_view(), data);
  ranges::copy(std::string_view(right, RightSize), data + LeftSize);
  data[NewSize - 1] = '\0';

  return static_string(data);
}

template <std::size_t LeftSize, std::size_t RightSize>
constexpr auto operator+(const char (&left)[LeftSize],
                         const static_string<RightSize> &right) noexcept
{
  constexpr std::size_t NewSize = LeftSize + RightSize;
  char data[NewSize] = {};

  ranges::copy(std::string_view(left, LeftSize), data);
  ranges::copy(right.to_string_view(), data + LeftSize - 1);
  data[NewSize - 1] = '\0';

  return static_string(data);
}

template <std::size_t LeftSize, std::size_t RightSize>
constexpr auto operator+(const static_string<LeftSize> left,
                         const static_string<RightSize> right) noexcept
{
  constexpr std::size_t NewSize = LeftSize + RightSize + 1;
  char data[NewSize] = {};

  ranges::copy(left.to_string_view(), data);
  ranges::copy(right.to_string_view(), data + LeftSize);
  data[NewSize - 1] = '\0';

  return static_string(data);
}

} // namespace Parse::Util

#endif // LIBPARSE_UTIL_STATIC_STRING_HPP
