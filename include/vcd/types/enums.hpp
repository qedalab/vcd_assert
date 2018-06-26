#ifndef LIBVCD_ENUMS_HPP
#define LIBVCD_ENUMS_HPP

namespace VCD {

enum class ScopeType {
  begin, fork, function, module, task
};

enum class TimeNumber {
  _1=1, _10=10, _100=100
};

enum class TimeUnit {
  s, ms, us, ns, ps, fs
};

enum class VarType {
  event, integer, parameter, real, realtime, reg, supply0, supply1, time,
  tri, triand, trior, trireg, tri0, tri1, wand, wire, wor
};

enum class Value {
  zero, one, x, z
};

enum class DumpType {
  all, off, on, vars
};

} // namespace VCD

#endif // LIBVCD_ENUMS_HPP
