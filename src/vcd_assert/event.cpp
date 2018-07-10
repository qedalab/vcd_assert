#include "vcd_assert/event.hpp"

using namespace VCDAssert;

ranges::span<Event> EventList::get_event_list(EdgeType type) {
  if(type == EdgeType::PosEdge)
    return this->pos_edge;

  if(type == EdgeType::NegEdge)
    return this->neg_edge;

  return {};
}

