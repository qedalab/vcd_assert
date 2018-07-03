#ifndef LIBSDF_TYPES_TIMINGSPEC_HPP
#define LIBSDF_TYPES_TIMINGSPEC_HPP

#include <sdf/types/timing_check.hpp>

namespace SDF {
 
namespace Unsupported{

  struct TimingDelay{};
  struct TimingEnv{};
  struct TimingLabel{};
  
} // namespace Unsupported

// clang-format off
using TimingSpec = std::variant<
  TimingCheck,
  Unsupported::TimingDelay,
  Unsupported::TimingEnv,
  Unsupported::TimingLabel
>;
// clang-format on
 
} // namespace SDF


#endif // LIBSDF_TYPES_TIMINGSPEC_HPP
