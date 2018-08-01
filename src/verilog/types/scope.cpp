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

// #include "verilog/types/scope.hpp"

// #include <cassert>

// using namespace Verilog;

// Scope::Scope(Verilog::ScopeType type, std::string identifier) noexcept :
//     type_(type),
//     identifier_(std::move(identifier))
// {
//   // Empty
// }

// bool Scope::contains_variable(std::string &reference) const noexcept
// {
//   return child_variables_.count(reference) > 0;
// }

// std::size_t Scope::get_variable_index(std::string &reference) const
// {
//   assert(contains_variable(reference));
//   return child_variables_.at(reference);
// }

// std::size_t Scope::num_variables() const noexcept
// {
//   return child_variables_.size();
// }

// bool Scope::contains_scope(std::string &identifier) const noexcept
// {
//   return child_scopes_.count(identifier) > 0;
// }

// std::size_t Scope::get_scope_index(std::string &identifier) const
// {
//   assert(contains_scope(identifier));
//   return child_scopes_.at(identifier);
// }

// std::size_t Scope::num_scopes() const noexcept { return child_scopes_.size(); }

// auto Scope::get_scopes() const -> decltype(ranges::view::all(this->child_scopes_))
// {
//   return ranges::view::all(this->child_scopes_);
// }

// auto Scope::get_variables() const
//     -> decltype(ranges::view::all(this->child_variables_))
// {
//   return ranges::view::all(this->child_variables_);
// }

// std::string_view Scope::get_identifier() const noexcept { return identifier_; }

// ScopeType Scope::get_scope_type() const noexcept { return type_; }

// Scope::operator ScopeDataView() const noexcept { return {type_, identifier_}; }
