#ifndef LIBSDF_TYPES_TIMINGDELAY_H_
#define LIBSDF_TYPES_TIMINGDELAY_H_

// clang-format off
using TimingSpecVariant = std::variant<
  // Delay,     //unimplemented
  TimingCheck,
  // TimingEnv, //unimplemented
  // Label      //unimplemented
>;
// clang-format on

struct TimingSpec : public TimingSpecVariant {
  using TimingSpecVariant::TimingSpecVariant;
};

using TimingSpecPtr = std::unique_ptr<TimingSpec>;


#endif //LIBSDF_TYPES_TIMINGDELAY_H_
