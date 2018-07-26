
#include <cassert>
#include <verilog/types/design_reader.hpp>

using namespace Verilog;

// const Variable &Design::get_var(std::size_t index) const
// {
//   assert(variables_.size() > index);
//   return variables_.at(index);
// }

// const Net &Design::get_net(std::size_t index) const
// {
//   assert(nets_.size() > index);
//   return nets_.at(index);
// }

// const Net &Design::get_root_net() const
// {
//   assert(!nets_.empty());
//   return nets_.at(0);
// }

std::optional<std::size_t> Design::module_find(std::string module_identifier) const
{
  assert(!module_lookup_.empty()); 
  auto search = module_lookup_.find(module_identifier);
  if(search != module_lookup_.end()){  
    return module_lookup_.at(module_identifier);
  }else{
    return {};
  }
}

const Module &Design::get_module(std::size_t  index) const
{
  assert(!modules_.empty());
  assert(modules_.size() > index);
  return modules_.at(index);
}

const Instance &Design::get_instance(std::size_t index) const
{ 
   assert(instances_.size() > index);
  return instances_.at(index);
}

// std::size_t Design::num_nets() const noexcept { return nets_.size(); }

// std::size_t Design::num_variables() const noexcept { return variables_.size(); }


std::size_t Design::num_modules() const noexcept { return modules_.size(); }

std::size_t Design::num_instances() const noexcept { return instances_.size(); }