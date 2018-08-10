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

#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP

#include "base.hpp"
#include "commands.hpp"
#include "module.hpp"

#include <parse/util/filesystem.hpp>

#include "../../types/design_reader.hpp"
#include "../../util/parse_input.hpp"
#include "../grammar/grammar_hacked.hpp"

#include <parse/actions/make_pegtl_template.hpp>
#include <parse/util/debug_printing.hpp>
#include <tao/pegtl/memory_input.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Actions {
// clang-format off

struct GrammarAction;

struct IncludeFileApply { // clang-format on
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, DesignReader & /*reader*/,
                    Util::InputMap & /*inputmap*/, bool first_pass)
  {
    namespace fs = Parse::Util::fs;

    // BETTER WAY
    // auto next_input_rel = input.string();
    // auto next_input_abs = fs::path(next_input_rel).lexically_normal();
    // auto abs_path = fs::weakly_canonical(next_input_abs);

    auto next_input_rel = input.string();

    auto curr_path = fs::path(input.position().source).parent_path();
    auto next_input_abs = fs::path(curr_path / fs::path(next_input_rel));

    if (first_pass) {
      Parse::Util::debug_puts("DEBUG: include statement first pass\n");
    } else {
      Parse::Util::debug_puts("DEBUG: include statement second pass\n");
    }

    Parse::Util::debug_print("DEBUG: import: next_input_rel: {}\n",
                             next_input_rel);
    Parse::Util::debug_print("DEBUG: import: next_input_abs: {}\n",
                             next_input_abs);

    // TODO : Actually want lexically_normal.
    // Normalize the include, for ID purposes.
    next_input_abs = fs::exists(next_input_abs) ? fs::canonical(next_input_abs)
                                                : next_input_abs;

    // auto i = inputmap.find(next_input_abs);
    // if (i != inputmap.end()) {
    //   auto parse_input = i->second;
    //   // auto parse_input = inputmap.at(next_input_abs);

    //   if(parse_input.type == Util::InputTypeEnum::memory){
    //     auto start = std::get<const char*>(parse_input.value);
    //     tao::pegtl::memory_input<> new_input(start, next_input_rel);

    //     tao::pegtl::parse_nested<Grammar::_grammar_,
    //                             Parse::make_pegtl_template<GrammarAction>::type,
    //                             Parse::capture_control>(input, new_input,
    //                             reader,
    //                                                     inputmap,
    //                                                     first_pass);
    //   }else if(parse_input.type == Util::InputTypeEnum::library_file){
    //     auto file = std::get<std::string>(parse_input.value);
    //     tao::pegtl::file_input<> new_input(file);

    //     tao::pegtl::parse_nested<Grammar::_grammar_,
    //                             Parse::make_pegtl_template<GrammarAction>::type,
    //                             Parse::capture_control>(input, new_input,
    //                             reader,
    //                                                     inputmap,
    //                                                     first_pass);
    //   }else{
    //     Parse::Util::debug_puts("DEBUG: redundant source file include,
    //     ignored.\n");
    //   }

    // } else {
    //   throw std::runtime_error(fmt::format("RuntimeError : Could not find
    //   included file ({})",next_input_abs));
    // }

    return true;
  }
}; // clang-format off

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

// clang-format on
} // namespace Actions
} // namespace IEEE1364_2001
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_ACTIONS_GRAMMAR_HPP
