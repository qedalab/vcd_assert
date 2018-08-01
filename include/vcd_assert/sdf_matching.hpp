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

#ifndef VCD_ASSERT_SDF_MATCHING_HPP
#define VCD_ASSERT_SDF_MATCHING_HPP

#include "./conditional.hpp"
#include "./state.hpp"

#include <sdf/types/enums.hpp>
#include <sdf/types/delayfile.hpp>
#include <sdf/types/timing.hpp>
#include <sdf/types/timing_check.hpp>
#include <parse/util/debug_printing.hpp>


namespace VCDAssert {

struct IndexLookup {
  std::size_t from;
  std::size_t to;
};


ConditionalValuePointer
get_sdf_conditional_ptr_helper(SDF::EqualityOperator op, 
                               ConditionalValuePointer left,
                               ConditionalValuePointer right);

int get_scaled_sdf_value(const VCD::Header &header, const SDF::DelayFile &d, double input);

ConditionalValuePointer get_sdf_node_ptr(const VCD::Header &header,
                                         State &state, 
                                         std::vector<IndexLookup> &index_lookup, 
                                         std::size_t vcd_var_index);

std::optional<std::size_t> match_scope(const VCD::Header &header,
                                       std::vector<std::string> path,
                                       std::size_t scope_index);

std::optional<std::size_t> match_scope_helper(const VCD::Header &header,
                                              std::vector<std::string> path,
                                              std::size_t path_index,
                                              std::size_t scope_index);

std::optional<std::size_t> get_sdf_node_scope_index(const VCD::Header &header,
                                              SDF::Node node,
                                              std::size_t scope_index,
                                              const VCD::Scope &scope);

std::optional<ConditionalValuePointer>
get_sdf_conditional_ptr(const VCD::Header &header, State &state,
                        SDF::TimingCheckCondition cond, 
                        std::vector<IndexLookup> &index_lookup, 
                        std::size_t scope_index, VCD::Scope &scope);

} // namespace VCDAssert

#endif // VCD_ASSERT_SDF_MATCHING_HPP
