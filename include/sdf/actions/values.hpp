#ifndef LIBSDF_ACTIONS_VALUES_HPP
#define LIBSDF_ACTIONS_VALUES_HPP

#include <sdf/actions/base.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>
#include <sdf/grammar/values.hpp>


namespace SDF {
namespace Actions {



struct NumberAction : multi_dispatch<
    Grammar::signed_real_number, apply<Apply::float_value>,
    Grammar::real_number, apply<Apply::float_value>
> {
  using state = Number;
};

template <class Number>
struct TripleAction : multi_dispatch<
    Grammar::triple_min<Number>, inner_action< 
        NumberAction, 
        Storage::member<&Triple::min>
      >,
    Grammar::triple_typ<Number>, inner_action< 
        NumberAction, 
        Storage::member<&Triple::typ>
      >,
    Grammar::triple_max<Number>, inner_action<
        NumberAction, 
        Storage::member<&Triple::max>
      >
> {
  using state = Triple;
};

struct ValueAction : multi_dispatch<
    Grammar::rtriple, 
      inner_action_passthrough<
        TripleAction<Grammar::signed_real_number>
      >, 
    Grammar::triple, 
      inner_action_passthrough<
        TripleAction<Grammar::real_number>
      >,
    Grammar::signed_real_number, 
      inner_action_passthrough<
        NumberAction
      >, 
    Grammar::real_number, 
      inner_action_passthrough<
        NumberAction
      >
> {
  using state = Value;
};


} // namespace Actions
} // namespace SDF

#endif // LIBSDF_ACTIONS_VALUES_HPP
