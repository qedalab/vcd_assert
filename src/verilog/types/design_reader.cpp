#include "verilog/types/design_reader.hpp"

#include "parse/util/dependent_value.hpp"
#include <cassert>

using namespace Verilog;

DesignReader::DesignReader() { design_ = std::make_unique<Design>(); }

// void DesignReader::merge(std::unique_ptr<DesignReader> other)
void DesignReader::merge(DesignReader other)
{
  // Files
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

  auto instance_index = design_->instances_.size();

  for (auto &&new_module : other.design_->modules_) {
    auto module_index = design_->modules_.size();

    //if module not previously defined
    auto search = design_->module_lookup_.find(new_module.identifier);
    if (search == design_->module_lookup_.end()) {

      for (auto &&[key, value] : new_module.instance_lookup_) {
        new_module.instance_lookup_[key] = value + instance_index;
      }

      //order is important
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
  // index to store at.
  auto module_index = design_->modules_.size();

  // check that module not already defined
  auto search = design_->module_lookup_.find(module_name);
  if (search == design_->module_lookup_.end()) {

    design_->modules_.push_back(Module{module_name, file_path, {}});

    design_->module_lookup_.emplace(module_name, module_index);
    return (module_index);

  } else {
    auto found = design_->modules_[design_->module_lookup_[module_name]];
    throw std::runtime_error(
        fmt::format("Module {} multiply defined! Already defined in ({}) !",
                    found.file_path));
  }
}

/*  Assumes that the origin of the instantiation is the
    last elem in collection corresponding to the NetType (modules_) */
std::size_t DesignReader::instance(NetType type, std::string instance_name,
                                   std::string definition_name)
{
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
    // create name->index lookup for instance inside origin(module);
    design_->modules_.back().instance_lookup_.emplace(instance_name,
                                                     new_instance_index);

    // create name->index lookup for instance inside design;
    // design_->instances_module_lookup_.insert({instance_name,instances_.size()})

    design_->instances_.push_back({type, // todo remove
                                   instance_name, definition_index});

    return new_instance_index;

  } else {
    throw std::runtime_error(
        fmt::format("Declaration of {} not found.", definition_name));
  }
}

std::size_t DesignReader::command(Command command, std::string definition_name)
{
  if (std::holds_alternative<SDFAnnotateCommand>(command)) {
    auto sdf = std::get<SDFAnnotateCommand>(command);

    // check if sdf_annotate applies to this scope or a child scope.
    auto apply_scope = sdf.name_of_instance.has_value()
                           ? sdf.name_of_instance.value()
                           : definition_name;

    // std::cout << fmt::format("SDF ANNOTATE : apply_scope {} \n",
    // apply_scope); for(auto&& [mn,i] : design_->module_lookup_ ){
    //   std::cout << fmt::format(" module mn : {} -- {}\n", mn, i);
    // }

    // find apply scope.
    auto search = design_->module_lookup_.find(apply_scope);
    if (search != design_->module_lookup_.end()) {
      auto apply_scope_index = design_->module_lookup_.at(apply_scope);

      auto search_2 = design_->sdf_commands_lookup_.find(apply_scope_index);

      if (search_2 != design_->sdf_commands_lookup_.end()) {

        auto sdf_index = design_->sdf_commands_lookup_[apply_scope_index];
        design_->sdf_commands_.at(sdf_index).push_back(sdf);

        return sdf_index;
      } else {
        auto new_sdf_index = design_->sdf_commands_.size();
        design_->sdf_commands_.push_back({sdf});
        design_->sdf_commands_lookup_.emplace(apply_scope_index,
                                              std::move(new_sdf_index));
        return new_sdf_index;
      }

    } else {
      throw std::runtime_error(fmt::format(
          "SDFAnnotationError : Module/Scope ({}) not found.", apply_scope));
    }
  } else {
    throw std::runtime_error("InternalError : command not supported");
  }
}

std::unique_ptr<Design> DesignReader::release()
{
  if (!net_stack_.empty())
    throw std::runtime_error("Cannot release Design while there is still net");

  return std::move(design_);
}
