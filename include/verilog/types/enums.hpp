#ifndef LIBVERILOG_ENUMS_HPP
#define LIBVERILOG_ENUMS_HPP

namespace Verilog {

enum class HChar {
  dot, slash
};

enum class ConditionalType {
  none,
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
  s, ms, us, ns, ps, fs
};

enum class TimeScaleNumber {
  _1, _10, _100
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


} // namespace Verlog

#endif // LIBVERILOG_ENUMS_HPP
