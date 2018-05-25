#ifndef LIBSDF_ENUMS_H_
#define LIBSDF_ENUMS_H_

#include <parse/grammar/base.h>

namespace SDF {

enum class TimescaleUnit {
  s, ms, us, ns, ps
};

enum class TimescaleNumber {
  _1, _10, _100
};

}

enum class CellType{
  Delay, TimingCheck, TimingEnv, Label
} 

enum class TimingCheckType{
  setup, hold, setuphold, recovery, removal, recrem, skew, bidirectskew, width, period, nochange
}


#endif // LIBSDF_GRAMMER_H_
