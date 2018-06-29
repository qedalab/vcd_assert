#ifndef LIBSDF_ACTIONS_VALUES_HPP
#define LIBSDF_ACTIONS_VALUES_HPP

#include <sdf/actions/base.hpp>
#include <sdf/types/values.hpp>
#include <sdf/grammar/values.hpp>


namespace SDF {

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


struct TripleValueAction : single_dispatch<
    Grammar::triple, apply0<Apply::value<std::string>>,
> {
  using state = std::string;
};

}

#endif LIBSDF_ACTIONS_VALUES_HPP
