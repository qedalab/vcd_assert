#ifndef LIBSDF_ACTIONS_VALUES_HPP
#define LIBSDF_ACTIONS_VALUES_HPP

#include <sdf/actions/base.hpp>

#include <sdf/types/base.hpp>
#include <sdf/types/values.hpp>

#include <sdf/grammar/values.hpp>

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

struct ValueAction : single_dispatch<
    Grammar::value, apply0<Apply::string>
> {
  using state = std::string;
};

struct TripleAction : single_dispatch<
    Grammar::triple, apply0<Apply::string>
> {
  using state = std::string;
};

} // namespace Actions
} // namespace SDF

#endif // LIBSDF_ACTIONS_VALUES_HPP
