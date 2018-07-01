#ifndef LIBSDF_TYPES_TIMINGCHECK_HPP_
#define LIBSDF_TYPES_TIMINGCHECK_HPP_


#include <sdf/types/values.hpp>

#include <variant>
#include <tuple>

namespace SDF {
namespace Types {

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

struct Value {
  std::string identifier;
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

struct TimingCheck : public TimingCheckVariant {
  using TimingCheckVariant::TimingCheckVariant;
};

using TimingCheckPtr = std::unique_ptr<TimingCheck>;

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_TIMINGCHECK_HPP_