#ifndef LIBVERILOG_TYPES_COMMANDS_HPP
#define LIBVERILOG_TYPES_COMMANDS_HPP

#include "base.hpp"

#include "parse/util/name_index_map.hpp"

#include <optional>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace Verilog {



struct SDFAnnotateCommand {
  std::string sdf_file;
  std::optional<std::string> name_of_instance;
  std::optional<std::string> config_file;
  std::optional<std::string> log_file;
  std::optional<std::string> mtm_spec;
  std::optional<std::string> scale_factors;
  std::optional<std::string> scale_type;
};

enum class CommandTypeEnum {
  unspecified,
  sdf_annotate_task
};

// struct TimeCommand {
//   int a;
// };

using CommandVariant = std::variant<
  // TimeCommand,
  SDFAnnotateCommand
>;

struct Command : public CommandVariant {
  using CommandVariant::CommandVariant;
  CommandTypeEnum type = CommandTypeEnum::unspecified;
};


}
#endif // LIBVERILOG_TYPES_COMMANDS_HPP
