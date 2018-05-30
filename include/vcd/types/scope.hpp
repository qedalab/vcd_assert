#ifndef LIBVCD_TYPES_SCOPE_HPP
#define LIBVCD_TYPES_SCOPE_HPP

#include "./enums.hpp"

#include <unordered_map>
#include <string>

namespace VCD {

class VCDScope {
  std::string name_;
  ScopeType type;

  std::unordered_map<std::string, std::size_t> child_scopes_;
  std::unordered_map<std::string, std::size_t> child_variables_;
public:

  bool contains_variable(std::string &name);
  std::size_t get_variable_index(std::string &name);

  bool contains_scope(std::string &name);
  std::size_t get_scope_index(std::string &name);

  std::string_view get_name();
  ScopeType get_scope_type();
};

} // VCD

#endif //LIBVCD_TYPES_SCOPE_HPP
