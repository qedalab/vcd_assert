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

#ifndef VCD_ASSERT_TIMING_CHECKER_HPP
#define VCD_ASSERT_TIMING_CHECKER_HPP

#include "./conditional.hpp"
#include "./event.hpp"
#include "./state.hpp"
#include "./sdf_matching.hpp"
#include "./triggered_timing_checker.hpp"

#include <sdf/actions/base.hpp>
#include <sdf/actions/delayfile.hpp>
#include <sdf/grammar/base.hpp>
#include <sdf/grammar/delayfile.hpp>
#include <sdf/grammar/grammar.hpp>
#include <sdf/types/base.hpp>
#include <sdf/types/enums.hpp>
#include <sdf/types/delayfile.hpp>
#include <sdf/types/delayfile_reader.hpp>
#include <sdf/types/timing_check.hpp>
#include <sdf/types/timing_spec.hpp>
#include <sdf/types/values.hpp>

#include <parse/actions/control.hpp>
#include <parse/actions/make_pegtl_template.hpp>
#include <parse/util/filesystem.hpp>
#include <parse/util/debug_printing.hpp>


#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>


#include <verilog/types/design.hpp>
#include <verilog/types/commands.hpp>

#include <vcd/types/header.hpp>
#include <vcd/types/simulation_time.hpp>
#include <vcd/types/value_change.hpp>

#include <optional>
#include <range/v3/span.hpp>
#include <range/v3/view/indices.hpp>
#include <variant>
#include <fmt/format.h>

#include <unordered_map>

namespace VCDAssert {

class TimingChecker
{

  // struct IndexLookup {
  //   std::size_t from;
  //   std::size_t to;
  // };

  // Order is important
  std::shared_ptr<VCD::Header> header_;
  std::shared_ptr<Verilog::Design> design_;
  State state_;
  TriggeredTimingChecker checker_;

  std::unordered_map<std::size_t,std::size_t> netlist_lookup_;//scope -> module 
  std::unordered_map<std::size_t,std::size_t> netlist_reverse_lookup_; // module -> scope

  // std::unordered_map<std::size_t,std::size_t> sdf_apply_scope_lookup_;//??Why this
  std::vector<IndexLookup> index_lookup_;
  std::vector<RegisterEventList> event_lists_;
  std::vector<std::string> assertion_string_list_;

  std::unordered_map<VCD::Value*, std::size_t> pointer_to_index_;

  size_t sim_time_ = 0;
  bool did_assert_ = false;

  enum class MinTypeMax { min, typ, max };

  // MinTypeMax min_typ_max_ = MinTypeMax::typ;

  std::vector<VCD::Value> value_buffer_;

  void build_netlist_lookup(std::size_t scope_index, std::size_t net_index);

  void handle_event(const RegisterEvent &event, VCD::Value from, VCD::Value to);

  std::vector<std::size_t> get_hold_event_range(SDF::Node port,
                                                std::size_t port_vcd_var_index);

  std::optional<std::tuple<ConditionalValuePointer, EdgeType>>
  apply_sdf_hold_port_tchk_helper(SDF::PortTimingCheck port_tchk,
                                  std::size_t scope_index, VCD::Scope &scope);
  

  void apply_sdf_hold(SDF::DelayFile &d, SDF::Hold hold, std::size_t scope_index,
                      VCD::Scope &scope);

  void apply_sdf_timing_specs(SDF::DelayFile &d, SDF::Cell cell,
                              std::size_t scope_index, // remove
                              VCD::Scope &scope);

  void apply_sdf_cell_helper(SDF::DelayFile &d, SDF::Cell cell, VCD::Scope &scope);

  void apply_sdf_cell(SDF::DelayFile &d, SDF::Cell cell, std::size_t apply_scope_index);

  [[nodiscard]] bool internal_event(std::size_t vcd_index, VCD::Value value);
  [[nodiscard]] bool internal_event(std::size_t vcd_range_index,
                                    ranges::span<VCD::Value> values);
  // [[nodiscard]] bool event(std::size_t index, double value);

  void internal_update_sim_time(std::size_t sim_time);

  std::string serialize_conditional(const ConditionalValuePointer &cvp);

public:
  // Claims ownership of the header
  TimingChecker(std::shared_ptr<VCD::Header> header, std::shared_ptr<Verilog::Design> design);

  void apply_sdf_file(std::string delayfile_path, std::size_t vcd_node_scope_index);

  void simulation_time(VCD::SimulationTime simulation_time);

  void scalar_value_change(VCD::ScalarValueChangeView value_change);
  void vector_value_change(VCD::UncheckedVectorValueChangeView value_change);
  void real_value_change(VCD::RealValueChangeView value_change);

  bool did_assert();
  std::size_t num_registered_events();

  void dump_registered_event_list();
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TIMING_CHECKER_HPP
