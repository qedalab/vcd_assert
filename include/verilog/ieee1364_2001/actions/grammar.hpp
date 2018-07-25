#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP

#include "base.hpp"
#include "module.hpp"

#include "../grammar/grammar_hacked.hpp"
#include "../../types/design_reader.hpp"


namespace Verilog {
namespace IEEE1364_2001 {
// clang-format off

using namespace Parse;  
using namespace Verilog;  

struct GrammarAction;

struct IncludeFileApply {
  template <class Rule, class ActionInput, class InputType>
  static bool apply(const ActionInput &input, DesignReader &reader,
                    std::unordered_map<std::string, InputType> &handles)
  {
    auto input_identifier = input.string();
    auto search = handles.find(input_identifier);
    if (search != handles.end()) {
      /*file_input<>*/ auto fh = handles[input_identifier];

      tao::pegtl::parse_nested<Grammar::_grammar_,
                               make_pegtl_template<GrammarAction>::type,
                               capture_control>(input, fh, reader, input_identifier, handles);
    } else {
      throw std::runtime_error("InternalError");
    }

    return true;
  }
};


struct IncludeFileAction : all_dispatch<
  apply<IncludeFileApply>
> {};

struct IncludeStatementAction: single_dispatch<
    Grammar::file_path_spec, inner_action_passthrough<
      IncludeFileAction
  >
> {
  using state = DesignReader;
};

struct LibraryDescriptionAction: single_dispatch<
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


struct ModuleInstantiationIdentifierAction : single_dispatch<
    Grammar::module_identifier, inner_action<
      IdentifierAction, 
      Storage::member<&NetDataView::identifier>
    >
>{
  using state = NetDataView;
};



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
      ModuleInstantiationIdentifierAction, 
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
      ModuleInstantiationAction, 
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

struct GrammarAction : multi_dispatch<
  Grammar::_library_description_, inner_action<
      LibraryDescriptionAction, 
      Storage::function<&DesignReader::merge>
  >,
  Grammar::_module_description_, inner_action<
      ModuleDescriptionAction, 
      Storage::function<&DesignReader::merge>
  >
> {
  using state = DesignReader;
};
      

}
}

#endif // LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
