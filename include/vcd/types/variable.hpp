#ifndef LIBVCD_TYPES_VARIABLE_HPP
#define LIBVCD_TYPES_VARIABLE_HPP

#include "./enums.hpp"

#include <string>
#include <string_view>

#include <cstddef>

namespace VCD {

/// View of Variable
struct VariableView {
  VarType type;                     /// Variable type
  std::size_t size;                 /// Variable size
  std::string_view identifier_code; /// Variable identifier code
  std::string_view reference;       /// Variable reference
};

/// Immutable variable object
class Variable {
  std::size_t id_code_; /// Variable identifier code index
  std::string ref_;     /// Variable reference

public:
  /// Variable constructor
  /// \param id_code The variable identifier code index
  /// \param reference The variable reference
  Variable(std::size_t id_code, std::string reference) noexcept;

  /// Get the variable identifier code index
  /// \returns The variable identifier code index
  std::size_t get_id_code_index() const noexcept;

  /// Get the variable reference index
  /// \returns View of the variable reference string
  std::string_view get_reference() const noexcept;
};

} // namespace

#endif //LIBVCD_TYPES_VARIABLE_HPP
