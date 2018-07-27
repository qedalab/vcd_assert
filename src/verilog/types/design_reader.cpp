#include "verilog/types/design_reader.hpp"

#include <cassert>
#include "parse/util/dependent_value.hpp"

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

  auto module_index = design_->modules_.size();
  auto instance_index = design_->instances_.size();

  for (auto &&new_module : other.design_->modules_) {

    auto search = design_->module_lookup_.find(new_module.identifier);
    if (search == design_->module_lookup_.end()) {
      module_index += 1;

      for (auto &&[key, value] : new_module.instance_lookup_) {
        new_module.instance_lookup_[key] = value + instance_index;
      }

      design_->modules_.emplace_back(std::move(new_module));
      design_->module_lookup_.insert({new_module.identifier, module_index});

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
  auto module_index = design_->modules_.size();
  auto search = design_->module_lookup_.find(module_name);
  if (search == design_->module_lookup_.end()) {
    module_index += 1;
    design_->modules_.emplace_back(Module{module_name, file_path, {}});
    design_->module_lookup_.insert({module_name, module_index});
    return (design_->modules_.size() - 1);
  } else {
    auto found = design_->modules_[design_->module_lookup_[module_name]];
    throw std::runtime_error(
        fmt::format("Module {} multiply defined! Already defined in ({}) !",
                    found.file_path));
  }
}

std::size_t DesignReader::instance(NetType type, std::string instance_name,
                                   std::string definition_name)
{

  // only support module type at the moment
  auto search = design_->module_lookup_.find(definition_name);
  if (search != design_->module_lookup_.end()) {

    auto index = design_->module_lookup_[definition_name];

    // create name->index lookup for instance inside module;
    design_->modules_[index].instance_lookup_.insert(
        {instance_name, design_->modules_[index].instance_lookup_.size()});

    // create name->index lookup for instance inside design;
    // design_->instances_module_lookup_.insert({instance_name,instances_.size()})

    design_->instances_.push_back({type, // todo remove
                                   instance_name});

    return (design_->instances_.size() - 1);
  } else {
    throw std::runtime_error(
        fmt::format("Declaration of {} not found.", definition_name));
  }
}

std::size_t DesignReader::command(Command param, std::string definition_name)
{
  (void)param;
  (void)definition_name;
  return 0;
  // // using T = typename std::decay<decltype(param)>::type;

  // // if constexpr (std::is_same_v<T, SDFAnnotateCommand>) {
  // if (std::holds_alternative<SDFAnnotateCommand>(param)) {
  //   auto sdf = std::get<SDFAnnotateCommand>(param);

  //   // check if sdf_annotate applies to this scope or a child scope.
  //   auto apply_scope = sdf.name_of_instance.has_value()
  //                           ? sdf.name_of_instance.value()
  //                           : definition_name;
    
  //   // find apply scope.
  //   auto search = design_->module_lookup_.find(apply_scope);
  //   if (search != design_->module_lookup_.end()) {
      
  //     auto index = design_->sdf_commands_lookup_.at(search->second);
  //     design_->sdf_commands_.at(index).push_back(sdf);
  //     throw std::runtime_error(
  //        fmt::format("index {}", index));
      
  //     return search->second;

  //   } else {
  //     throw std::runtime_error(
  //         fmt::format("SDFAnnotationError : Module/Scope ({}) not found.",
  //                     apply_scope));
  //   }
  // } else {
  //   throw std::runtime_error("InternalError : command not supported");
  // }
}


std::unique_ptr<Design> DesignReader::release()
{
  if (!net_stack_.empty())
    throw std::runtime_error("Cannot release Design while there is still net");

  return std::move(design_);
}
