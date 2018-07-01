#ifndef LIBSDF_TYPES_VALUES_HPP_
#define LIBSDF_TYPES_VALUES_HPP_

// #include <sdf/grammar/base.hpp>

namespace SDF {
namespace Types {

// choice : min/typ/max -> but must look at edge-transitions too
struct Triple {
  std::array<double, 3> triple;
  double min;
  double typ;
  double max;
};

struct Number {
  double value; 
};

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_VALUES_HPP_