// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

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

  for(auto i : ranges::views::reverse(ranges::views::indices(ref.items.get_size()))) {
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
