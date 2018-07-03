#include "vcd/types/scope.hpp"

#include <cassert>

using namespace VCD;

Scope::Scope(VCD::ScopeType type, std::string identifier) noexcept :
    type_(type),
    identifier_(std::move(identifier)) {}

bool Scope::contains_variable(std::string &reference) const noexcept
{
  return child_variables_.count(reference) > 0;
}

std::size_t Scope::get_variable_index(std::string &reference) const
{
  assert(contains_variable(reference));
  return child_variables_.at(reference);
}

std::size_t Scope::num_variables() const noexcept
{
  return child_variables_.size();
}

bool Scope::contains_scope(std::string &identifier) const noexcept
{
  return child_scopes_.count(identifier) > 0;
}

std::size_t Scope::get_scope_index(std::string &identifier) const
{
  assert(contains_scope(identifier));
  return child_scopes_.at(identifier);
}

std::size_t Scope::num_scopes() const noexcept
{
  return child_scopes_.size();
}

std::string_view Scope::get_identifier() const noexcept
{
  return identifier_;
}

ScopeType Scope::get_scope_type() const noexcept
{
  return type_;
}

Scope::operator ScopeDataView() const noexcept {
  return {
    .type = type_,
    .identifier = identifier_
  };
}
