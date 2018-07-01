#ifndef LIBSDF_ENUMS_HPP_
#define LIBSDF_ENUMS_HPP_

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
  rtiple,
  delval,
  delval_list,
  retval
};

enum class DelayType{
  iopath,
  interconnects
};


} // namespace SDF

#endif // LIBSDF_ENUMS_HPP_
