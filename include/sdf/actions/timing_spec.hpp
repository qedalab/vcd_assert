#ifndef LIBSDF_ACTIONS_TIMING_SPEC_HPP
#define LIBSDF_ACTIONS_TIMING_SPEC_HPP

#include <sdf/actions/base.hpp>
#include <sdf/actions/timing_check.hpp>

#include <sdf/types/timing_spec.hpp>


namespace SDF{
namespace Actions{

using namespace Parse;  

struct TimingSpecAction : single_dispatch<
  Grammar::timing_spec, inner_action<
    TimingCheckArrayAction,
    Storage::member<&TimingSpec::value>
  >
> {
  using state = TimingSpec;
};

struct TimingSpecArrayAction : single_dispatch<
  Grammar::timing_spec, inner_action<
    TimingSpecAction,
    Storage::push_back
  >
> {
  using state = std::vector<TimingSpec>;
};

}
}

#endif // LIBSDF_ACTIONS_TIMING_SPEC_HPP