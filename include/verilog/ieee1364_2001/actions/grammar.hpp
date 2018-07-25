#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP

#include "base.hpp"
#include "module.hpp"

#include "../grammar/grammar_hacked.hpp"
#include "../../types/design_reader.hpp"
#include "../../util/parse_input.hpp"

#include "parse/actions/make_pegtl_template.hpp"
#include <tao/pegtl/memory_input.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Actions {
// clang-format off

struct GrammarAction;

struct IncludeFileApply {
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, DesignReader &reader,
                    Util::InputMap &inputmap)
  { 
    // std::filesystem::current_path();
    auto next_input_identifier = input.string();
    auto search = inputmap.find(next_input_identifier);
    if (search != inputmap.end()) {
      auto next_input = inputmap.at(next_input_identifier);
      if(next_input.type == Util::InputTypeEnum::file){
        tao::pegtl::file_input<> new_input(next_input_identifier);

        tao::pegtl::parse_nested<Grammar::_grammar_,
                                Parse::make_pegtl_template<GrammarAction>::type,
                                Parse::capture_control>(input, new_input, reader, inputmap);
      }else{
        auto start = std::get<const char*>(next_input.value);
        tao::pegtl::memory_input<> new_input(start, next_input_identifier);

        tao::pegtl::parse_nested<Grammar::_grammar_,
                                Parse::make_pegtl_template<GrammarAction>::type,
                                Parse::capture_control>(input, new_input, reader, inputmap);
      }
      
      
    } else {
      throw std::runtime_error("InternalError");
    }

    return true;
  }
};

// struct action : Rule<tao::pegtl::nothing>{};
// struct IncludeFileAction : all_dispatch<
//   apply<Apply::pegtl_action<action>>
// > {};


struct IncludeStatementAction: single_dispatch<
    Grammar::file_path_spec, apply<IncludeFileApply>
> {
  using state = DesignReader;
};

struct CompilerDirectiveAction: single_dispatch<
    Grammar::_include_statement_, 
    inner_action_passthrough<IncludeStatementAction>
> {
  using state = DesignReader;
};

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

// struct InstantiationModuleIdentifierStorage{
//   static bool store(DesignReader &reader, std::string s) {
//     auto module = reader_->modules.back();
//     module
//     hi.value.push_back(std::move(s));
//     return true;
//    }
//  };



struct StringStringMapping {
  std::string type;
  std::string name;
};

struct ModuleEvent {
  std::string module_identifier;
  std::vector<StringStringMapping> instances; 
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


struct ModuleDeclarationAction : multi_dispatch<
    Grammar::module_identifier, inner_action<
      IdentifierAction, 
      Storage::member<&ModuleEvent::module_identifier>
    >,
    Grammar::module_instantiation, inner_action<
      ModuleInstantiationArrayAction, 
      Storage::member<&ModuleEvent::instances>
    >
> {
  using state = ModuleEvent;
};


struct ModuleDescriptionStorage{
  static bool store(DesignReader &reader, ModuleEvent data) {

    //technically this does not have to happen before instances are 
    //  added, as this module may not be instanced in itself, so the lookup doesnt
    // require it to be present.
    reader.module(data.module_identifier, "dummy filename");

    std::vector<std::size_t> insert_indices;
    
    for (auto&& instance : data.instances ){
      reader.instance(NetType::module,  instance.name, instance.type);
    }
    return true;
   }
 };


struct ModuleDescriptionAction: single_dispatch<
    Grammar::_module_declaration_, inner_action<
      ModuleDeclarationAction, 
      ModuleDescriptionStorage
    >
> {
  using state = DesignReader;
};

using DesignReaderFunctionType = void (DesignReader::*)(DesignReader);

struct GrammarAction : multi_dispatch<
  Grammar::compiler_directive, inner_action<
      CompilerDirectiveAction, 
      Storage::function<
        &DesignReader::merge
        // static_cast<DesignReaderFunctionType>(&DesignReader::merge)
        >
  >,
  Grammar::_module_description_, inner_action<
      ModuleDescriptionAction, 
      Storage::function<
        &DesignReader::merge
        // static_cast<DesignReaderFunctionType>(&DesignReader::merge)
        >
  >
> {
  using state = DesignReader;
};
      

}
}
}

#endif // LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
