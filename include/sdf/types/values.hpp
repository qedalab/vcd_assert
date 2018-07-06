#ifndef LIBSDF_TYPES_VALUES_HPP
#define LIBSDF_TYPES_VALUES_HPP

// #include <sdf/types/base.hpp>
#include <array>
#include <variant>

namespace SDF {
 



// struct Number {
//   double value;
//   bool operator==(const Number& t) const noexcept{
//     return value == t.value;
//   }
// };

using Number = double;

// // choice : min/typ/max -> but must look at edge-transitions too
struct Triple {
  Number min;
  Number typ;
  Number max;
  bool operator==(const Triple& t) const noexcept{
    return ((min == t.min) && (typ == t.typ) && (max == t.max));
  }
};
using ValueVariant = std::variant<
  Triple,
  Number
>;

struct Value : public ValueVariant {
  using ValueVariant::ValueVariant;
};
 
 
} // namespace SDF

#endif // LIBSDF_TYPES_VALUES_HPP