#ifndef LIBSDF_ACTIONS_TIMING_SPEC_HPP
#define LIBSDF_ACTIONS_TIMING_SPEC_HPP

#include <sdf/actions/base.hpp>
#include <sdf/actions/timing_check.hpp>

#include <sdf/types/timing_spec.hpp>


namespace SDF{
namespace Actions{

using namespace Parse;  

struct TimingSpecArrayAction : single_dispatch<
  Grammar::tc_spec, inner_action<
    TimingCheckAction,
    Storage::push_back
  >
> {
  using state = std::vector<TimingSpec>;
};

}
}

#endif // LIBSDF_ACTIONS_TIMING_SPEC_HPP