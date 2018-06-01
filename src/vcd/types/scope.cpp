#include "vcd/types/scope.hpp"

#include <cassert>

using namespace VCD;

VCDScope::VCDScope(VCD::ScopeType type, std::string name) :
  type_(type),
  name_(std::move(name))
{
  // Nothing
}

bool VCDScope::contains_variable(std::string &name)
{
  return child_variables_.count(name) > 0;
}

std::size_t VCDScope::get_variable_index(std::string &name)
{
  assert(contains_variable(name));
  return child_variables_.at(name);
}

bool VCDScope::contains_scope(std::string &name)
{
  return child_scopes_.count(name) > 0;
}

std::size_t VCDScope::get_scope_index(std::string &name)
{
  assert(contains_scope(name));
  return child_scopes_.at(name);
}

std::string_view VCDScope::get_name()
{
  return name_;
}

ScopeType VCDScope::get_scope_type()
{
  return type_;
}