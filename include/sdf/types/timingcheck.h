#ifndef LIBSDF_TYPES_TIMINGCHECK_H_
#define LIBSDF_TYPES_TIMINGCHECK_H_

#include <type_traits>
#include <variant>

#include "delay.h"
#include "values.h"

namespace SDF {
namespace Types {

// clang-format off
using TimingCheckVariant = std::variant<
  // Setup,
  Hold,
  // Setuphold,
  // Recovery,
  // Removal,
  // Recrem,
  // Skew,
  // Bidirectskew,
  // Width,
  // Period,
  // Nochange
>;
// clang-format on

struct TimingCheck : public TimingCheckVariant {
  using TimingCheckVariant::TimingCheckVariant;
};

using TimingCheckPtl = std::unique_ptr<TimingCheck>;

// clang-format off
//(Almost)All timingcheck types use two ports to define the assert.
struct Hold {
  std::tuple<Port,Port> ports;
  // Port data_port;
  // Port clock_port;
  double value;
};
// clang-format on

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_TIMINGCHECK_H_