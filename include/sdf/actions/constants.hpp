#ifndef LIBSDF_ACTIONS_CONSTANTS_HPP
#define LIBSDF_ACTIONS_CONSTANTS_HPP

#include <sdf/actions/base.hpp>

#include <sdf/grammar/constants.hpp>


namespace SDF {
namespace Actions {

struct BinaryAction : multi_dispatch<
    Grammar::scalar_constant_0, apply0<Apply::value<false>>,
    Grammar::scalar_constant_1, apply0<Apply::value<true>>
> {
  using state = bool;
};

} // namespace Actions
} // namespace SDF

#endif // LIBSDF_ACTIONS_CONSTANTS_HPP
