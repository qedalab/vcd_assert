#ifndef LIBVCD_TYPES_EVENT_SCOPE_HPP
#define LIBVCD_TYPES_EVENT_SCOPE_HPP

#include "../types/enums.hpp"
#include "../types/scope.hpp"
#include "../grammar/enums/scope_type.hpp"
#include "../grammar/commands.hpp"

#include "parse/action/enum.h"
#include "parse/actions/storage/member.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/command/pegtl_action.hpp"
#include "parse/actions/apply/string_view.hpp"
#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/action/enum.h"

#include <string_view>
#include <parse/actions/apply/string_view.hpp>

namespace VCD::Actions {

using namespace Parse;

struct UpscopeApply {
  template<class Rule, class Parent>
  static bool apply0(Parent& parent) {
    parent.upscope();
    return true;
  }
};

struct ScopeTypeAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = ScopeType;
};

struct ScopeIdentifierAction : Parse::single_dispatch<
    Grammar::scope_identifier, Parse::apply<Parse::Apply::string_view>
> {
  using state = std::string_view;
};

struct ScopeAction
    : Parse::multi_dispatch<
          Grammar::scope_type,
          Parse::inner_action<ScopeTypeAction,
                              Parse::Storage::member<&ScopeDataView::type>>,
          Grammar::scope_identifier,
          Parse::inner_action<ScopeIdentifierAction,
                              Parse::Storage::member<&ScopeDataView::identifier>>
> {
  using state = ScopeDataView;
};

}

#endif //PARSE_SCOPE_HPP
