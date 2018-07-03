#ifndef LIBSDF_TYPES_VALUES_HPP
#define LIBSDF_TYPES_VALUES_HPP

// #include <sdf/grammar/base.hpp>
#include <array>

namespace SDF {
 

// // choice : min/typ/max -> but must look at edge-transitions too
struct Triple {
  // std::array<double, 3> triple;
  double min;
  double typ;
  double max;
  // auto operator<=>(const Triple&) = default;
  bool operator==(const Triple& t) const noexcept{
    return ((min == t.min) && (typ == t.typ) && (max == t.max));
  }
};

struct Number {
  double value;
  bool operator==(const Number& t) const noexcept{
    return value == t.value;
  }
};

 
} // namespace SDF

#endif // LIBSDF_TYPES_VALUES_HPP