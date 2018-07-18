#ifndef LIBSDF_TYPES_VALUES_HPP
#define LIBSDF_TYPES_VALUES_HPP

#include <sdf/types/enums.hpp>
// #include <sdf/types/base.hpp>
#include <array>
#include <variant>
#include <optional>

namespace SDF {

// struct Number {
//   double value;
//   bool operator==(const Number& t) const noexcept{
//     return value == t.value;
//   }
// };

// using NumberValue = double;
using Number = std::optional<double>;

// struct Number : NumberValue{
//   bool operator==(const Number& t) const noexcept{
//     return value == t.value;
//   }
// };

// // choice : min/typ/max -> but must look at edge-transitions too
struct Triple {
  Number min;
  Number typ;
  Number max;
  int places = 0;

  bool operator==(const Triple &t) const noexcept {
    return ((min == t.min) && (typ == t.typ) && (max == t.max));
  }
};
using ValueVariant = std::variant<Triple, Number>;

struct Value : public ValueVariant {
  using ValueVariant::ValueVariant;

  bool operator==(const Value &other) const noexcept {
    if (std::holds_alternative<Triple>(*this) &&
        std::holds_alternative<Triple>(other)) {
      return (std::get<Triple>(*this) == std::get<Triple>(other));
    } else if (std::holds_alternative<Number>(*this) &&
               std::holds_alternative<Number>(other)) {
      return (std::get<Number>(*this) == std::get<Number>(other));
    } else {
      return false;
    }
  }

  std::optional<double> content(MinTypMax proc = MinTypMax::unspecified) const noexcept;

};

} // namespace SDF

#endif // LIBSDF_TYPES_VALUES_HPP