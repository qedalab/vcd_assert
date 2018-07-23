#ifndef VCD_ASSERT_TIMING_CHECKER_HPP
#define VCD_ASSERT_TIMING_CHECKER_HPP

#include "./conditional.hpp"
#include "./event.hpp"
#include "./state.hpp"
#include "./triggered_timing_checker.hpp"

#include "sdf/actions/delayfile.hpp"
#include "sdf/grammar/grammar.hpp"
#include "sdf/types/delayfile.hpp"
#include "sdf/types/enums.hpp"
#include "sdf/types/timing_check.hpp"
#include "sdf/types/timing_spec.hpp"
#include "sdf/types/values.hpp"

// #include <verilog_ast.h>
// #include <verilog_ast_util.h>
// #include <verilog_parser.h>

#include "vcd/types/header.hpp"
#include "vcd/types/simulation_time.hpp"
#include "vcd/types/value_change.hpp"

#include <optional>
#include <range/v3/span.hpp>
#include <range/v3/view/indices.hpp>
#include <variant>

// using VerilogSourceTree = verilog_source_tree;

namespace VCDAssert {

class TimingChecker
{

  struct IndexLookup {
    std::size_t from;
    std::size_t to;
  };

  // Order is important
  std::shared_ptr<VCD::Header> header_;
  State state_;
  TriggeredTimingChecker checker_;

  std::vector<IndexLookup> index_lookup_;
  std::vector<RegisterEventList> event_lists_;

  size_t sim_time_ = 0;

  enum class MinTypeMax { min, typ, max };

  // MinTypeMax min_typ_max_ = MinTypeMax::typ;

  std::vector<VCD::Value> value_buffer_;

  [[nodiscard]] bool handle_event(const RegisterEvent &event, std::size_t index,
                                  VCD::Value from, VCD::Value to);

  std::optional<std::size_t> match_scope_helper(std::vector<std::string> path,
                                                size_t path_index,
                                                size_t scope_index);

  std::optional<std::size_t> match_scope(std::vector<std::string> path,
                                         std::size_t scope_index);

  std::optional<std::size_t> get_sdf_node_index(SDF::Node node,
                                                std::size_t scope_index,
                                                VCD::Scope &scope);

  ConditionalValuePointer get_sdf_node_ptr(std::size_t var_index);

  ConditionalValuePointer
  get_sdf_conditional_ptr_helper(SDF::EqualityOperator &op,
                                 ConditionalValuePointer &left,
                                 ConditionalValuePointer &right);

  std::optional<ConditionalValuePointer>
  get_sdf_conditional_ptr(SDF::TimingCheckCondition cond,
                          std::size_t scope_index, VCD::Scope &scope);

  std::vector<std::size_t> get_hold_event_range(SDF::Node port,
                                                std::size_t port_vcd_index);

  std::optional<std::tuple<ConditionalValuePointer, EdgeType>>
  apply_sdf_hold_port_tchk_helper(SDF::PortTimingCheck port_tchk,
                                  std::size_t scope_index, VCD::Scope &scope);
  

  void apply_sdf_hold(SDF::Hold hold, std::size_t scope_index,
                      VCD::Scope &scope);

  void apply_sdf_timing_specs(SDF::Cell cell,
                              std::size_t scope_index, // remove
                              VCD::Scope &scope);

  void apply_sdf_cell_helper(SDF::Cell cell, VCD::Scope &scope);

  void apply_sdf_cell(SDF::Cell cell, std::size_t apply_scope_index);

  [[nodiscard]] bool internal_event(std::size_t index, VCD::Value value);
  [[nodiscard]] bool internal_event(std::size_t range_index, ranges::span<VCD::Value> values);
  // [[nodiscard]] bool event(std::size_t index, double value);

  void internal_update_sim_time(std::size_t sim_time);

public:
  // Claims ownership of the header
  TimingChecker(std::shared_ptr<VCD::Header> header);

  void apply_sdf_file(/*VerilogSourceTree *ast, */
                      std::shared_ptr<SDF::DelayFile> delayfile,
                      std::vector<std::string> vcd_node_path);

  void simulation_time(VCD::SimulationTime simulation_time);

  void scalar_value_change(VCD::ScalarValueChangeView value_change);
  void vector_value_change(VCD::UncheckedVectorValueChangeView value_change);
  void real_value_change(VCD::RealValueChangeView value_change);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TIMING_CHECKER_HPP
