#ifndef LIBSDF_TYPES_TIMINGCHECK_H_
#define LIBSDF_TYPES_TIMINGCHECK_H_

#include <sdf/types/delayfile.hpp>
#include <sdf/types/values.hpp>
#include <sdf/types/variant.hpp>

namespace SDF {
namespace Types {

// clang-format off
using TimingCheckVariant = std::variant<
  // Setup,         //unsupported
  Hold,
  // Setuphold,     //unsupported
  // Recovery,      //unsupported
  // Removal,       //unsupported
  // Recrem,        //unsupported
  // Skew,          //unsupported
  // Bidirectskew,  //unsupported
  // Width,         //unsupported
  // Period,        //unsupported
  // Nochange       //unsupported
>;
// clang-format on

struct TimingCheck : public TimingCheckVariant {
  using TimingCheckVariant::TimingCheckVariant;
};

using TimingCheckPtl = std::unique_ptr<TimingCheck>;

// clang-format off
struct Hold {
  std::tuple<Port,Port> ports;
  double value;
};
// clang-format on

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_TIMINGCHECK_H_