// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

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
