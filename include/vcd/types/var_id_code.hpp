#ifndef PARSE_VCD_TYPES_VARIABLE_IDENTIFIER_CODE_HPP
#define PARSE_VCD_TYPES_VARIABLE_IDENTIFIER_CODE_HPP

#include "./enums.hpp"

#include <string>
#include <cstddef>

namespace VCD {

class VarIdCode {
  VarType type_;
  std::size_t size_;
  std::string id_code_;

public:
  VarIdCode(VarType type, std::size_t size,
      std::string identifier_code);

  std::string_view get_id_code();
  VarType get_type();
  std::size_t get_size();
};

} // namespace VCD

#endif //PARSE_VCD_TYPES_VARIABLE_IDENTIFIER_CODE_HPP
