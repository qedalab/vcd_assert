#ifndef LIBVERILOG_TYPES_DESIGN_HPP
#define LIBVERILOG_TYPES_DESIGN_HPP

#include "commands.hpp"
#include "module.hpp"

#include "parse/util/name_index_map.hpp"

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace Verilog {

struct Instance {
  NetType type_;                     /// The net type
  std::string identifier_;           /// The net identifier
  std::size_t definition_index;      /// The net definition identifier
};

struct Counter {
  std::size_t value;
};

struct DesignView{
  //Definitions
  std::vector<Module> modules_;            /// Modules
  std::vector<Instance> instances_;        /// Instance

  std::unordered_map<std::string, std::size_t> module_lookup_;   /// Modules lookup

  /// Instance index -> instance definition index lookup
  // std::unordered_map<std::size_t, std::size_t> definition_lookup_;


  std::vector<std::vector<SDFAnnotateCommand>> sdf_commands_;        /// SDF commands per scope
  std::unordered_map<std::size_t, std::size_t> sdf_commands_lookup_;   /// Module -> SDF commands lookup
  //  //Files
  // std::vector<std::string> file_names_;      /// File Names
  
  // /// 'module index' <-> 'file index' lookup
  // std::unordered_map<std::size_t, std::size_t> file_name_lookup_;  
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
  //Definitions
  std::vector<Module> modules_;            /// Modules
  std::vector<Instance> instances_;        /// Instance
  // std::vector<Function> functions_;     /// Functions
  // std::vector<Task> tasks_;             /// Tasks

  std::unordered_map<std::string, std::size_t> module_lookup_;   /// Modules lookup
  // std::unordered_map<std::string, std::size_t> function_lookup_; /// Functions lookup
  // std::unordered_map<std::string, std::size_t> task_lookup_;     /// Tasks lookup


  //outer index corresponds with module index.
  std::vector<std::vector<SDFAnnotateCommand>> sdf_commands_;        /// SDF commands per scope
  std::unordered_map<std::size_t, std::size_t> sdf_commands_lookup_;   /// Module -> SDF commands lookup
  std::unordered_map<std::size_t, std::size_t> sdf_commands_reverse_lookup_;   /// Module -> SDF commands lookup

  // //Files
  // std::vector<std::string> file_names_;      /// File Names
  
  // /// 'module index' <-> 'file index' lookup
  // std::unordered_map<std::size_t, std::size_t> file_name_lookup_;   

  // /// 'file name' <-> 'file index' lookup
  // std::unordered_map<std::size_t, std::size_t> file_lookup_;   

  friend class DesignReader;
  friend class Test::DesignTester;

public:

  /// Returns the module corresponding to the identifier.
  /// \param id_code the identifier code string
  /// \returns the number of nets defined in the design
  std::optional<std::size_t> module_find(std::string module_identifier) const;


  const Module& get_module(std::size_t module_index) const;

  /// Returns the instance corresponding to the index
  /// \param instance_index the index of the instance
  /// \returns the number of nets defined in the design
  const Instance& get_instance(std::size_t instance_index) const;

    /// Returns the set of SDF commands corresponding to the index it was stored at
  /// \param sdf_set_index the index of the sdf command set
  /// \returns the SDF Annotation Command set.
  std::vector<SDFAnnotateCommand> 
  get_sdf_commands(std::size_t sdf_set_index) const;

  /// Returns the sdf_command corresponding to the index of the module it was found in.
  /// \param id_code the identifier code string
  /// \returns the number of nets defined in the design
  std::optional<std::size_t> sdf_lookup(std::size_t module_index) const;

  /// \returns the module index 
  std::size_t sdf_reverse_lookup(std::size_t sdf_set_index) const;


  /// Returns the number of identifier codes defined in the design
  /// \returns the number of identifier code define din the design
  std::size_t num_modules() const noexcept;

  /// Returns the number of identifier codes defined in the design
  /// \returns the number of identifier code define din the design
  std::size_t num_instances() const noexcept;
  
  std::size_t num_sdf_commands() const noexcept;
};

namespace Test{
  class DesignTester
  { 
    Design design_;
    virtual void test() = 0;
  };
}


} // namespace Verilog

#endif // LIBVERILOG_TYPES_DESIGN_HPP
