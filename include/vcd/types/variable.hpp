#ifndef LIBVCD_TYPES_VARIABLE_HPP
#define LIBVCD_TYPES_VARIABLE_HPP

#include "./enums.hpp"

#include <string>

namespace VCD {

class VCDVariable {
  std::string name_;
  std::string reference_;
  VarType type_;

public:
  VCDVariable(std::string name, VarType type);

  std::string_view get_name();
  std::string_view get_reference();
  VarType get_type();
};

} // namespace

#endif //LIBVCD_TYPES_VARIABLE_HPP
