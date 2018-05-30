#ifndef LIBSDF_TYPES_SCOPETREE_H_
#define LIBSDF_TYPES_SCOPETREE_H_

#include <sdf/types/timingdelay.h>
#include <parse/grammar/base.h>
#include <sdf/enums.h>
#include <sdf/types/values.h>

namespace VCDAssert {
namespace Types {

// THIS FILE IS NOT SDF SPECIFIC.
// scope tree constructs should be moved to 'vcdasser'(exe)
class ScopeNode
{
  std::string id;
  // std::option<std::shared_ptr<DelayFile>>; // Is this even necessary?
  std::map<std::string,
           std::shared_ptr<ScopeNode>>; // should this be unique pointer?
  std::vector<Delay> ds;
  std::vector<TimingCheck> tcs;
  // std::vector<TimingEnv> tes;
  // std::vector<Label> lbls;
  std::weak_ptr<ScopeNode>
      parent; // need to go up if want to flatten scope tree.
  std::shared_ptr<ScopeNode> next; // if needed to go to next.
};

// this is the design root.. all delayfiles are applied to this tree.
class ScopeTree : ScopeNode // Rename to DesignRoot/InstanceTree?
{
  std::string design_name;
  std::vector<std::shared_ptr<ScopeNode>> children;
};

} // namespace Types
} // namespace VCDAssert

#endif // LIBSDF_TYPES_SCOPETREE_H_