#ifndef LIBSDF_ACTIONS_NUMBERS_HPP
#define LIBSDF_ACTIONS_NUMBERS_HPP

#include <sdf/actions/base.hpp>
#include <sdf/grammar/numbers.hpp>

namespace SDF {
namespace Actions {

using namespace Parse;  

//TODO : fix

// struct RealNumberAction : single_dispatch<
//     Grammar::integer, apply0<Apply::string>
// > {
//   using state = std::string;
// };

// struct IntegerAction : single_dispatch<
//     Grammar::integer, apply0<Apply::string>
// > {
//   using state = std::string;
// };

}
}

#endif // LIBSDF_ACTIONS_NUMBERS_HPP


