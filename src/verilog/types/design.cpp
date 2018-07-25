
#include <cassert>
#include <verilog/types/design_reader.hpp>

using namespace Verilog;

const Variable &Design::get_var(std::size_t index) const
{
  assert(variables_.size() > index);
  return variables_.at(index);
}

const Net &Design::get_net(std::size_t index) const
{
  assert(nets_.size() > index);
  return nets_.at(index);
}

const Net &Design::get_root_net() const
{
  assert(!nets_.empty());
  return nets_.at(0);
}

std::size_t Design::get_var_id_code_index(std::string &id_code) const
{
  assert(has_var_id_code(id_code));
  return var_id_code_map_.get_index(id_code);
}

const VarIdCode &Design::get_var_id_code(std::size_t index) const
{
  assert(index < num_id_codes());
  return id_codes_.at(index);
}

bool Design::has_var_id_code(std::string &id_code) const noexcept
{
  return var_id_code_map_.has_name(id_code);
}

std::size_t Design::num_nets() const noexcept { return nets_.size(); }

std::size_t Design::num_variables() const noexcept { return variables_.size(); }

std::size_t Design::num_id_codes() const noexcept { return id_codes_.size(); }

std::size_t Design::num_modules() const noexcept { return modules_.size(); }

std::size_t Design::num_instances() const noexcept { return instances_.size(); }