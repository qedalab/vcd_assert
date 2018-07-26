#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_MODULE_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_MODULE_HPP

#include "base.hpp"
#include "commands.hpp"

#include <filesystem>
// #include <stdlib.h>

#include "../../types/commands.hpp"
#include "../../types/design_reader.hpp"
#include "../../util/parse_input.hpp"
#include "../grammar/grammar_hacked.hpp"

#include "parse/actions/make_pegtl_template.hpp"
#include <tao/pegtl/memory_input.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Actions {
// clang-format off


struct ModuleInstanceIdentifierAction : single_dispatch<
    Grammar::module_instance_identifier, 
    inner_action_passthrough< IdentifierAction >
> {
  using state = std::string;
};

struct ModuleInstanceAction : single_dispatch<
    Grammar::name_of_instance, 
    inner_action_passthrough< ModuleInstanceIdentifierAction>
> {
  using state = std::string;
};


struct StringStringMapping {
  std::string type;
  std::string name;
};

struct ModuleEvent {
  std::string module_identifier;
  std::vector<StringStringMapping> instances; 
  std::vector<Command> commands; 
};


struct ModuleInstantiationAction : multi_dispatch<
    Grammar::module_identifier, inner_action<
      IdentifierAction, 
      Storage::member<&StringStringMapping::type>
    >,
    Grammar::module_instance, inner_action<
      ModuleInstanceAction, 
      Storage::member<&StringStringMapping::name>
    >
> {
  using state = StringStringMapping;
};

struct ModuleInstantiationArrayAction : single_dispatch<
    Grammar::module_instantiation, inner_action<
      ModuleInstantiationAction, 
      Storage::push_back
    >
> {
  using state = std::vector<StringStringMapping>;
};


struct CommandArrayAction : single_dispatch<
    Grammar::sdf_annotate_task, inner_action<
      SDFAnnotateTaskAction, 
      Storage::push_back
    >
> {
  using state = std::vector<Command>;
};


// struct InitialBlockAction : single_dispatch<
//     Grammar::sdf_annotate_task, inner_action_passthrough<
//       SDFAnnotateTaskAction,
//     >
// > {
//   using state = ModuleEvent;
// };

struct ModuleDeclarationAction : multi_dispatch<
    Grammar::module_identifier, inner_action<
      IdentifierAction, 
      Storage::member<&ModuleEvent::module_identifier>
    >,
    Grammar::module_instantiation, inner_action<
      ModuleInstantiationArrayAction, 
      Storage::member<&ModuleEvent::instances>
    >,
    Grammar::sdf_annotate_task, inner_action<
      CommandArrayAction, 
      Storage::member<&ModuleEvent::commands>
    >
> {
  using state = ModuleEvent;
};


struct ModuleDescriptionApply{
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, DesignReader &reader, ModuleEvent data, 
                    Util::InputMap &inputmap){

    //technically this does not have to happen before instances are 
    //  added, as this module may not be instanced in itself, so the lookup doesn't
    // require it to be present.
    reader.module(data.module_identifier, std::string(in.source()));
    // throw std::runtime_error(fmt::format("Saving module : {}",data.module_identifier));

    std::vector<std::size_t> insert_indices;
    
    for (auto&& instance : data.instances ){
      reader.instance(NetType::module,  instance.name, instance.type);
    }
    return true;
   }
 };

struct ModuleDescriptionAction: single_dispatch<
    Grammar::_module_declaration_, 
    inner_action< ModuleDeclarationAction, ModuleDescriptionApply >
> {
  using state = DesignReader;
};

}
}
}

#endif // LIBVERILOG_IEEE1364_2001_ACTIONS_MODULE_HPP
