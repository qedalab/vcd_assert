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

#ifndef LIBVERILOG_TYPES_DESIGN_READER_HPP
#define LIBVERILOG_TYPES_DESIGN_READER_HPP

#include "design.hpp"
#include "enums.hpp"

#include <fmt/format.h>
#include <memory>
#include <optional>
#include <parse/util/debug_printing.hpp>
#include <vector>

// #include <pegtl/input/>

namespace Verilog {

template <class InputTypeValueVariant>
using InputHandles = std::unordered_map<std::string, InputTypeValueVariant>; // source

// template<class InputTypeValueVariant>
// class InputHandles{
//   // std::vector<std::filesystem::path>;
//   // std::vector<std::string> sources_;
//   std::unordered_map<std::string, InputTypeValueVariant> inputs_; //source
// };
/// Verilog design reader class
/// This class populates and returns a populated Verilog::Design
// template<class InputTypeValueVariant>
class DesignReader
{
  std::unique_ptr<Design> design_;       /// Pointer to Verilog Design
  // std::vector<std::size_t> net_stack_;   /// Stack of current nets
  int current_module_index_ = 0; /// current definition index
  // InputHandles<InputTypeValueVariant> inputs_;
  // std::vector<tao::pegtl::file_input> files_;
  // std::unordered_map<std::string, std::size_t> file_lookup_;

public:
  /// DesignReader constructor
  DesignReader();

  // Copy constructor
  DesignReader(const DesignReader &other) {
    current_module_index_ = other.current_module_index_;
    design_ = std::make_unique<Design>(*other.design_);
  }
  
  // void merge(std::unique_ptr<DesignReader> other);
  void merge(DesignReader other);

  /// Introduces a new module into the design, and links it with a <NetType>
  /// definition
  std::size_t module(std::string module_name, std::string file_path);

  bool next_module();

  /// Introduces a new instance, and links it with a <NetType> definition
  /// \param NetType instance definition's type
  /// \param instance_name instance identifier.
  /// \param definition_name <NetType> definition identifier
  /// \return index instance is stored at if successful, throws otherwise.
  /// \exception Throws if definition is not found. (missing import statement)
  std::size_t instance(NetType type, std::string instance_name,
                       std::string definition_name);

  /// Add a command to be applied at a specific definition scope
  /// \param command command to add
  /// \param definition identifier
  std::size_t command(Command command);

  /// Releases the design file that was read in.
  /// Essentially finalizing the data within the design file.
  /// \returns Owning pointer to the Design
  /// \exception Throws if all there is still net in the stack.
  std::unique_ptr<Design> release();
};

} // namespace Verilog

#endif // LIBVERILOG_TYPES_DESIGN_READER_HPP
