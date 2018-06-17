#include "parse/input/memory.h"

using namespace Parse;

const char *MemoryInput::data() const noexcept { return data_.get(); }

size_t MemoryInput::size() const noexcept { return size_; }

std::string_view MemoryInput::source() const noexcept { return "memory"; }
