#include "verilog/types/design_reader.hpp"

#include <cassert>

using namespace Verilog;

DesignReader::DesignReader() { design_ = std::make_unique<Design>(); }

// void DesignReader::merge(std::unique_ptr<DesignReader> other)
void DesignReader::merge(DesignReader other)
{
   //Files
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

      for(auto && [key,value] : new_module.instance_lookup_){
        new_module.instance_lookup_[key] = value+instance_index;
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
    design_->modules_.emplace_back(Module{module_name,file_path, {}});
    design_->module_lookup_.insert({module_name, module_index});
    return (design_->modules_.size() -1);
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

    return (design_->instances_.size() -1);
  } else {
    throw std::runtime_error(
        fmt::format("Declaration of {} not found.", definition_name));
  }
}

// void DesignReader::net(NetType /*type*/, std::string /*name*/,
//                        std::string /*net_definition*/)
// {
//   // net_definition must have been included
//   // auto search = design_->modules_.find(net_definition);
//   // if(search != design_->modules_.end()){

//   //   auto definition_index = design_->modules_[net_definition]
//   //   auto &nets_ref = design_->nets_;

//   //   if (net_stack_.empty()) {
//   //     if (design_->num_nets() > 0)
//   //       throw std::runtime_error("Cannot have more than one base net");

//   //     // Create root net
//   //     nets_ref.emplace_back(type, std::move(name), definition_index);
//   //     net_stack_.push_back(0);
//   //   } else {

//   //     auto &current_net_ref = design_->nets_.at(net_stack_.back());

//   //     if (current_net_ref.contains_net(name))
//   //       throw std::runtime_error("Duplicate net name");

//   //     // Create net within a net
//   //     auto index = nets_ref.size();
//   //     current_net_ref.child_nets_[name] = index;
//   //     nets_ref.emplace_back(type, std::move(name), definition_index);

//   //     // Make new net active
//   //     net_stack_.push_back(index);
//   //   }
//   // }else{
//   //   throw std::runtime_error(fmt::format("Declaration of {} not found.",
//   //   net_definition));
//   // }
// }

// void DesignReader::net(Verilog::NetDataView /*net*/)
// {
//   // this->net(net.type, std::string(net.identifier), net.net_definition);
// }

// void DesignReader::upnet()
// {
//   if (net_stack_.empty())
//     throw std::runtime_error("Cannot upnet if there is no net!");

//   net_stack_.pop_back();
// }

// void DesignReader::var(VarType type, std::size_t size,
//                        std::string identifier_code, std::string reference)
// {
//   if (net_stack_.empty())
//     throw std::runtime_error("Variable must have net");

//   // Grab references for convenience
//   auto &variables_ref = design_->variables_;
//   auto &current_net_ref = design_->nets_.at(net_stack_.back());
//   auto &id_codes_ref = design_->id_codes_;

//   auto &id_code_map_ref = design_->var_id_code_map_;

//   if (current_net_ref.contains_variable(reference))
//     throw std::runtime_error("Duplicate variable reference");

//   std::size_t id_code_index;

//   if (id_code_map_ref.has_name(identifier_code)) {
//     // Check that existing identifier_code has the same type
//     id_code_index = id_code_map_ref.get_index(identifier_code);

//     auto &id_code_ref = id_codes_ref.at(id_code_index);
//     assert(id_code_ref.get_id_code() == identifier_code);

//     bool same =
//         id_code_ref.get_size() == size && id_code_ref.get_type() == type;

//     if (!same)
//       throw std::runtime_error("Same identifier code with different types");
//   } else {
//     // Add new identifier_code
//     id_code_index = id_code_map_ref.add_new_name(identifier_code);
//     assert(id_code_index == id_codes_ref.size());

//     id_codes_ref.emplace_back(type, size, identifier_code);
//   }

//   auto var_index = variables_ref.size();
//   variables_ref.emplace_back(id_code_index, reference);
//   current_net_ref.child_variables_[reference] = var_index;
// }

// void DesignReader::var(Verilog::VariableView variable)
// {
//   this->var(variable.type, variable.size, std::string(variable.identifier_code),
//             std::string(variable.reference));
// }

std::unique_ptr<Design> DesignReader::release()
{
  if (!net_stack_.empty())
    throw std::runtime_error("Cannot release Design while there is still net");

  return std::move(design_);
}
