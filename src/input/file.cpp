#include "parse/input/file.h"

using namespace Parse;

const char *FileInput::data() const noexcept { return data_.get(); }

size_t FileInput::size() const noexcept { return size_; }

std::string_view FileInput::source() const noexcept { return source_; }
