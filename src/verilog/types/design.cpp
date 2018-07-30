
#include <cassert>
#include <verilog/types/design_reader.hpp>

using namespace Verilog;

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

const Module &Design::get_module(std::size_t  module_index) const
{
  assert(!modules_.empty());
  assert(modules_.size() > module_index);
  return modules_.at(module_index);
}

const Instance &Design::get_instance(std::size_t instance_index) const
{ 
  assert(instances_.size() > instance_index);
  return instances_.at(instance_index);
}

std::vector<SDFAnnotateCommand>
Design::get_sdf_commands(std::size_t sdf_set_index) const
{ 
  assert(sdf_commands_.size() > sdf_set_index);
  return sdf_commands_.at(sdf_set_index);
}

std::size_t Design::sdf_reverse_lookup(std::size_t sdf_set_index) const
{
  return sdf_commands_reverse_lookup_.at(sdf_set_index);
}

std::optional<std::size_t> Design::sdf_lookup(std::size_t module_index) const
{ 
  assert(modules_.size() > module_index);
  auto search = sdf_commands_lookup_.find(module_index);
  if(search != sdf_commands_lookup_.end()){  
    return sdf_commands_lookup_.at(module_index);
  }else{
    return {};
  }
}



std::size_t Design::num_modules() const noexcept { return modules_.size(); }

std::size_t Design::num_instances() const noexcept { return instances_.size(); }

std::size_t Design::num_sdf_commands() const noexcept { return sdf_commands_.size(); }
