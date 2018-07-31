#ifndef LIBSDF_ENUMS_HPP
#define LIBSDF_ENUMS_HPP

namespace SDF {

enum class HChar {
  dot, slash
};

enum class ConditionalType {
  simple,
  inverted,
  equality
};

enum class EqualityOperator {
  case_inv,
  case_equal,
  logic_inv,
  logic_equal
};

enum class TimeScaleUnit {
  s=15, ms=12, us=9, ns=6, ps=3, fs=0
};

enum class TimeScaleNumber {
  _1=1, _10=10, _100=100
};

enum class TimingSpecType {
  delay,
  timing_check,
  timing_env,
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

enum class EdgeType {
  posedge,
  negedge,
  _01,
  _10,
  _0z,
  _z1,
  _1z,
  _z0
};

enum class NodeType{
  port,
  net,
  unspecified
};

enum class MinTypMax{
  min,
  typ,
  max,
  unspecified
};


} // namespace SDF

#endif // LIBSDF_ENUMS_HPP
