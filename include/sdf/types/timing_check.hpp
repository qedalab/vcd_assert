#ifndef LIBSDF_TYPES_TIMINGCHECK_HPP
#define LIBSDF_TYPES_TIMINGCHECK_HPP


#include <sdf/types/values.hpp>

#include <variant>
#include <tuple>

namespace SDF {
 
namespace Unsupported {
  struct Setup{};
  struct Setuphold{};
  struct Recovery{};
  struct Removal{};
  struct Recrem{};
  struct Skew{};
  struct Bidirectskew{};
  struct Width{};
  struct Period{};
  struct Nochange{};
}

struct Port {
  std::string identifier;
};

using ValueVariant = std::variant<
  Triple,
  Number
>;

struct Value : public ValueVariant {
  using ValueVariant::ValueVariant;
};

struct Hold {
  std::tuple<Port,Port> ports;
  Value value;
};

// clang-format off
using TimingCheckVariant = std::variant<
  Hold,
  Unsupported::Setup,
  Unsupported::Setuphold,
  Unsupported::Recovery,
  Unsupported::Removal,
  Unsupported::Recrem,
  Unsupported::Skew,
  Unsupported::Bidirectskew,
  Unsupported::Width,
  Unsupported::Period,
  Unsupported::Nochange 
>;
// clang-format on

struct TimingCheck {
  std::vector<TimingCheckVariant> tchk_defs;
};

// struct TimingCheck : public TimingCheckVariant {
//   using TimingCheckVariant::TimingCheckVariant;
// };

// using TimingCheckDefPtr = std::unique_ptr<TimingCheckDef>;

 
} // namespace SDF

#endif // LIBSDF_TYPES_TIMINGCHECK_HPP