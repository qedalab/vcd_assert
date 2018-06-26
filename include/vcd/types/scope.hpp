#ifndef LIBVCD_TYPES_SCOPE_HPP
#define LIBVCD_TYPES_SCOPE_HPP

#include "./enums.hpp"

#include <unordered_map>
#include <string>

namespace VCD {

struct ScopeDataView {
  ScopeType type;
  std::string_view identifier;
};

class Scope {
  ScopeType type_;
  std::string identifier_;

  std::unordered_map<std::string, std::size_t> child_scopes_;
  std::unordered_map<std::string, std::size_t> child_variables_;

  friend class HeaderReader;
public:
  Scope(ScopeType type, std::string identifier);

  bool contains_variable(std::string &reference);
  std::size_t get_variable_index(std::string &reference);
  std::size_t num_variables();

  bool contains_scope(std::string &identifier);
  std::size_t get_scope_index(std::string &identifier);
  std::size_t num_scopes();

  std::string_view get_identifier();
  ScopeType get_scope_type();

  operator ScopeDataView() const noexcept;
};

} // VCD

#endif //LIBVCD_TYPES_SCOPE_HPP
