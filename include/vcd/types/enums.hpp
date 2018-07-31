#ifndef LIBVCD_TYPES_ENUMS_HPP
#define LIBVCD_TYPES_ENUMS_HPP

namespace VCD {

/// VCD Scope type enum
enum class ScopeType {
  begin, fork, function, module, task
};

/// VCD Time number enum
enum class TimeNumber {
  _1=1, _10=10, _100=100
};

/// VCD Time unit enum
enum class TimeUnit {
  s=15, ms=12, us=9, ns=6, ps=3, fs=0
};

/// VCD Variable type enum
enum class VarType {
  event, integer, parameter, real, realtime, reg, supply0, supply1, time,
  tri, triand, trior, trireg, tri0, tri1, wand, wire, wor
};

/// VCD Variable value enum
enum class Value {
  zero, one, x, z
};

/// VCD $dump types enum
enum class DumpType {
  all, off, on, vars
};

} // namespace VCD

#endif // LIBVCD_TYPES_ENUMS_HPP
