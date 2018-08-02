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

#ifndef VCD_ASSERT_EVENT_HPP
#define VCD_ASSERT_EVENT_HPP

#include "./conditional.hpp"
#include "./edge_type.hpp"

#include "parse/util/bag.hpp"

#include <range/v3/span.hpp>

#include <cstdint>
#include <vector>

namespace VCDAssert {

struct TriggeredEvent {
  ConditionalValuePointer condition;
  EdgeType edge_type;
  std::string_view assertion_sv;
  std::size_t hold_time;
};

struct TriggeredEventList {
  Parse::Util::Bag<TriggeredEvent> events;
};

struct RegisterEvent {
  ConditionalValuePointer condition;
  EdgeType edge_type;
  std::size_t trigger_index;
  TriggeredEvent triggered;
};

struct RegisterEventList {
  std::vector<RegisterEvent> events;
};

} // namespace VCDAssert

#endif // VCD_ASSERT_EVENT_HPP
