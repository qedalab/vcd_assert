#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP

#include "base.hpp"
#include "commands.hpp"
#include "module.hpp"

#include <parse/util/filesystem.hpp>

#include "../../types/design_reader.hpp"
#include "../../util/parse_input.hpp"
#include "../grammar/grammar_hacked.hpp"

#include <parse/util/debug_printing.hpp>
#include <parse/actions/make_pegtl_template.hpp>
#include <tao/pegtl/memory_input.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Actions {
// clang-format off

struct GrammarAction;

struct IncludeFileApply {
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, 
                    DesignReader &reader, Util::InputMap &inputmap, 
                    bool first_pass){
    namespace fs =  Parse::Util::fs;

    
    std::cout << "DEBUG: include statement: first pass: " << first_pass << "\n"; 
    // auto next_input_rel = input.string();
    // auto next_input_abs = fs::path(next_input_rel).lexically_normal();
    // auto abs_path = fs::weakly_canonical(next_input_abs);
    auto next_input_rel = input.string();
    Parse::Util::debug_print("DEBUG: import: next_input_rel: {}\n",next_input_rel);
    
    auto curr_path = fs::path(input.position().source).parent_path();
    
    // curr_path for memory input is ""(the empty string)
    auto next_input_abs = fs::path(curr_path / fs::path(next_input_rel));

    Parse::Util::debug_print("DEBUG: import: next_input_abs: {}\n",next_input_abs);

    // TODO : Actually want lexically_normal.
    next_input_abs = fs::exists(next_input_abs) 
                      ? fs::canonical(next_input_abs) 
                      : next_input_abs;

    // for (auto && pair : inputmap){
    // }

    auto i = inputmap.find(next_input_abs);
    if (i != inputmap.end()) {
      auto parse_input = i->second;
      // auto parse_input = inputmap.at(next_input_abs);

      if(parse_input.type == Util::InputTypeEnum::const_char_pointer){
        auto start = std::get<const char*>(parse_input.value);
        tao::pegtl::memory_input<> new_input(start, next_input_rel);

        tao::pegtl::parse_nested<Grammar::_grammar_,
                                Parse::make_pegtl_template<GrammarAction>::type,
                                Parse::capture_control>(input, new_input, reader, 
                                                        inputmap, first_pass);
      }else if(parse_input.type == Util::InputTypeEnum::library_file){
        auto file = std::get<std::string>(parse_input.value);
        tao::pegtl::file_input<> new_input(file);

        tao::pegtl::parse_nested<Grammar::_grammar_,
                                Parse::make_pegtl_template<GrammarAction>::type,
                                Parse::capture_control>(input, new_input, reader, 
                                                        inputmap, first_pass);
      }else{
        Parse::Util::debug_puts("DEBUG: redundant source file include, ignored.\n");
      }
      
      
    } else {  
      throw std::runtime_error(fmt::format("RuntimeError : Could not find included file ({})",next_input_abs));
    }

    return true;
  }
};

struct IncludeStatementAction: single_dispatch<
    Grammar::file_path_spec, apply<IncludeFileApply>
> {
  using state = DesignReader;
};

struct CompilerDirectiveAction: single_dispatch<
    Grammar::include_statement, 
    inner_action_passthrough<IncludeStatementAction>
> {
  using state = DesignReader;
};


using DesignReaderFunctionType = void (DesignReader::*)(DesignReader);

struct GrammarAction : multi_dispatch<
  Grammar::compiler_directive, inner_action<
      CompilerDirectiveAction, 
      Storage::function<&DesignReader::merge>
  >,
  Grammar::_module_description_, inner_action_then_apply<
      ModuleDescriptionAction, 
      ModuleDescriptionApply       
  >
> {
  using state = DesignReader;
};

}
}
}

#endif // LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
