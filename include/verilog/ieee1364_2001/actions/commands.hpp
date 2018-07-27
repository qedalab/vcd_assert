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
    
    outer = Command{std::move(inner)};
    
    outer.type = CommandTypeEnum::sdf_annotate_task;
    // auto temp = std::get<SDFAnnotateCommand>(outer);

    return true;
  }
};

struct SDFAnnotateTaskAction : single_dispatch<
  Grammar::sdf_annotate_task, inner_action<
      SDFAnnotateTaskHelperAction, 
      SDFAnnotateTaskStorage
    >
> {    
  using state = Command;
};

}
}
}

#endif// LIBVERILOG_IEEE1364_2001_ACTIONS_COMMAND_HPP
