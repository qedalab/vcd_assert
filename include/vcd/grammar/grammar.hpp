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

#ifndef LIBVCD_GRAMMAR_GRAMMAR_HPP
#define LIBVCD_GRAMMAR_GRAMMAR_HPP

#include "./base.hpp"
#include "./commands.hpp"
#include "./enums/scope_type.hpp"
#include "./enums/time.hpp"
#include "./enums/value.hpp"
#include "./enums/var_type.hpp"
#include "./keywords.hpp"
#include "./value.hpp"

#include <parse/grammar/base.h>

namespace VCD::Grammar {

using namespace Parse::Grammar;

// clang-format off

struct simulation_time : seq<one<'#'>, decimal_number, command_separator> {};

struct simulation_command : sor<
  dumpall_command,
  dumpoff_command,
  dumpon_command,
  dumpvars_command,
  comment_command,
  simulation_time,
  value_change
> {};

struct declaration_command : sor<
  comment_command,
  date_command,
  scope_command,
  timescale_command,
  upscope_command,
  var_command,
  version_command
> {};

struct header_commands : seq<
  star<declaration_command>,
  end_definitions_command
> {};

struct value_change_dump : seq<
  header_commands,
  star<simulation_command>,
  eof
> {};

// clang-format on

} // namespace VCD::Grammar

#endif // LIBVCD_GRAMMAR_GRAMMAR_HPP
