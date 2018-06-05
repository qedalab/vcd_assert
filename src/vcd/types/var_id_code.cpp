#include "vcd/types/var_id_code.hpp"

using namespace VCD;

VarIdCode::VarIdCode(VarType type, std::size_t size, std::string identifier_code) :
  type_(type),
  size_(size),
  id_code_(identifier_code)
{
  // Empty
}

std::string_view VarIdCode::get_id_code()
{
  return id_code_;
}

VarType VarIdCode::get_type()
{
  return type_;
}

std::size_t VarIdCode::get_size()
{
  return size_;
}
