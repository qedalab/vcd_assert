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
