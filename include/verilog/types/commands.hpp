#ifndef LIBVERILOG_TYPES_COMMANDS_HPP
#define LIBVERILOG_TYPES_COMMANDS_HPP

#include "netlist.hpp"
#include "time_scale.hpp"
#include "var_id_code.hpp"
#include "variable.hpp"

#include "parse/util/name_index_map.hpp"

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace Verilog {


struct SDFAnnotateCommand {
  std::string sdf_file;
  std::string name_of_instance;
  std::string config_file;
  std::string log_file;
  std::string mtm_spec;
  std::string scale_factors;
  std::string scale_type;
};

}
#endif // LIBVERILOG_TYPES_COMMANDS_HPP
