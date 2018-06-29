#ifndef LIBSDF_TYPES_VALUES_H_
#define LIBSDF_TYPES_VALUES_H_

// #include <sdf/grammar/base.hpp>

namespace SDF {
namespace Types {

// choice : min/typ/max -> but must look at edge-transitions too
struct Triple {
  std::array<3, double> triple;
  double min;
  double typ;
  double max;
};

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_VALUES_H_