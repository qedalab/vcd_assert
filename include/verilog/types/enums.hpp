#ifndef LIBVERILOG_ENUMS_HPP
#define LIBVERILOG_ENUMS_HPP

namespace Verilog {

/// Verilog Scope type enum
enum class ScopeType {
  begin, fork, function, module, task, instance
};

/// Verilog Net type enum
//TODO the netlist doesn't usually contain the module + instance, does it?
enum class NetType {
  module, variable, port
};

/// Verilog Time number enum
enum class TimeNumber {
  _1=1, _10=10, _100=100
};

/// Verilog Time unit enum
enum class TimeUnit {
  s, ms, us, ns, ps, fs
};

/// Verilog Variable type enum
enum class VarType {
  event, integer, parameter, real, realtime, reg, supply0, supply1, time,
  tri, triand, trior, trireg, tri0, tri1, wand, wire, wor
};

/// Verilog Variable value enum
enum class Value {
  zero, one, x, z
};

/// Verilog $dump types enum
enum class DumpType {
  all, off, on, vars
};


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
