#ifndef LIBSDF_TYPES_SPEC_H_
#define LIBSDF_TYPES_SPEC_H_

#include <variant>

#include <delay.h>
#include <timingcheck.h>
// #include <timingenv.h>
// #include <label.h>

namespace SDF {
namespace Types {


using namespace Parse;
using namespace Internal;

using TimingSpecVariant = std::variant<
  Delay,
  TimingCheck,
  // TimingEnv, //unimplemented
  // Label      //unimplemented
>;

struct TimingSpec : public TimingSpecVariant {
  using TimingSpecVariant::TimingSpecVariant;
};

using TimingSpecPtl = std::unique_ptr<TimingSpec>;




// template<typename T>
// class TimingSpec {
//   TimingSpecType type;
//   DataType dt;
//   std::vector<T> data;
// };


// struct TimingCheck : TimingSpec{
//   type = TimingSpecType::TimingCheck;
//   TimingCheckType type;
//   std::vector<TimingCheckType> tchcks;
// }


// template<>
// class DelaySpec : TimingSpec<Delay>{
//     dt = DataType::
// };


// template<>
// class TimingEnvSpec : TimingSpec<TimingEnv>{
  
// };

// template<>
// class LabelSpec : TimingSpec<LabelSpec>{
  
// };

}
}

#endif //LIBSDF_TYPES_SPEC_H_
