#ifndef LIBSDF_TYPES_TIMINGSPEC_HPP
#define LIBSDF_TYPES_TIMINGSPEC_HPP

#include <sdf/types/timing_check.hpp>
#include <sdf/types/enums.hpp>

namespace SDF {
 
namespace Unsupported{
  struct TimingDelaySpec{};
  struct TimingEnvSpec{};
  struct TimingLabelSpec{};
} // namespace Unsupported

// clang-format off
using TimingSpecVariant = std::variant<
  TimingCheckSpec,
  Unsupported::TimingDelaySpec,
  Unsupported::TimingEnvSpec,
  Unsupported::TimingLabelSpec
>;
// clang-format on

struct TimingSpec {
  TimingSpecType type;
  TimingSpecVariant value;
};

} // namespace SDF


#endif // LIBSDF_TYPES_TIMINGSPEC_HPP
