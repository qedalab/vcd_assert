#ifndef LIBVCD_ENUMS_H_
#define LIBVCD_ENUMS_H_


namespace VCD {

enum class ScopeType {
  begin, fork, function, module, task
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

}

#endif // LIBSDF_GRAMMER_H_
