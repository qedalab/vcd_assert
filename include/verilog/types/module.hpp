#ifndef LIBVERILOG_TYPES_MODULE_HPP
#define LIBVERILOG_TYPES_MODULE_HPP

#include "enums.hpp"
#include "time_scale.hpp"

#include <range/v3/view/all.hpp>

#include <optional>
#include <string>
#include <unordered_map>

namespace Verilog {

class Attributes {
  std::optional<TimeScale> time_scale_; /// Time scale of 

public:
    /// Get the time scale if present
  /// \returns The time scale if present
  std::optional<TimeScale> get_time_scale() const noexcept;

  /// True if the design contains a time scale
  /// \returns Wether the design contains a time scale
  bool has_time_scale() const noexcept;

};



struct Module { 
  std::string identifier;        /// The module identifier
  std::string file_path;

  std::unordered_map<std::string, std::size_t> instance_lookup_; /// netlist references to child instances   
  // std::vector<std::size_t> variable;  /// netlist references to child variables   
  
  // std::optional<Attributes> attributes;
  
  // std::vector<Attribute> attributes_;
  // std::vector<Port> ports_;
  // std::vector<Parameters> parameters_;
};

}

#endif // LIBVERILOG_TYPES_MODULE_HPP
