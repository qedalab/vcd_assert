#ifndef LIBVERILOG_IEEE1364_2001_ACTIONS_COMMAND_HPP
#define LIBVERILOG_IEEE1364_2001_ACTIONS_COMMAND_HPP

#include "base.hpp"
#include "module.hpp"


#include "../../types/design_reader.hpp"
#include "../../util/parse_input.hpp"
#include "../grammar/grammar_hacked.hpp"

#include "parse/actions/make_pegtl_template.hpp"
#include <tao/pegtl/memory_input.hpp>

namespace Verilog {
namespace IEEE1364_2001 {
namespace Actions {
// clang-format off


struct SDFAnnotateHelperAction : multi_dispatch<
    Grammar::sdf_file, inner_action<
      FilePathAction, 
      Storage::member<&Command::sdf_file>
    >,
    Grammar::name_of_instance, inner_action<
      ModuleInstanceIdentifierAction, 
      Storage::member<&SDFAnntateCommand::name_of_instance>
    >,
    Grammar::config_file, inner_action<
      FilePathAction, 
      Storage::member<&SDFAnntateCommand::config_file>
    >,
    Grammar::log_file, inner_action<
      FilePathAction, 
      Storage::member<&SDFAnntateCommand::log_file>
    >,
    Grammar::mtm_spec, inner_action<
      QStringAction, 
      Storage::member<&SDFAnntateCommand::mtm_spec>
    >,
    Grammar::scale_factors, inner_action<
      QStringAction, 
      Storage::member<&SDFAnntateCommand::scale_factors>
    >,
    Grammar::scale_type, inner_action<
      QStringAction, 
      Storage::member<&SDFAnntateCommand::scale_type>
    >
> {    
  using state = Command;
};

using CommandVariant = std::variant<
  TimeCommand
  SDFAnnotateCommand
>;

struct Command : public CommandVariant {
  using CommandVariant::CommandVariant;
  CommandTypeEnum type = CommandTypeEnum::unspecified;
};


struct SDFAnnotateTaskApply{
  template <class Rule, class ActionInput>
  static bool apply(const ActionInput &input, DesignReader &reader, 
                    Util::InputMap &inputmap){

                      (void)input;
                      (void)reader;
                      (void)inputmap;
    return true;
  }
}

struct SDFAnnotateTaskAction : single_dispatch<
  Grammar::sdf_annotate_task, inner_action<
      SDFAnnotateTaskAction, 
      SDFAnnotateTaskStorage
    >
> {    
  using state = Command;
};

}
}
}

#endif// LIBVERILOG_IEEE1364_2001_ACTIONS_COMMAND_HPP
