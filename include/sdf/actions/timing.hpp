#ifndef LIBSDF_ACTIONS_TIMING_HPP
#define LIBSDF_ACTIONS_TIMING_HPP

#include <sdf/actions/base.hpp>

#include <sdf/grammar/timing.hpp>
#include <sdf/types/timing.hpp>

namespace SDF{
namespace Actions{

using namespace Parse;  

struct BusRangeStorage  {
  static bool store(Node &n, std::array<size_t, 2> arr) {
    n.end = arr[0];
    n.start = arr[1];
    return true;
  }
};

struct BusIndexAction : single_dispatch<
    Grammar::integer, apply0<Apply::integer>
>{
  using state = size_t;
};

struct BusRangeAction : single_dispatch<
    Grammar::integer, inner_action<BusIndexAction, Storage::push_back>
>{
  using state = std::array<size_t, 2>;
};

struct NodeAction : multi_dispatch<
    Grammar::bus_index, inner_action<BusIndexAction, Storage::member<&Node::start>>,
    Grammar::bus_range, inner_action<BusRangeAction, BusRangeStorage>
>{
  using state = Node;
};


}
}
#endif // LIBSDF_ACTIONS_TIMING_HPP
