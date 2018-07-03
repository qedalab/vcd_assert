#ifndef LIBSDF_ENUMS_HPP
#define LIBSDF_ENUMS_HPP

namespace SDF {

enum class HChar {
  dot, slash
};

enum class TimeScaleUnit {
  s, ms, us, ns, ps, fs
};

enum class TimeScaleNumber {
  _1, _10, _100
};

enum class TimingSpecType {
  delay,
  timingCheck,
  timingEnv,
  label
};

enum class TimingDelayType{
  iopath,
  interconnects
};

enum class TimingCheckType {
  setup,
  hold,
  setuphold,
  recovery,
  removal,
  recrem,
  skew,
  bidirectskew,
  width,
  period,
  nochange
};

enum class DataType {
  value,
  triple,
  rvalue,
  rtriple,
  delval,
  delval_list,
  retval
};




} // namespace SDF

#endif // LIBSDF_ENUMS_HPP
