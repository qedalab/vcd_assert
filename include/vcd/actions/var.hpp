#ifndef LIBVCD_TYPES_EVENT_VAR_HPP
#define LIBVCD_TYPES_EVENT_VAR_HPP

#include "./identifier_code.hpp"

#include "../types/enums.hpp"
#include "../grammar/enums/var_type.hpp"
#include "../types/variable.hpp"

#include <tao/pegtl/nothing.hpp>

#include <string_view>
#include <vcd/grammar/base.hpp>
#include <vcd/grammar/commands.hpp>

#include "parse/actions/storage/member.hpp"
#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/apply/string_view.hpp"
#include "parse/actions/apply/integer.hpp"

#include "parse/actions/dispatch.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/command/apply.hpp"
#include "parse/actions/command/pegtl_action.hpp"

namespace VCD::Actions {

using namespace Parse;


struct ReferenceAction : single_dispatch<
    Grammar::reference, apply<Apply::string_view>
> {
  using state = std::string_view;
};

struct SizeAction : single_dispatch<
    Grammar::size, apply<Apply::integer>
> {
  using state = int;
};

struct VarTypeAction : all_dispatch<apply0<Apply::rule_value>> {
  using state = VarType;
};

struct VarAction : multi_dispatch<
    Grammar::var_type, inner_action<VarTypeAction, Storage::member<&VariableView::type>>,
    Grammar::var_size, inner_action<SizeAction, Storage::member<&VariableView::size>>,
    Grammar::identifier_code, inner_action<IdentifierCodeAction, Storage::member<&VariableView::identifier_code>>,
    Grammar::reference, inner_action<ReferenceAction, Storage::member<&VariableView::reference>>
> {
  using state = VariableView;
};

} // namespace VCD::Actions

#endif // LIBVCD_TYPES_EVENT_VAR_HPP
