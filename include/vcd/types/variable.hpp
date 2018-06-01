#ifndef LIBVCD_TYPES_VARIABLE_HPP
#define LIBVCD_TYPES_VARIABLE_HPP

#include "./enums.hpp"

#include <string>

namespace VCD {

class VCDVariable {
  VarType type_;
  std::size_t size_;
  std::string name_;
  std::string reference_;

public:
  VCDVariable(VarType type, std::size_t size,
              std::string name, std::string reference);

  VarType get_type();
  std::size_t get_size();
  std::string_view get_name();
  std::string_view get_reference();
};

} // namespace

#endif //LIBVCD_TYPES_VARIABLE_HPP
