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

#ifndef LIBVCD_TYPES_VARIABLE_HPP
#define LIBVCD_TYPES_VARIABLE_HPP

#include "./enums.hpp"

#include <string>
#include <string_view>

#include <cstddef>

namespace VCD {

/// View of Variable
struct VariableView {
  VarType type = VarType::reg;      /// Variable type
  std::size_t size = 0;             /// Variable size
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
