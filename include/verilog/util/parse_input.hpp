#ifndef LIBVERILOG_UTIL_PARSE_INPUT_HPP
#define LIBVERILOG_UTIL_PARSE_INPUT_HPP

#include <string>
#include <variant>
#include <unordered_map>

namespace Verilog::Util {

enum class InputTypeEnum {
  file,
  const_char_pointer
};

using InputType = std::variant<const char*, std::string>;

struct ParseInput{
  InputTypeEnum type;
  InputType value;
};

using InputMap = std::unordered_map<std::string, ParseInput>;


} // namespace Verilog::Util

#endif // LIBVERILOG_UTIL_PARSE_INPUT_HPP
