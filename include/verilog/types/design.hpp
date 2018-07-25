#ifndef LIBVERILOG_TYPES_DESIGN_HPP
#define LIBVERILOG_TYPES_DESIGN_HPP

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

struct Instance {
  NetType type_;                     /// The net type
  std::string identifier_;           /// The net identifier
};

/// Stores the Verilog definition information.
/// Allows for efficient lookups for common access pattern. Also efficient when
/// being read in from file or similar data structure. Can only be populated
/// with DesignReader
/// \related DesignReader
class Design
{
  //Defintions
  std::vector<Instance> instances_;        /// Nets
  std::vector<Module> modules_;            /// Modules
  // std::vector<Function> functions_;     /// Functions
  // std::vector<Task> tasks_;             /// Tasks

  std::unordered_map<std::string, std::size_t> instance_lookup_; /// Instance lookup
  std::unordered_map<std::string, std::size_t> module_lookup_;   /// Modules lookup
  std::unordered_map<std::string, std::size_t> function_lookup_; /// Functions lookup
  std::unordered_map<std::string, std::size_t> task_lookup_;     /// Tasks lookup

  std::vector<Variable> variables_;     /// Variable
  std::vector<VarIdCode> id_codes_;     /// Identifier codes
  Parse::Util::NameIndexMap var_id_code_map_; /// 'identifier code' <-> 'index' lookup


  //Instance tree
  std::vector<Net> nets_;                   /// Nets

  //Files
  std::vector<std::string> file_names_;      /// File Names
  
  /// 'module index' <-> 'file index' lookup
  std::unordered_map<std::size_t, std::size_t> file_name_lookup_;   

  // /// 'file name' <-> 'file index' lookup
  // std::unordered_map<std::size_t, std::size_t> file_lookup_;   

  friend class DesignReader;

public:
  /// Get variable by index
  /// \param index the variable index
  const Variable &get_var(std::size_t index) const;

  /// Get net by index
  /// \param index the net index
  /// \returns the net
  const Net &get_net(std::size_t index) const;

  /// Get the first net defined in the design
  /// \returns the root net
  const Net &get_root_net() const;

  /// Get the identifier code index by string
  /// \param id_code the identifier code string
  /// \returns the identifier code index
  std::size_t get_var_id_code_index(std::string &id_code) const;

  /// Get the identifier code by index
  /// \param index the identifier code index
  /// \returns the identifier code
  const VarIdCode &get_var_id_code(std::size_t index) const;

  /// True if design contains the identifier code
  /// \param id_code the identifier code string
  /// \returns Wether the design contains the identifier code
  bool has_var_id_code(std::string &id_code) const noexcept;


  /// Returns the instance corresponding to the identifier and module.
  /// \param id_code the identifier code string
  /// \returns the number of nets defined in the design
  std::size_t get_instance(std::string instance_identifier) const;


  /// Returns the number of nets defined in the design
  /// \returns the number of nets defined in the design
  std::size_t num_nets() const noexcept;

  /// Returns the number of variables defined in the design
  /// \returns the number of nets defined in the design
  std::size_t num_variables() const noexcept;

  /// Returns the number of identifier codes defined in the design
  /// \returns the number of identifier code define din the design
  std::size_t num_id_codes() const noexcept;

  /// Returns the number of identifier codes defined in the design
  /// \returns the number of identifier code define din the design
  std::size_t num_modules() const noexcept;

  /// Returns the number of identifier codes defined in the design
  /// \returns the number of identifier code define din the design
  std::size_t num_instances() const noexcept;
};

} // namespace Verilog

#endif // LIBVERILOG_TYPES_DESIGN_HPP
