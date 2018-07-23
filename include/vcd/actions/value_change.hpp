#ifndef LIBVCD_ACTIONS_VALUE_CHANGE_HPP
#define LIBVCD_ACTIONS_VALUE_CHANGE_HPP

#include "../grammar/value.hpp"
#include "../types/value_change.hpp"
#include "./identifier_code.hpp"

#include "parse/actions/apply/rule_value.hpp"
#include "parse/actions/apply/float.hpp"
#include "parse/actions/apply/string_view.hpp"
#include "parse/actions/command/inner_action.hpp"
#include "parse/actions/command/apply0.hpp"
#include "parse/actions/dispatch.hpp"
#include "parse/actions/storage/member.hpp"

namespace VCD::Actions {

// clang-format off
struct RealAction : Parse::single_dispatch <
  Grammar::real_number, apply<Parse::Apply::float_value>
> {
  using state = double;
};

struct ValueAction : Parse::all_dispatch<Parse::apply0<Apply::rule_value>> {
  using state = Value;
};

struct UncheckedVectorValueAction : Parse::all_dispatch<Parse::apply<Apply::string_view>> {
  using state = std::string_view;
};

struct RealValueChangeAction : Parse::multi_dispatch<
  Grammar::identifier_code, Parse::inner_action<IdentifierCodeAction,
    Parse::Storage::member<&RealValueChangeView::identifier_code>>,
  Grammar::real_number, Parse::inner_action<RealAction,
    Parse::Storage::member<&RealValueChangeView::value>>
> {
  using state = RealValueChangeView;
};

struct ScalarValueChangeAction : Parse::multi_dispatch<
  Grammar::identifier_code, Parse::inner_action<IdentifierCodeAction,
    Parse::Storage::member<&ScalarValueChangeView::identifier_code>>,
  Grammar::value, Parse::inner_action<ValueAction,
    Parse::Storage::member<&ScalarValueChangeView::value>>
> {
  using state = ScalarValueChangeView;
};

struct UncheckedVectorValueChangeAction : Parse::multi_dispatch<
  Grammar::identifier_code, Parse::inner_action<IdentifierCodeAction,
    Parse::Storage::member<&UncheckedVectorValueChangeView::identifier_code>>,
  Grammar::binary_value, Parse::inner_action<UncheckedVectorValueAction,
    Parse::Storage::member<&UncheckedVectorValueChangeView::values>>
> {
  using state = UncheckedVectorValueChangeView;
};
// clang-fomrmat on

} // namespace VCD

#endif // LIBVCD_ACTIONS_VALUE_CHANGE_HPP
