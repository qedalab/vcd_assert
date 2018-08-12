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
  assert(sdf_commands_reverse_lookup_.size() > sdf_set_index);
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
