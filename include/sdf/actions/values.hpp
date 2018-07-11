#ifndef LIBSDF_ACTIONS_VALUES_HPP
#define LIBSDF_ACTIONS_VALUES_HPP

#include <sdf/actions/base.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>
#include <sdf/grammar/values.hpp>

#include <variant>

namespace SDF {
namespace Actions {

// triple_number
// define_triple
// triple
// rtriple
// define_value
// value
// rvalue
// delval
// retval_list
// delval_list

struct PassThroughStorage{
  template<typename T>
  static bool store(T &v, T t) {
    v = t;
    return true;
  }
};

// struct SignedNumberStorage {
//   static bool store(Number &parent, bool sign) {
//     if(!sign){
//       parent = -parent;
//     }
//     return true;
//   }
// };

// struct SignAction :  multi_dispatch<
//     Grammar::one<'+'>, apply<Apply::value<true>>,
//     Grammar::one<'-'>, apply<Apply::value<false>>
// > {
//   using state = bool;
// };

// struct SignedNumberAction : multi_dispatch<
//     Grammar::sign, inner_action<SignAction,SignedNumberStorage>,
//     Grammar::real_number, apply<Apply::float_value>
// > {
//   using state = Number;
// };

struct NumberAction : multi_dispatch<
    // Grammar::sign, inner_action<SignAction,SignedNumberStorage>,
    Grammar::signed_real_number, apply<Apply::float_value>,
    // Grammar::signed_real_number, inner_action_passthrough<SignedNumberAction>,
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
    Grammar::rtriple, inner_action<
      TripleAction<Grammar::signed_real_number>, 
      PassThroughStorage>,
    Grammar::triple, inner_action<
      TripleAction<Grammar::real_number>,
      PassThroughStorage>,
    Grammar::signed_real_number, inner_action<
      NumberAction, 
      PassThroughStorage>,
    Grammar::real_number, inner_action<
      NumberAction, 
      PassThroughStorage>
> {
  using state = Value;
};


} // namespace Actions
} // namespace SDF

#endif // LIBSDF_ACTIONS_VALUES_HPP
