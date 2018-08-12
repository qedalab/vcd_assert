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

#include "verilog/types/design_reader.hpp"

#include "parse/util/dependent_value.hpp"
#include <cassert>

using namespace Verilog;

DesignReader::DesignReader() { design_ = std::make_unique<Design>(); }

// void DesignReader::merge(std::unique_ptr<DesignReader> other)
void DesignReader::merge(DesignReader other)
{

  /* TODO : Revise file name list merge */
  // std::vector<std::string> file_names_;      /// File Names

  /// 'module index' <-> 'file index' lookup
  // std::unordered_map<std::size_t, std::size_t> file_name_lookup_;

  // for(auto &&new_file_name : new_reader.design_->file_names_){
  //   bool found = false;
  //   for(auto &&cur_file_name : file_names_){
  //     if(ranges::equal(cur_file_name, new_file_name){
  //       found = true;
  //     }
  //   }
  //   if(!found){
  //     file_names_.push_back(new_file_name);
  //   }
  //   if(!cur_file_name.contains(new_file_name)){
  //     module_index += 1;
  //     design_->modules_.emplace_back(new_module);
  //     design_->module_lookup_.insert(new_module.identifier_, module_index);
  //   }else{
  //     auto existing = module_lookup_.get(new_module.identifier_);
  //     throw std::runtime_error(fmt::format("Module {} multiply defined! First
  //     defined in ({}) and then again in ({})!", existing.file_path_,
  //     new_module.file_path));
  //   }
  // }

  Parse::Util::debug_puts("DEBUG: merging DesignReader");
  auto instance_index = design_->instances_.size();

  for (auto &&new_module : other.design_->modules_) {
    auto module_index = design_->modules_.size();

    // if module not previously defined
    auto search = design_->module_lookup_.find(new_module.identifier);
    if (search == design_->module_lookup_.end()) {

      for (auto &&[key, value] : new_module.instance_lookup_) {
        new_module.instance_lookup_[key] = value + instance_index;
      }

      // order is important
      design_->module_lookup_.emplace(new_module.identifier, module_index);
      design_->modules_.emplace_back(std::move(new_module));

    } else {
      auto found =
          design_->modules_[design_->module_lookup_[new_module.identifier]];
      throw std::runtime_error(
          fmt::format("Module {} multiply defined! First defined in ({}) and "
                      "then again in ({})!",
                      found.file_path, new_module.file_path));
    }
  }

  for (auto &&new_instance : other.design_->instances_) {
    design_->instances_.emplace_back(std::move(new_instance));
  }
}

std::size_t DesignReader::module(std::string module_name, std::string file_path)
{

  Parse::Util::debug_print("DEBUG: module_name : {}\n", module_name);
  Parse::Util::debug_print("DEBUG: file_path : {}\n", file_path);

  // index to store at.
  auto module_index = design_->modules_.size();

  // check that module not already defined
  auto search = design_->module_lookup_.find(module_name);
  if (search == design_->module_lookup_.end()) { // IF NOT FOUND > INSERT

    design_->modules_.emplace_back(Module{module_name, file_path, {}});

    design_->module_lookup_.emplace(module_name, module_index);
    return (module_index);

  } else {

    auto found = design_->modules_[design_->module_lookup_[module_name]];
    throw std::runtime_error(
        fmt::format("Module {} multiply defined! Already defined in ({}) !",
                    found.file_path));
  }
}

bool DesignReader::next_module()
{
  Parse::Util::debug_puts("DEBUG: old current module index: ({})",current_module_index_);
  if (current_module_index_ < (design_->modules_.size() - 1)) {
    current_module_index_++;
    Parse::Util::debug_puts("DEBUG: new current module index: ({})",current_module_index_);
    return true;
  } else {
    current_module_index_ = 0;
    Parse::Util::debug_puts("DEBUG: new current module index: ({})",current_module_index_);
    return false;
  }

}

/*  NO LONGER Assumes that the origin of the instantiation is the
    last elem in collection corresponding to the NetType (modules_).
    INSTEAD, Since instance are found in parsing second pass the
    module name is used to look up the index in modules_ of
    the source module where the instantiation occurred. */
std::size_t DesignReader::instance(NetType type,
                                   std::string instance_name,
                                   std::string definition_name)
{
  Parse::Util::debug_puts("DEBUG: found instance :");

  Parse::Util::debug_print("DEBUG: instance_name : {}\n", instance_name);
  Parse::Util::debug_print("DEBUG: definition_name : {}\n", definition_name);
  // only support module type at the moment
  if (type != NetType::module) {
    throw std::runtime_error("InternalError : unsupported net definition type");
  }

  // Check that instance type has been defined.
  auto search = design_->module_lookup_.find(definition_name);
  if (search != design_->module_lookup_.end()) {

    // get index to definition
    auto definition_index = design_->module_lookup_[definition_name];
    auto new_instance_index = design_->instances_.size();

    // auto current_module_index = design_->module_lookup_[current_module_name];

    // create name->index lookup for instance inside design;
    // design_->instances_module_lookup_.insert({instance_name,instances_.size()})

    design_->instances_.push_back({type, // todo remove
                                   instance_name, definition_index});

    // INSERT INSTANCE INDEX INTO MODULE
    Parse::Util::debug_print("DEBUG: insert instance idx into module w idx : {}\n", current_module_index_);

    design_->modules_.at(current_module_index_)
        .instance_lookup_.emplace(instance_name, new_instance_index);

    return new_instance_index;

  } else {
    throw std::runtime_error(
        fmt::format("Declaration of {} not found.", definition_name));
  }
}

std::size_t DesignReader::command(Command command)
{
  Parse::Util::debug_puts("DEBUG: found command :");

  if (std::holds_alternative<SDFAnnotateCommand>(command)) {
    auto sdf = std::get<SDFAnnotateCommand>(command);
    Parse::Util::debug_puts("DEBUG: SDF annotate command");

    // check if sdf_annotate applies to this scope or a child scope.
    // auto apply_scope = sdf.name_of_instance.has_value()
    //                        ? sdf.name_of_instance.value()
    //                        : definition_name;

    auto apply_scope_index = 0;

    // find apply scope.
    if (sdf.name_of_instance.has_value()) {
      auto apply_scope = sdf.name_of_instance.value();
      auto search = design_->module_lookup_.find(apply_scope);
      if (search != design_->module_lookup_.end()) {
        apply_scope_index = design_->module_lookup_.at(apply_scope);
        Parse::Util::debug_print("DEBUG: apply SDF to scope : {}\n", apply_scope);
      } else {
        throw std::runtime_error(fmt::format(
            "SDFAnnotationError : Module/Scope ({}) not found.", apply_scope));
      }
    } else {
      Parse::Util::debug_print("DEBUG: apply SDF to current scope");
      apply_scope_index = current_module_index_;
    }


    // add command.
    auto sdf_index_it = design_->sdf_commands_lookup_.find(apply_scope_index);
    if (sdf_index_it != design_->sdf_commands_lookup_.end()) {

      Parse::Util::debug_print("DEBUG: apply scope index : {}\n",
                                sdf_index_it->second);

      design_->sdf_commands_.at(sdf_index_it->second).push_back(sdf);

      return sdf_index_it->second;
    } else {

      auto new_sdf_index = design_->sdf_commands_.size();
      design_->sdf_commands_.push_back({sdf});

      design_->sdf_commands_lookup_.emplace(apply_scope_index, new_sdf_index);

      design_->sdf_commands_reverse_lookup_.emplace(new_sdf_index,
                                                    apply_scope_index);

      return new_sdf_index;
    }

  
  } else {
    throw std::runtime_error("InternalError : command not supported");
  }
}

std::unique_ptr<Design> DesignReader::release()
{
  return std::move(design_);
}
