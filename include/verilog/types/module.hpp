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
