#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP

#include "base.hpp"
#include "commands.hpp"
#include "module.hpp"

// #include <parse/util/filesystem.hpp>
#include <filesystem>

#include "../../types/design_reader.hpp"
#include "../../util/parse_input.hpp"
#include "../grammar/grammar_hacked.hpp"

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
                    Util::InputMap &inputmap/*, Counter &*//*module_count*/)
  { 
    // namespace fs =  Parse::Util::fs;
    namespace fs = std::filesystem;

    auto next_input_identifier = input.string();
    auto search_input = fs::path(next_input_identifier).lexically_normal();
    auto abs_path = fs::weakly_canonical(search_input);
    
    // std::cout << fmt::format("INCLUDE : {}({}) \n",search_input,abs_path) ;

    auto search = inputmap.find(search_input);
    if (search != inputmap.end()) {

      auto parse_input = inputmap.at(search_input);

      if(parse_input.type == Util::InputTypeEnum::file){
        auto next_input = std::get<std::string>(parse_input.value);
        tao::pegtl::file_input<> new_input(next_input);

        tao::pegtl::parse_nested<Grammar::_grammar_,
                                Parse::make_pegtl_template<GrammarAction>::type,
                                Parse::capture_control>(input, new_input, reader, inputmap);
      }else{
        auto start = std::get<const char*>(parse_input.value);
        tao::pegtl::memory_input<> new_input(start, next_input_identifier);

        tao::pegtl::parse_nested<Grammar::_grammar_,
                                Parse::make_pegtl_template<GrammarAction>::type,
                                Parse::capture_control>(input, new_input, reader, inputmap);
      }
      
      
    } else {
      throw std::runtime_error(fmt::format("RuntimeError : Could not find included file ({})",search_input));
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
      // Storage::function<&DesignReader::merge>
      ModuleDescriptionApply       
  >
> {
  using state = DesignReader;
};
      

}
}
}

#endif // LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
