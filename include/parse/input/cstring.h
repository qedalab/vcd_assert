#ifndef LIBPARSE_INPUT_CSTRING_H
#define LIBPARSE_INPUT_CSTRING_H

#include <memory>
#include <string_view>

namespace Parse {

struct CStringInput {
  std::unique_ptr<char[]> data_;
  size_t size_;

public:
  explicit CStringInput(const char *str);

  const char *data() const noexcept;
  size_t size() const noexcept;
  std::string_view source() const noexcept;
};

} // namespace Parse

#endif // LIBPARSE_CSTRING_H
