#ifndef LIBVCD_GRAMMER_H_
#define LIBVCD_GRAMMER_H_

#include "./commands.h"
#include "./enums/scope_type.h"
#include "./enums/time.h"
#include "./enums/value.h"
#include "./enums/var_type.h"
#include "./keywords.h"
#include "./value.h"
#include "./base.h"

#include <parse/grammar/base.h>

namespace VCD {

namespace Grammar {
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

//struct size : decimal_number {};


struct value_change_dump : seq<
  star<declaration_command>,
  end_definitions_command,
  star<simulation_command>
> {};

// clang-format on

} // namespace Grammer

} // namespace VCD

#endif // LIBSDF_GRAMMER_H_
