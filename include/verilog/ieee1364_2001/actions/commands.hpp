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

#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_COMMAND_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_COMMAND_HPP

#include "base.hpp"

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

using namespace Verilog;

struct SDFAnnotateTaskHelperAction : multi_dispatch<
    Grammar::sdf_file, inner_action<
      FilePathSpecAction, 
      Storage::member<&SDFAnnotateCommand::sdf_file>
    >,
    Grammar::name_of_instance, inner_action<
      IdentifierAction, 
      Storage::member<&SDFAnnotateCommand::name_of_instance>
    >,
    Grammar::config_file, inner_action<
      FilePathSpecAction, 
      Storage::member<&SDFAnnotateCommand::config_file>
    >,
    Grammar::log_file, inner_action<
      FilePathSpecAction, 
      Storage::member<&SDFAnnotateCommand::log_file>
    >,
    Grammar::mtm_spec, inner_action<
      QStringAction, 
      Storage::member<&SDFAnnotateCommand::mtm_spec>
    >,
    Grammar::scale_factors, inner_action<
      QStringAction, 
      Storage::member<&SDFAnnotateCommand::scale_factors>
    >,
    Grammar::scale_type, inner_action<
      QStringAction, 
      Storage::member<&SDFAnnotateCommand::scale_type>
    >
> {    
  using state = SDFAnnotateCommand;
};

struct SDFAnnotateTaskActionProxy : single_dispatch<
  Grammar::sdf_annotate_task, inner_action_passthrough<
      SDFAnnotateTaskHelperAction
    >
> {    
  using state = Command;
};

struct SDFAnnotateTaskStorage{
  static bool store(Command &outer, Command inner){
    
    outer = std::move(inner);
    
    outer.type = CommandTypeEnum::sdf_annotate_task;

    return true;
  }
};

struct SDFAnnotateTaskAction : single_dispatch<
  Grammar::sdf_annotate_task, inner_action<
      SDFAnnotateTaskActionProxy, 
      SDFAnnotateTaskStorage
    >
> {    
  using state = Command;
};

// clang-format on
}
}
}

#endif// LIBVERILOG_IEEE1364_2001_ACTIONS_COMMAND_HPP
