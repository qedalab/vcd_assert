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

#ifndef VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP
#define VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP

#include "./conditional.hpp"
#include "./edge_type.hpp"
#include "./event.hpp"

#include "sdf/types/enums.hpp"

#include "parse/util/bag.hpp"

namespace VCDAssert {

struct TriggeredItem {
  std::reference_wrapper<const ConditionalValuePointer> condition;
  EdgeType edge_type;
  std::string_view assertion_sv;
  std::size_t until;
};

struct TriggeredItemList {
  Parse::Util::Bag<TriggeredItem> items;
};

class TriggeredTimingChecker
{
  std::vector<TriggeredItemList> triggered_item_list_;
  std::size_t sim_time_;

public:
  TriggeredTimingChecker(std::size_t size);

  void set_sim_time(std::size_t sim_time);
  std::size_t get_sim_time();

  [[nodiscard]] bool event(std::size_t index,
                           VCD::Value from, VCD::Value to);

  void hold(const TriggeredEvent &event, std::size_t index);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TRIGGERED_TIMING_CHECKER_HPP
