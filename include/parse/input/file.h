// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

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
