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

#ifndef LIBVCD_TYPES_SCOPE_HPP
#define LIBVCD_TYPES_SCOPE_HPP

#include "./enums.hpp"

#include <range/v3/view/all.hpp>

#include <string>
#include <unordered_map>

namespace VCD {

/// View of scope data
/// \todo Ensure identifier correctness
struct ScopeDataView {
  ScopeType type = ScopeType::begin;
  std::string_view identifier;
};

/// VCD Scope object
/// This object is defined in terms of the Header it is contained in and can
/// therefore only be populated alongside the Header with HeaderReader
/// \related HeaderReader
class Scope {
  ScopeType type_;         /// The scope type
  std::string identifier_; /// The scope identifier

  /// Child scopes
  std::unordered_map<std::string, std::size_t> child_scopes_;

  /// Child variables
  std::unordered_map<std::string, std::size_t> child_variables_;

  friend class HeaderReader;
public:
  /// The scope constructor
  /// \todo Ensure identifier correctness
  /// \param type The scope type
  /// \param identifier The identifier string
  /// \todo ensure identifier correctness
  Scope(ScopeType type, std::string identifier) noexcept;

  /// True if the scope directly contains the variable reference
  /// \param reference The variable reference
  /// \returns Wether the scope directly contains the variable reference
  bool contains_variable(std::string &reference) const noexcept;

  /// Get the variable index by reference
  /// \param reference The variable reference
  /// \returns The variable index
  std::size_t get_variable_index(std::string &reference) const;

  /// Number of variables directly in this scope
  /// \returns The number of variables directly in this scope
  std::size_t num_variables() const noexcept;

  /// True if the scope directly contains the scope
  /// \param identifier The child scope identifier
  /// \returns Wether the scope directly contains \p identifier
  bool contains_scope(std::string &identifier) const noexcept;

  /// Get scope index by identifierthis
  /// \param identifier The child scope identifier
  /// \returns The scope index from \p identifier
  std::size_t get_scope_index(std::string &identifier) const;

  /// Returns the number of direct scopes within this scope
  /// \returns The number of direct scopes within this scope
  std::size_t num_scopes() const noexcept;

  /// Returns a range of identifier-index pairs of the scopes
  /// \returns identifier-index pairs range
  /// \TODO Make and use identifier-index range
  auto get_scopes() const -> decltype(ranges::view::all(this->child_scopes_));

  /// Returns a range of identifier-index pairs of the variables
  /// \returns identifier-index pairs range
  /// \TODO Make and use identifier-index range
  auto get_variables() const -> decltype(ranges::view::all(this->child_variables_));

  /// Get scope identifier
  /// \returns View of identifier string
  std::string_view get_identifier() const noexcept;

  /// Get scope type
  /// \returns The scope type
  ScopeType get_scope_type() const noexcept;

  /// Convert to ScopeDataView
  /// \returns ScopeDataView of Scope
  operator ScopeDataView() const noexcept;
};

} // VCD

#endif //LIBVCD_TYPES_SCOPE_HPP
