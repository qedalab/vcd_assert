#include "vcd/types/variable.hpp"

using namespace VCD;

Variable::Variable(std::size_t id_code, std::string reference) :
  id_code_(id_code),
  ref_(std::move(reference))
{
  // Empty
}

std::size_t Variable::get_id_code_index()
{
  return id_code_;
}

std::string_view Variable::get_reference()
{
  return ref_;
}
