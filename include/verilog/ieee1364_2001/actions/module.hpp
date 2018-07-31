#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_MODULE_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_MODULE_HPP

#include "base.hpp"
#include "commands.hpp"

#include "../../types/commands.hpp"
#include "../../types/design_reader.hpp"
#include "../../util/parse_input.hpp"
#include "../grammar/grammar_hacked.hpp"

#include <parse/util/debug_printing.hpp>
#include <parse/actions/command/inner_action_then_apply.hpp>
#include <parse/actions/make_pegtl_template.hpp>
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


struct ModuleDescriptionAction: single_dispatch<
    Grammar::_module_declaration_, 
    inner_action_passthrough< 
      ModuleDeclarationAction
    >
> {
  using state = ModuleEvent;
};


struct ModuleDescriptionApply{
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, ModuleEvent data, 
                    DesignReader &reader, Util::InputMap &/*inputmap*/, 
                    bool first_pass){
                    
    if(first_pass){
      Parse::Util::debug_puts("DEBUG: first pass : found module");
      //if first pass, build only the module list and lookup. 
      reader.module(data.module_identifier, input.position().source);
    }else{

      Parse::Util::debug_puts("DEBUG: second pass : found instance/command");
      
      for (auto&& instance : data.instances ){
        reader.instance(NetType::module, data.module_identifier, instance.name, instance.type);
      }

      for (auto&& command : data.commands ){
        reader.command(command, data.module_identifier);
      }
    }

    return true;
   }
 };

}
}
}

#endif // LIBVERILOG_IEEE1364_2001_ACTIONS_MODULE_HPP
