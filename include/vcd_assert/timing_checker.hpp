#ifndef VCD_ASSERT_TIMING_CHECKER_HPP
#define VCD_ASSERT_TIMING_CHECKER_HPP

#include "./basic_timing_checker.hpp"
#include "./conditional.hpp"
#include "./event.hpp"
#include "./state.hpp"

#include "sdf/actions/delayfile.hpp"
#include "sdf/grammar/grammar.hpp"


#include <verilog_ast.h>
#include <verilog_ast_util.h>
#include <verilog_parser.h>

#include "vcd/types/header.hpp"
#include <range/v3/span.hpp>
#include <range/v3/view/indices.hpp>

using VerilogSourceTree = verilog_source_tree;

namespace VCDAssert {

class TimingChecker {

  struct IndexLookup {
    std::size_t from;
    std::size_t to;
  };

  // Order is important
  std::shared_ptr<VCD::Header> header_;
  State state_;
  BasicTimingChecker checker_;

  std::vector<IndexLookup> index_lookup_;
  std::vector<EventList> event_lists_;

  size_t sim_time_ = 0;

  [[nodiscard]] bool handle_event(const Event& event);

private:
  void match_scope_helper();
  bool match_scope(SDF::Cell cell, 
                   std::size_t scope_index);

public:
  // Claims ownership of the header
  TimingChecker(std::shared_ptr<VCD::Header> header);

  void apply_sdf(VerilogSourceTree *ast, 
                 std::shared_ptr<SDF::DelayFile> delayfile, 
                 std::vector<std::string> vcd_node_path);

  // Trigger event and return true if event was triggered
  [[nodiscard]] bool event(std::size_t time, std::size_t index,
                           VCD::Value value);

  [[nodiscard]] bool event(std::size_t time, std::size_t index,
                           ranges::span<VCD::Value> values);

  void update_sim_time(std::size_t sim_time_);
  // Don't handle doubles for now
  // [[nodiscard]] bool event(std::size_t index, double value);
};

} // namespace VCDAssert

#endif // VCD_ASSERT_TIMING_CHECKER_HPP
