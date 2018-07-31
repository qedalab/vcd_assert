#include "vcd_assert/triggered_timing_checker.hpp"

#include <range/v3/view/reverse.hpp>
#include <fmt/format.h>

using namespace VCDAssert;

TriggeredTimingChecker::TriggeredTimingChecker(std::size_t size) :
    triggered_item_list_(size),
    sim_time_(0)
{
  // Empty
}

void TriggeredTimingChecker::set_sim_time(std::size_t sim_time) {
  sim_time_ = sim_time;
}

std::size_t TriggeredTimingChecker::get_sim_time() {
  return sim_time_;
}

bool TriggeredTimingChecker::event(std::size_t index, VCD::Value from, VCD::Value to) {
  auto& ref = triggered_item_list_[index];
  bool out = false;

  for(auto &item : ranges::view::reverse(ref.items.as_range())) {
    // If the assertion no longer needs to be checked
    if (sim_time_ >= item.until) {
      ref.items.remove(std::addressof(item));
      continue;
    }

    // If edge type doesn't match it doesn't matter
    if (!edge_type_matches(item.edge_type, from, to)) {
      continue;
    }
    
    // if it actually triggered
    if (item.condition.get().value() == VCD::Value::one) {
      // TODO print usefull information
      fmt::print("Timing Assertion: Violated (TODO TYPE) from (TODO WHERE) at {}\n", sim_time_);
      out |= true;
    }
  }

  return out;
}

void TriggeredTimingChecker::hold(const TriggeredEvent &event, std::size_t index)
{
  auto& ref = triggered_item_list_[index];

  TriggeredItem triggered_item {
    event.condition,
    event.edge_type,
    event.assertion_index,
    sim_time_ + event.hold_time
  };

  ref.items.insert(triggered_item);
}
