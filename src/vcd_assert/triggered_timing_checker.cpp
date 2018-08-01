#include "vcd_assert/triggered_timing_checker.hpp"

#include <parse/util/debug_printing.hpp>

#include <range/v3/view/reverse.hpp>
#include <range/v3/view/indices.hpp>
#include <fmt/format.h>

using namespace VCDAssert;

TriggeredTimingChecker::TriggeredTimingChecker(std::size_t size) :
    triggered_item_list_(size),
    sim_time_(0)
{
  // Empty
}

void TriggeredTimingChecker::set_sim_time(std::size_t sim_time) {
  Parse::Util::debug_print("DEBUG: Updating TriggeredTimingChecker sim time to {}\n", sim_time);
  sim_time_ = sim_time;
}

std::size_t TriggeredTimingChecker::get_sim_time() {
  return sim_time_;
}

bool TriggeredTimingChecker::event(std::size_t index, VCD::Value from, VCD::Value to) {
  auto& ref = triggered_item_list_[index];
  bool out = false;

  for(auto i : ranges::view::reverse(ranges::view::indices(ref.items.get_size()))) {
    auto &item = ref.items.as_range().at(i);
    Parse::Util::debug_print("DEBUG: Checking Triggered Event: {}\n", item.assertion_sv);

    // If the assertion no longer needs to be checked
    if (sim_time_ >= item.until) {
      Parse::Util::debug_print("DEBUG: Triggered event expired: {}\n", item.assertion_sv);
      Parse::Util::debug_print("       sim_time_={}, item.until={}\n", sim_time_, item.until);
      ref.items.remove(i);
      continue;
    }

    // If edge type doesn't match it doesn't matter
    if (!edge_type_matches(item.edge_type, from, to)) {
      Parse::Util::debug_print("DEBUG: Edge type doesn't match: {}\n", item.assertion_sv);
      continue;
    }
    
    // if it actually triggered
    if (item.condition.get().value() == VCD::Value::one) {
      // TODO print usefull information
      fmt::print("ASSERT: Triggered {}\n", item.assertion_sv);
      out |= true;
    }
  }
  
  return out;
}

void TriggeredTimingChecker::hold(const TriggeredEvent &event, std::size_t index)
{
  Parse::Util::debug_print("DEBUG: Registering Event: {} until {}\n", event.assertion_sv, sim_time_+event.hold_time);

  auto& ref = triggered_item_list_[index];

  TriggeredItem triggered_item {
    event.condition,
    event.edge_type,
    event.assertion_sv,
    sim_time_ + event.hold_time
  };

  ref.items.insert(triggered_item);
}
