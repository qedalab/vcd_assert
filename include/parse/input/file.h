#ifndef PARSE_INPUT_FILE_H_
#define PARSE_INPUT_FILE_H_

#include <fstream>
#include <memory>
#include <string_view>

namespace Parse {
class FileInput
{
  std::unique_ptr<char[]> data_;
  size_t size_;
  std::string source_;

public:
  /// Constructs FileInput from object that can be used as a path
  template <typename FilePath>
  FileInput(FilePath path) : source_(path) {
    std::ifstream f;
    f.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    f.open(path, std::ios::binary);

    f.seekg(0, std::ios::end);
    size_ = f.tellg();
    data_ = std::make_unique<char[]>(size_);

    f.seekg(0, std::ios::beg);
    f.read(data_.get(), size_);
  }

  const char *data() const noexcept;
  size_t size() const noexcept;
  std::string_view source() const noexcept;
};
} // namespace Parse

#endif // PARSE_BASE_H_
