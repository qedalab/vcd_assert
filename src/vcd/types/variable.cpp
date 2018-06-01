#include "vcd/types/variable.hpp"

using namespace VCD;

VCDVariable::VCDVariable(VCD::VarType type, std::size_t size,
                         std::string name, std::string reference) :
  type_(type),
  size_(size),
  name_(std::move(name)),
  reference_(std::move(reference))
{
  // Empty
}

VarType VCDVariable::get_type()
{
  return type_;
}

std::size_t VCDVariable::get_size()
{
  return size_;
}

std::string_view VCDVariable::get_name()
{
  return name_;
}

std::string_view VCDVariable::get_reference()
{
  return reference_;
}
