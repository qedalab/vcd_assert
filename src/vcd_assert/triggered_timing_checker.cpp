#include "vcd_assert/triggered_timing_checker.hpp"

#include <range/v3/view/reverse.hpp>
#include <fmt/format.h>

using namespace VCDAssert;

TriggeredTimingChecker::TriggeredTimingChecker(std::size_t size) :
    triggered_event_list_(size){};

void TriggeredTimingChecker::update_sim_time(std::size_t sim_time) {
  sim_time_ = sim_time;
}

bool TriggeredTimingChecker::event(std::size_t index, VCD::Value from, VCD::Value to) {
  auto& ref = triggered_event_list_[index];
  bool out = false;

  for(auto &event : ranges::view::reverse(ref.events.as_range())) {
    // If the assertion no longer needs to be checked
    if (sim_time_ >= event.until) {
      ref.events.remove(std::addressof(event));
      continue;
    }

    // If edge type doesn't match it doesn't matter
    if (!edge_type_matches(event.edge_type, from, to)) {
      continue;
    }
    
    // if it actually triggered
    if (event.condition.value() == VCD::Value::one) {
      // TODO trigger event
    }
  }

  return out;
}

void TriggeredTimingChecker::hold(ConditionalValuePointer condition,
                                  std::size_t index, std::size_t hold_time,
                                  EdgeType edge_type)
{
  auto& ref = triggered_event_list_[index];
  TriggeredEvent triggered_event {
    std::move(condition),
    edge_type,
    sim_time_ + hold_time
  };

  ref.events.insert(std::move(triggered_event));
}
