#ifndef LIBVCD_TYPES_VARIABLE_IDENTIFIER_CODE_HPP
#define LIBVCD_TYPES_VARIABLE_IDENTIFIER_CODE_HPP

#include "./enums.hpp"

#include <cstddef>
#include <string>

namespace VCD {

/// Immutable variable identifier code object
/// \todo Ensure identifier code correctness
class VarIdCode {
  VarType type_;        /// Variable type
  std::size_t size_;    /// Variable size
  std::string id_code_; /// Variable identifier code

public:
  /// Variable identifier code constructor
  /// \param type The variable type
  /// \param size The variable size
  /// \param identifier_code The variable identifier code
  /// \todo ensure identifier code correctness
  VarIdCode(VarType type, std::size_t size,
      std::string identifier_code) noexcept;

  /// Get the variable identifier code
  /// \returns View of identifier code string
  std::string_view get_id_code() const noexcept;

  /// Get the variable type
  /// \returns The varable type
  VarType get_type() const noexcept;

  /// Get the variable size
  /// \returns The variable size
  std::size_t get_size() const noexcept;
};

} // namespace VCD

#endif //LIBVCD_TYPES_VARIABLE_IDENTIFIER_CODE_HPP
