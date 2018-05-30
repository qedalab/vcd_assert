#ifndef LIBSDF_TYPES_DESIGN_H_
#define LIBSDF_TYPES_DESIGN_H_

#include "delay.h"
#include "spec.h"
#include "values.h"
#include <parse/grammar/base.h>
#include <sdf/grammar/enums.h>

namespace VCDAssert {
namespace Types {

//THIS FILE IS NOT SDF SPECIFIC. 
// scope tree constructs should be moved to 'vcdasser'(exe)
class ScopeNode
{
  std::string id;
  std::option<DelayFile>; //could make this a reference to a delayfile instead.
  std::map<std::string, std::shared_ptr<ScopeNode>>; //should this be unique pointer? 
  std::vector<Delay> ds;
  std::vector<TimingCheck> tcs;
  // std::vector<TimingEnv> tes;
  // std::vector<Label> lbls;
  std::weak_ptr<ScopeNode> parent; //need to go up during VCD design reverse ..(engineering)
  std::shared_ptr<ScopeNode> next; //needed to go to next for? TODO
};

// this is the design root.. all delayfiles are applied / built-out into the
// scope tree.
class ScopeTree : ScopeNode
{ // Rename to DesignRoot?
  std::string design_name;
  std::vector<std::shared_ptr<ScopeNode>> delayfiles; // pointers to scopes that contain delayfiles.
};

} // namespace Types
} // namespace SDF

#endif // LIBSDF_TYPES_DESIGN_H_