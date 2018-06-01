#include "parse/input/cstring.h"

#include <cstring>
#include <algorithm>

using namespace Parse;

CStringInput::CStringInput(const char *str) {
  size_ = std::strlen(str);
  data_ = std::move(std::make_unique<char[]>(size_));
  std::copy_n(str, size_, data_.get());
}

const char *CStringInput::data() const noexcept { return data_.get(); }

size_t CStringInput::size() const noexcept { return size_; }

std::string_view CStringInput::source() const noexcept { return "cstring"; }
