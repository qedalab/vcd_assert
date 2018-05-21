#ifndef LIBVCD_GRAMMER_ENUMS_SCOPE_TYPE_H_
#define LIBVCD_GRAMMER_ENUMS_SCOPE_TYPE_H_

#include "../../enums.h"

#include <parse/grammar/base.h>

namespace VCD {
namespace Grammar {

using namespace Parse::Grammar::Base;

// clang-format off

/// Scope types
struct scope_begin : string<'b','e','g','i','n'> {
  static constexpr auto value = ScopeType::begin;
};

struct scope_fork : string<'f','o','r','k'> {
  static constexpr auto value = ScopeType::fork;
};

struct scope_function : string<'f','u','n','c','t','i','o','n'> {
  static constexpr auto value = ScopeType::function;
};

struct scope_task : string<'t','a','s','k'> {
  static constexpr auto value = ScopeType::task;
};

struct scope_module : string<'m','o','d','u','l','e'> {
  static constexpr auto value = ScopeType::module;
};

struct scope_type : sor<
    scope_begin,
    scope_fork,
    scope_function,
    scope_task,
    scope_module
  > {
  static constexpr auto error() { return "Expected scope type"; }
};

// clang-format on

} // namespace Grammer
} // namespace VCD

#endif
