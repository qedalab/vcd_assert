#ifndef LIBVERILOG_TYPES_DESIGN_HPP
#define LIBVERILOG_TYPES_DESIGN_HPP

#include "netlist.hpp"
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

struct DesignView{
  //Defintions
  std::vector<Instance> instances_;        /// Instance
  std::vector<Module> modules_;            /// Modules
  std::unordered_map<std::string, std::size_t> instance_lookup_; /// Instance lookup
  std::unordered_map<std::string, std::size_t> module_lookup_;   /// Modules lookup

   //Files
  std::vector<std::string> file_names_;      /// File Names
  
  /// 'module index' <-> 'file index' lookup
  std::unordered_map<std::size_t, std::size_t> file_name_lookup_;  
};
namespace Test{
class DesignTester;
}
/// Stores the Verilog definition information.
/// Allows for efficient lookups for common access pattern. Also efficient when
/// being read in from file or similar data structure. Can only be populated
/// with DesignReader
/// \related DesignReader
class Design
{
  //Defintions
  std::vector<Instance> instances_;        /// Instance
  std::vector<Module> modules_;            /// Modules
  // std::vector<Function> functions_;     /// Functions
  // std::vector<Task> tasks_;             /// Tasks

  // std::unordered_map<std::string, std::size_t> instance_lookup_; /// Instance lookup
  std::unordered_map<std::string, std::size_t> module_lookup_;   /// Modules lookup
  // std::unordered_map<std::string, std::size_t> function_lookup_; /// Functions lookup
  // std::unordered_map<std::string, std::size_t> task_lookup_;     /// Tasks lookup

  // std::vector<Variable> variables_;     /// Variable
  // std::vector<VarIdCode> id_codes_;     /// Identifier codes
  // Parse::Util::NameIndexMap var_id_code_map_; /// 'identifier code' <-> 'index' lookup


  //Instance tree
  // std::vector<Net> nets_;                   /// Nets

  //Files
  std::vector<std::string> file_names_;      /// File Names
  
  /// 'module index' <-> 'file index' lookup
  std::unordered_map<std::size_t, std::size_t> file_name_lookup_;   

  // /// 'file name' <-> 'file index' lookup
  // std::unordered_map<std::size_t, std::size_t> file_lookup_;   

  friend class DesignReader;
  friend class Test::DesignTester;

public:
  // /// Get variable by index
  // /// \param index the variable index
  // const Variable &get_var(std::size_t index) const;

  // /// Get net by index
  // /// \param index the net index
  // /// \returns the net
  // const Net &get_net(std::size_t index) const;

  // /// Get the first net defined in the design
  // /// \returns the root net
  // const Net &get_root_net() const;

  // /// Get the identifier code index by string
  // /// \param id_code the identifier code string
  // /// \returns the identifier code index
  // std::size_t get_var_id_code_index(std::string &id_code) const;

  // /// Get the identifier code by index
  // /// \param index the identifier code index
  // /// \returns the identifier code
  // const VarIdCode &get_var_id_code(std::size_t index) const;

  // /// True if design contains the identifier code
  // /// \param id_code the identifier code string
  // /// \returns Wether the design contains the identifier code
  // bool has_var_id_code(std::string &id_code) const noexcept;

  /// Returns the module corresponding to the identifier.
  /// \param id_code the identifier code string
  /// \returns the number of nets defined in the design
  std::optional<std::size_t> module_find(std::string module_identifier) const;


  const Module& get_module(std::size_t module_index) const;

  /// Returns the instance corresponding to the index
  /// \param instance_index the index of the instance
  /// \returns the number of nets defined in the design
  const Instance& get_instance(std::size_t instance_index) const;


  // /// Returns the number of nets defined in the design
  // /// \returns the number of nets defined in the design
  // std::size_t num_nets() const noexcept;

  // /// Returns the number of variables defined in the design
  // /// \returns the number of nets defined in the design
  // std::size_t num_variables() const noexcept;

  // /// Returns the number of identifier codes defined in the design
  // /// \returns the number of identifier code define din the design
  // std::size_t num_id_codes() const noexcept;

  /// Returns the number of identifier codes defined in the design
  /// \returns the number of identifier code define din the design
  std::size_t num_modules() const noexcept;

  /// Returns the number of identifier codes defined in the design
  /// \returns the number of identifier code define din the design
  std::size_t num_instances() const noexcept;
};

namespace Test{
  class DesignTester
  { 
    Verilog::Design design_;
    virtual void test() = 0;
  };
}


} // namespace Verilog

#endif // LIBVERILOG_TYPES_DESIGN_HPP
