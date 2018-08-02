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

#include "vcd_assert/timing_checker.hpp"
#include "vcd/serialize/enums.hpp"
#include "vcd/serialize/value_change.hpp"

#include "vcd_assert/edge_type.hpp"
#include "vcd_assert/sdf_matching.hpp"

#include "vcd/util/size.hpp"
#include "vcd/util/time.hpp"

#include <range/v3/view/indices.hpp>
#include <range/v3/view/linear_distribute.hpp>
#include <range/v3/view/zip.hpp>

#include <sdf/serialize/timing_check.hpp>

using namespace VCDAssert;
using namespace ranges::view;
namespace rsv = ranges::view;

TimingChecker::TimingChecker(std::shared_ptr<VCD::Header> header,
                             std::shared_ptr<Verilog::Design> design) :
    header_(std::move(header)),
    design_(std::move(design)),
    state_(*header_),
    checker_(state_.num_total_values()),
    event_lists_(state_.num_total_values()),
    value_buffer_(VCD::Util::get_max_var_size(*header_))
{
  index_lookup_.reserve(state_.num_values());

  std::size_t counter = 0;

  for (auto i : indices(state_.num_values())) {
    auto var_id_code_view = header_->get_var_id_code(i);
    auto var_size = var_id_code_view.get_size();
    auto var_type = var_id_code_view.get_type();

#ifdef VERBOSE_DEBUG_OUTPUT
    fmt::print("DEBUG: VarIdCode: {} start at index {}\n",
               var_id_code_view.get_id_code(), counter);
#endif // VERBOSE_DEBUG_OUTPUT


    // If single value
    if (var_type == VCD::VarType::real) {
      index_lookup_.push_back({counter, counter + 1});
      counter += 1;
      continue;
    }

    if (var_size == 1) {
      // Scalar values
      pointer_to_index_[std::get<VCD::Value *>(state_.get_value_pointer(i))] =
          counter;
    } else {
      // array value
      auto value_range =
          std::get<ranges::span<VCD::Value>>(state_.get_value_pointer(i));

      for (auto jj : indices(value_range.size())) {
        pointer_to_index_[std::addressof(value_range[jj])] = counter + jj;
      }
    }

    // Else Vector
    index_lookup_.push_back({counter, counter + var_size});
    counter += var_size;
  };

  assert(index_lookup_.size() == header_->num_id_codes());
  assert(index_lookup_.size() == state_.num_values());


  /*
    Module names are unique but instance names not. Thus need to traverse two
    trees simultaneously to match them.
  */
  if (design_->num_modules() != 0) {
    auto root_scope = header_->get_root_scope();
    auto root_net_op =
        design_->module_find(std::string(root_scope.get_identifier()));
    if (root_net_op.has_value()) {
      netlist_lookup_.reserve(design_->num_modules());
      netlist_reverse_lookup_.reserve(design_->num_modules());

      netlist_lookup_.emplace(0, 0);
      netlist_reverse_lookup_.emplace(0, 0);
      build_netlist_lookup(0, root_net_op.value());
    } else {
      // incorrect-design error?
    }
  } else {
    // no-design error?
  }

  auto num_modules = design_->num_modules();
  auto num_sdf_commands = design_->num_sdf_commands();

  /* Process and apply the SDF files specified in Verilog file (from scope
   * derived call location). */
  // ONLY IF DESIGN WAS GIVEN
  if ( num_modules != 0 && num_sdf_commands != 0) {
    for (auto &&sdf_set_index : indices(design_->num_sdf_commands())) {

      // get commands
      auto sdf_command_set = design_->get_sdf_commands(sdf_set_index);

      // get apply scope as hierarchical identifier
      auto source_module_index = design_->sdf_reverse_lookup(sdf_set_index);
      auto module_identifier =
          design_->get_module(source_module_index).identifier;

      auto scope_path_index = netlist_reverse_lookup_.at(source_module_index);
      auto scope_path_str = header_->get_scope(source_module_index);

      // apply each sdf found to the scope.
      for (auto &&sdf_command : sdf_command_set) {

        // narrow down the scope at which to apply based on command
        std::optional<std::size_t> local_scope_index_op = scope_path_index;
        SDF::HierarchicalIdentifier local_scope_path{};

        // EITHER APPLY TO THIS SCOPE, A CHILD SCOPE.
        if (sdf_command.name_of_instance.has_value()) {
          if (sdf_command.name_of_instance.value() != module_identifier) {

            auto stem_path_str = sdf_command.name_of_instance.value();

            // SHOULD BE ADDITIVE, TODO TEST.
            tao::pegtl::memory_input<> stem_path_input(stem_path_str,
                                                       stem_path_str);
            tao::pegtl::parse<
                SDF::Grammar::hierarchical_identifier,
                Parse::make_pegtl_template<
                    SDF::Actions::HierarchicalIdentifierAction>::type,
                Parse::capture_control>(stem_path_input, local_scope_path);

            local_scope_index_op =
                match_scope(*header_, local_scope_path.value, scope_path_index);
          }
        }

        // apply
        if (local_scope_index_op.has_value()) {
          fmt::print("found local scope index : ({})\n",
                     local_scope_index_op.value());
          apply_sdf_file(sdf_command.sdf_file, local_scope_index_op.value());
        } else {
          // Error : annotate command specidies instance that could not be
          // found.
        }
      }
    }
  }
}

void TimingChecker::build_netlist_lookup(std::size_t scope_index,
                                         std::size_t net_index)
{
  auto child_scopes = header_->get_scope(scope_index).get_scopes();
  auto verilog_instances = design_->get_module(net_index).instance_lookup_;

  Parse::Util::debug_print("DEBUG: importing Verilog instance data :\n");
  for(auto && vi : verilog_instances){
    Parse::Util::debug_print("DEBUG: instance ({}:{})\n",vi.first,vi.second);
  }

  for (auto &&scope_tup : child_scopes) {

    auto child_scope = header_->get_scope(scope_tup.second);

    if (child_scope.get_scope_type() == VCD::ScopeType::module) {

                               
      auto instance_iter = verilog_instances.find(scope_tup.first);
      if (instance_iter != verilog_instances.end()) {

        auto child_module_index = instance_iter->second;
        
        Parse::Util::debug_print("DEBUG: storing ({}:{})\n", scope_tup.second, 
                                 child_module_index); 

        netlist_lookup_.emplace(scope_tup.second, child_module_index);
        netlist_reverse_lookup_.emplace(child_module_index, scope_tup.second);
        build_netlist_lookup(scope_tup.second, child_module_index);

      } else {
        // scope not found error
      }
    }
  }
}

std::optional<std::tuple<ConditionalValuePointer, EdgeType>>
TimingChecker::apply_sdf_hold_port_tchk_helper(SDF::PortTimingCheck port_tchk,
                                               std::size_t scope_index,
                                               VCD::Scope &scope)
{

  EdgeType edge{};

  if (port_tchk.port.edge.has_value()) {
    switch (port_tchk.port.edge.value()) {
    case SDF::EdgeType::posedge:
      edge = VCDAssert::EdgeType::PosEdge;
      Parse::Util::debug_puts("DEBUG: port check edgetype : (PosEdge)");
      break;
    case SDF::EdgeType::_01:
      edge = VCDAssert::EdgeType::_01;
      Parse::Util::debug_puts("DEBUG: port check edgetype : (_01)");
      break;
    case SDF::EdgeType::negedge:
      edge = VCDAssert::EdgeType::NegEdge;
      Parse::Util::debug_puts("DEBUG: port check edgetype : (NegEdge)");
      break;
    case SDF::EdgeType::_10:
      edge = VCDAssert::EdgeType::_10;
      Parse::Util::debug_puts("DEBUG: port check edgetype : (_10)");
      break;
    case SDF::EdgeType::_z0:
      edge = VCDAssert::EdgeType::_z0;
      Parse::Util::debug_puts("DEBUG: port check edgetype : (_z0)");
      break;
    case SDF::EdgeType::_0z:
      edge = VCDAssert::EdgeType::_0z;
      Parse::Util::debug_puts("DEBUG: port check edgetype : (_0z)");
      break;
    case SDF::EdgeType::_z1:
      edge = VCDAssert::EdgeType::_z1;
      Parse::Util::debug_puts("DEBUG: port check edgetype : (_z1)");
      break;
    case SDF::EdgeType::_1z:
      edge = VCDAssert::EdgeType::_1z;
      Parse::Util::debug_puts("DEBUG: port check edgetype : (_1z)");
      break;
    default:
      throw std::runtime_error("InternalError : unsupported edgetype");
    }
  } else {
    edge = VCDAssert::EdgeType::Edge;
    Parse::Util::debug_puts("DEBUG: port check edgetype : (Edge)");
  }

  if (port_tchk.timing_check_condition.has_value()) {
    auto cond_cvd_option = get_sdf_conditional_ptr(
        *header_, state_, port_tchk.timing_check_condition.value(),
        index_lookup_, scope_index, scope);

    if (cond_cvd_option.has_value()) {
      return {{std::move(cond_cvd_option.value()), edge}};
    } else {
      std::puts("InternalError : could not convert conditional to conditional "
                "value pointer.");
      return {};
    }

  } else {
    return {{std::move(VCD::Value::one), edge}};
  }
}

std::vector<std::size_t>
TimingChecker::get_hold_event_range(SDF::Node port,
                                    std::size_t port_vcd_var_index)
{
  std::vector<std::size_t> result{};

  /* if range */
  if (port.end.has_value()) {
    if (port.start.has_value()) {

      auto sdf_port_start = port.start.value();
      auto sdf_port_end = port.end.value();

      auto vcd_var = header_->get_var(port_vcd_var_index);
      auto vcd_id_index = vcd_var.get_id_code_index();

      auto [event_indx_start, event_inx_end] = index_lookup_[vcd_id_index];

      // verify range size corresponds
      if (event_indx_start + sdf_port_end > event_inx_end) {
        fmt::printf("WARN : Ignoring extra indices specified for signal : {}",
                    port.basename_identifier);
      }

      if (event_indx_start + sdf_port_start <= event_inx_end) {
        for (auto &&index : indices(sdf_port_start, sdf_port_end)) {
          result.push_back(event_indx_start + index);
        }
      } else {
        // Specified starting index out of bounds.
        // Ignore the HOLD.
      }
    }

    /* if single value from a range */
  } else if (port.start.has_value()) {

    auto sdf_port_start = port.start.value();

    auto vcd_var = header_->get_var(port_vcd_var_index);
    auto vcd_id_index = vcd_var.get_id_code_index();

    auto [event_indx_start, event_inx_end] = index_lookup_[vcd_id_index];

    if (event_indx_start + sdf_port_start <= event_inx_end) {
      result.push_back(event_indx_start + sdf_port_start);
    } else {
      // Specified index does not exist.
      // Ignore the HOLD.
      fmt::print("WARNING: Port range index out of bounds, ignoring HOLD!\n");
    }

    /* if single value only */
  } else {
    auto vcd_var = header_->get_var(port_vcd_var_index);
    auto vcd_id_index = vcd_var.get_id_code_index();
    result.push_back(index_lookup_[vcd_id_index].from);
  }
  return result;
}

void TimingChecker::apply_sdf_hold(SDF::DelayFile &d, SDF::Hold hold,
                                   std::size_t scope_index, VCD::Scope &scope)
{
  Parse::Util::debug_puts("DEBUG: applying hold timing check to scope.");

  auto sdf_value = hold.value.content(); // chooses TYP for now.

  auto reg = hold.reg;
  auto trig = hold.trig;

  if (sdf_value.has_value()) {

    // get the indexes to reg and trig port in header
    auto reg_port_idx_option =
        get_sdf_node_scope_index(*header_, reg.port, scope_index, scope);
    auto trig_port_idx_option =
        get_sdf_node_scope_index(*header_, trig.port, scope_index, scope);

    if (reg_port_idx_option.has_value() && trig_port_idx_option.has_value()) {

      Parse::Util::debug_puts("DEBUG: hold port nodes successfully found.");

      auto reg_port_idx = reg_port_idx_option.value();
      auto trig_port_idx = trig_port_idx_option.value();

      auto reg_apply_data_option =
          apply_sdf_hold_port_tchk_helper(reg, scope_index, scope);

      auto trig_apply_data_option =
          apply_sdf_hold_port_tchk_helper(trig, scope_index, scope);

      if (reg_apply_data_option.has_value() &&
          trig_apply_data_option.has_value()) {

        Parse::Util::debug_puts(
            "DEBUG: hold port check conditionals successfully matched.");

        auto &&[reg_cond_cvp, reg_edge] = reg_apply_data_option.value();
        auto &&[trig_cond_cvp, trig_edge] = trig_apply_data_option.value();

        // get event_list indexes of the reg event port
        auto reg_event_idx_range = get_hold_event_range(reg.port, reg_port_idx);

        // get event_list indexes of the trig event port
        auto trig_event_idx_range =
            get_hold_event_range(trig.port, trig_port_idx);

        if (!reg_event_idx_range.empty() && !trig_event_idx_range.empty()) {
          Parse::Util::debug_puts("DEBUG: hold reg port successfully matched.");

          std::string serialized;
          serialize_hold_check(ranges::back_inserter(serialized), 0, hold);

          Parse::Util::debug_puts("DEBUG: Adding hold assertion:");
          Parse::Util::debug_puts(serialized);

          assertion_string_list_.emplace_back(std::move(serialized));
          std::string_view ser_sv = assertion_string_list_.back();

          for (auto &&reg_event_idx : reg_event_idx_range) {
            for (auto &&trig_event_idx : trig_event_idx_range) {
              event_lists_[reg_event_idx].events.emplace_back(RegisterEvent{
                  std::move(reg_cond_cvp), reg_edge, 
                  (std::size_t)trig_event_idx,

                  TriggeredEvent{
                      std::move(trig_cond_cvp), trig_edge, ser_sv,
                      (std::size_t)(get_scaled_sdf_value(
                          *header_, d,
                          sdf_value.value()))}}); // TODO timescale 1000
            }
          }
        } else {
          // failed to get applicable range
        }
      }
    }
  } else {
    Parse::Util::debug_puts("DEBUG: hold value empty, ignoring.");
  }
}

/*
  for all timing specifications
    considering only timing checks
      for all hold timing checks
        create hold or conditional hold for the port/values/events involved.
*/
void TimingChecker::apply_sdf_timing_specs(SDF::DelayFile &d, SDF::Cell cell,
                                           std::size_t scope_index, // remove
                                           VCD::Scope &scope)
{
  Parse::Util::debug_puts("DEBUG: applying cell to scope.");
  for (auto &&spec : cell.timing_specs) {
    switch (spec.get_enum_type()) {
    case SDF::TimingSpecType::timing_check:

      for (auto &&check : std::get<SDF::TimingCheckSpec>(spec.value)) {
        switch (check.get_enum_type()) {
        case SDF::TimingCheckType::hold: {
          apply_sdf_hold(d, std::get<SDF::Hold>(check.value), scope_index,
                         scope);
        } break;
        default:
          throw std::runtime_error("InternalError");
        }
      }
      break;

    default:
      throw std::runtime_error("InternalError");
    }
  }
}

// This is called when the * cell instances wildcard is supplied.
// For every module in scope tree from 'scope' downward, apply.
void TimingChecker::apply_sdf_cell_helper(SDF::DelayFile &d, SDF::Cell cell,
                                          VCD::Scope &scope)
{
  Parse::Util::debug_print("DEBUG: cur scope : {} \n",scope.get_identifier());
  
  for (auto &child_scope_tup : scope.get_scopes()) {
    auto index = child_scope_tup.second;
    Parse::Util::debug_print("DEBUG: child scope : \n");
    Parse::Util::debug_print("DEBUG: ({}:{})\n", child_scope_tup.first,child_scope_tup.second);

    // cell instance scope
    VCD::Scope child_scope = header_->get_scope(index);
    Parse::Util::debug_print("DEBUG: (id={})\n", child_scope.get_identifier());

    if (child_scope.get_scope_type() == VCD::ScopeType::module) {

      for (auto && net_tup : netlist_lookup_){
        fmt::print("DEBUG: net_tup: ({}:{})\n",net_tup.first, net_tup.second);
      }

      auto verilog_module_index = netlist_lookup_.find(index);
      if (verilog_module_index != netlist_lookup_.end()) {

        auto module_name =
            design_->get_module(std::get<1>(*verilog_module_index)).identifier;
        Parse::Util::debug_print("DEBUG: scope definition ({})\n", module_name);

        if (cell.cell_type != module_name) {
          apply_sdf_timing_specs(d, cell, index, child_scope);
        }

      } else {
        Parse::Util::debug_print("DEBUG: scope index not found\n");    
        // else ignore..
      }
    }else{
      Parse::Util::debug_print("DEBUG: not a module type\n");    

    }
    // TODO : GO DOWN FOR NESTED MODULE ONLY OR ALL NESTED SCOPES?
    apply_sdf_cell_helper(d, cell, child_scope);
  }
}

void TimingChecker::apply_sdf_cell(SDF::DelayFile &d, SDF::Cell cell,
                                   std::size_t apply_scope_index)
{

  VCD::Scope apply_scope = header_->get_scope(apply_scope_index);

  /* IF the cell instance is blank or *, then look for
      verilog scopes of 'cell_type' among the available VCD scopes. */
  if (std::holds_alternative<SDF::Star>(cell.cell_instance)) {
    Parse::Util::debug_puts("DEBUG: star cell instance");

    apply_sdf_cell_helper(d, cell, apply_scope);

  } else {

    /*If a specific scope is specified, check if the scope is available
      from the current root scope. */
    auto hi = std::get<SDF::HierarchicalIdentifier>(cell.cell_instance);
    if (hi.value.empty()) {
      /* for module/instance scopes in CURRENT scope ONLY: */
      Parse::Util::debug_puts("DEBUG: blank cell instance");

      // For every module in *this* scope, apply.
      for (auto &child_scope_tup : apply_scope.get_scopes()) {
        auto index = child_scope_tup.second;

        VCD::Scope child_scope = header_->get_scope(index);

        if (child_scope.get_scope_type() == VCD::ScopeType::module) {

          Parse::Util::debug_print("DEBUG: applying cell at scope {}\n",
                                   child_scope_tup.first);
          auto verilog_module_index = netlist_lookup_.find(index);
          if (verilog_module_index != netlist_lookup_.end()) {

            auto module_name =
                design_->get_module(std::get<1>(*verilog_module_index))
                    .identifier;

            if (cell.cell_type != module_name) {
              apply_sdf_timing_specs(d, cell, index, child_scope);
            }

          } else {
            // else ignore..
          }
        }
      }

    } else {
      Parse::Util::debug_print("DEBUG: matching : {} \n", hi.to_string());

      if (apply_scope.contains_scope(hi.value[0])) {
        Parse::Util::debug_print("DEBUG: parent index ({}) child index ({})\n",
                                 apply_scope_index,
                                 apply_scope.get_scope_index(hi.value[0]));

        // ONLY the module/instance scope supplied:
        std::optional<size_t> index = match_scope(
            *header_, hi.value, apply_scope.get_scope_index(hi.value[0]));

        if (index.has_value()) {

          Parse::Util::debug_print("DEBUG: found scope index ({}) \n",
                                   index.value());
          VCD::Scope scope = header_->get_scope(index.value());

          // apply sdf timing specs withing cell instance
          apply_sdf_timing_specs(d, cell, index.value(), scope);

        } else {
          // Parse::Util::debug_puts("DEBUG: cell instance was not found.");
          Parse::Util::debug_puts(
              "DEBUG: scope does not contain cell instance.");
        }
      } else {
        Parse::Util::debug_puts("DEBUG: scope does not contain cell instance.");
      }
    }
  }
}

/*

For every application scope(appscope), find its node in the verilog ast.
Create the path to the appscope in terms of instance names(not module/type
names) Then go through

For every scope in the vcd, check whether the given node falls within the
scope. If not, increment the index and check its inner scopes(could record the
indexes that are checked so they can be skipped). Once the the application
scope is found, it becomes the SDF's root.

The cells with explicit instances are incrementally matched via scope walking
to get to the "leaf" scope. Once the leaf scope is found, check its type in
the verilog to make sure it matches the type (optional).

The cells with no instances given only applicable at the current scope to
cells of the given type. In this case, get the scope type and go through the
top level scopes checking each's type. When scopes are found that match, go
through the assertions in the cell and map each to the variables.

//Timing checker should also consolodate that all sdf files contain the same :
//    sdf_version
//    design_name
//    [process]
//    [voltage]
//    [temperature]
*/
void TimingChecker::apply_sdf_file(std::string delayfile_path,
                                   std::size_t vcd_node_scope_index)
{
  Parse::Util::debug_print("DEBUG: delayfile_path : {}\n", delayfile_path);
  SDF::DelayFileReader sdf_reader{};

  tao::pegtl::file_input<> sdf_input(delayfile_path);
  tao::pegtl::parse<
      SDF::Grammar::delay_file,
      Parse::make_pegtl_template<SDF::Actions::DelayFileAction>::type,
      Parse::capture_control>(sdf_input, sdf_reader);

  auto delayfile_p = sdf_reader.release();
  assert(delayfile_p.operator bool());

  // TODO: Should match the SDF file timescale with that of the VCD.
  // ..which could require conversion of the value.
  // auto timescale = delayfile->get_timescale();

  std::vector<SDF::Cell> cells = delayfile_p->get_cells();
  /*etc*/

  for (auto &cell : cells) {
    apply_sdf_cell(*delayfile_p, cell, vcd_node_scope_index);
  }
}

void TimingChecker::handle_event(const RegisterEvent &event,
                                               VCD::Value from, VCD::Value to) {

  if (!edge_type_matches(event.edge_type, from, to))
    return;

  if (!(event.condition.value() == VCD::Value::one))
    return;

  checker_.hold(event.triggered, event.trigger_index);
}

[[nodiscard]] bool TimingChecker::internal_event(std::size_t vcd_index,
                                                 VCD::Value value) {
  auto prev_value = state_.get_scalar_value(vcd_index);
  auto index = index_lookup_[vcd_index].from;
  auto &events = event_lists_.at(vcd_index).events;

  // Check for timing violation
  bool timing_violation = checker_.event(index, prev_value, value);

  // Check for new register events;
  for (const auto &event : events)
    handle_event(event, prev_value, value);

  // Update state
  state_.set_value(vcd_index, value);

  return timing_violation;
}

[[nodiscard]] bool TimingChecker::internal_event(
    std::size_t vcd_range_index, ranges::span<VCD::Value> values)
{
  auto prev_values = state_.get_vector_value(vcd_range_index);
  assert(values.size() == prev_values.size());

  bool timing_violation = false;
  auto range_indices = index_lookup_.at(vcd_range_index);

  // For each updated value
  for (auto i : indices(values.size())) {
    auto value = values[i];
    auto prev_value = prev_values[i];
    auto index = range_indices.from + i;

    auto &events = event_lists_.at(index).events;

    // Check for timing violation
    timing_violation |= checker_.event(index, prev_value, value);

    // Check for new register events
    for (const auto &event : events)
      handle_event(event, prev_value, value);
  }

  // Update values
  state_.set_value(vcd_range_index, values);

  return timing_violation;
}

void TimingChecker::internal_update_sim_time(std::size_t sim_time)
{
  Parse::Util::debug_print("DEBUG: Update sim time to {}\n", sim_time);
  this->sim_time_ = sim_time;
  this->checker_.set_sim_time(sim_time_);
  this->state_.update_sim_time();
}

void TimingChecker::simulation_time(VCD::SimulationTime simulation_time)
{
  if (sim_time_ > simulation_time.number) {
    fmt::print(
        "ERROR: simulation time change in VCD file is going back in time\n"
        "  To continue execution the simulation time change is ignored\n");
    return;
  }

  if (sim_time_ == simulation_time.number) {
    fmt::print(
        "WARNING: simulation time change in VCD file does not change time\n");
  }

  this->internal_update_sim_time(simulation_time.number);
}

void TimingChecker::scalar_value_change(VCD::ScalarValueChangeView value_change)
{
  std::string identifier_code_str{value_change.identifier_code};

  std::string buffer;
  VCD::serialize_value_change(ranges::back_inserter(buffer), value_change);

  Parse::Util::debug_print("DEBUG: Scalar value change: {}", buffer);

  if (!header_->has_var_id_code(identifier_code_str)) {
    fmt::print("ERROR: Unknown identifier code\n"
               "  To continue execution the scalar value change is ignored\n");
    return;
  }

  auto index = header_->get_var_id_code_index(identifier_code_str);

  if (internal_event(index, value_change.value)) {
    // Generate pretty time string if possible
    std::string sim_time_string;
    if(header_->has_time_scale()) {
      auto ts = header_->get_time_scale().value();
      sim_time_string = VCD::Util::time_string(ts, sim_time_);
    } else {
      sim_time_string = std::to_string(sim_time_);
    }

    const auto marker = value_change.marker;
    fmt::print("ASSERT: Timing violation(s) occurred "
               "during scalar value change\n"
               "        at time {} from line {} and col {}\n",
               sim_time_string, marker.line, marker.byte_in_line);
    did_assert_ = true;
  };
}

void TimingChecker::vector_value_change(
    VCD::UncheckedVectorValueChangeView value_change)
{
  std::string identifier_code_str{value_change.identifier_code};
  std::string_view values = value_change.values;

  if (!header_->has_var_id_code(identifier_code_str)) {
    fmt::print("ERROR: Unknown identifier code\n");
    fmt::print("  To continue execution the vector value change is ignored\n");
    return;
  }

  auto vcd_index = header_->get_var_id_code_index(identifier_code_str);
  auto var_id_code = header_->get_var_id_code(vcd_index);

  if (values.size() > var_id_code.get_size()) {
    fmt::print(
        "ERROR: Vector value change is larger than specified in the header\n"
        "  To continue execution the vector value change is ignored\n");
    return;
  }

  auto padded = var_id_code.get_size() - values.size();

  for (auto i : indices(values.size())) {
    char value_char = values[i];
    auto buffer_index = i + padded;
    // clang-format off
    switch (value_char) {
      case 'x': case 'X': value_buffer_[buffer_index] = VCD::Value::x; break;
      case 'z': case 'Z': value_buffer_[buffer_index] = VCD::Value::z; break;
      case '1': value_buffer_[buffer_index] = VCD::Value::one; break;
      case '0': value_buffer_[buffer_index] = VCD::Value::x; break;
      default:                                       // LCOV_EXCL_LINE
        puts("INTERNAL ERROR: Invalid value match"); // LCOV_EXCL_LINE
        std::abort();                                // LCOV_EXCL_LINE
    }
    // clang-format on
  }

  // Do left extention
  VCD::Value left_extend_value;

  // clang-format off
  switch (value_buffer_[padded]) {
    case VCD::Value::one: left_extend_value = VCD::Value::zero; break;
    case VCD::Value::zero: left_extend_value = VCD::Value::zero; break;
    case VCD::Value::x: left_extend_value = VCD::Value::x; break;
    case VCD::Value::z: left_extend_value = VCD::Value::z; break;
    default:                                      // LCOV_EXCL_LINE
      puts("INTERNAL ERROR: Invalid enum state"); // LCOV_EXCL_LINE
      std::abort();                               // LCOV_EXCL_LINE
  }
  // clang-format on

  for (auto i : indices(padded)) {
    value_buffer_[i] = left_extend_value;
  }

  // Get range of values
  ranges::span<VCD::Value> range = value_buffer_;
  range = range.subspan(0, var_id_code.get_size());

  if (internal_event(vcd_index, range)) {
    // TODO Better timing assert message
    const auto marker = value_change.marker;
    fmt::print("ASSERT : Timing violation(s) occured "
               "during vector value change\n"
               "         at time {} from line {} and col {}\n",
               sim_time_, marker.line, marker.byte_in_line);
    did_assert_ = true;
  };
}

void TimingChecker::real_value_change(VCD::RealValueChangeView /*unused*/)
{
  static bool did_warn = false;

  if (!did_warn) {
    fmt::print(
        "WARNING: Real value changes ignored in VCD file: UNIMPLEMENTED\n");
    did_warn = true;
  }
}

bool TimingChecker::did_assert() { return did_assert_; }

std::size_t TimingChecker::num_registered_events()
{
  std::size_t out = 0;

  for (auto &reg_event_list : this->event_lists_)
    out += reg_event_list.events.size();

  return out;
}

std::string
TimingChecker::serialize_conditional(const ConditionalValuePointer &cvp)
{
  return std::visit(
      [&](auto &value) -> std::string {
        using T = typename std::decay<decltype(value)>::type;

        if constexpr (std::is_same_v<T, VCD::Value>) {
          return std::string(VCD::value_to_string(value));
        } else if constexpr (std::is_same_v<T, VCD::Value *>) {
          return fmt::format("VCD[{}]", pointer_to_index_.at(value));
        } else {
          auto out = std::string("(");
          out.append(serialize_conditional(value->inner_left()));

          if (value->get_operator() == EqualityOperator::case_equal) {
            out.append(" === ");
          } else if (value->get_operator() ==
                     EqualityOperator::case_not_equal) {
            out.append(" !== ");
          } else if (value->get_operator() == EqualityOperator::logical_equal) {
            out.append(" == ");
          } else if (value->get_operator() ==
                     EqualityOperator::logical_not_equal) {
            out.append(" != ");
          } else {
            std::puts("INTERNAL ERROR: Invalid enum");
            std::abort();
          }

          out.append(serialize_conditional(value->inner_right()));
          out.append(")");

          return out;
        }
      },
      cvp.inner());
}

void TimingChecker::dump_registered_event_list()
{
  fmt::print("RegistedEventLists dump\n");
  fmt::print("=======================\n");

  for (auto i : ranges::view::indices(event_lists_.size())) {
    fmt::print("{}:", i);
    auto &event_list = event_lists_[i];

    if (event_list.events.empty()) {
      std::puts(" {}");
      continue;
    }

    std::puts(" {");

    for (auto j : ranges::view::indices(event_list.events.size())) {
      fmt::print("  {}:", j);
      auto &reg_event = event_list.events[j];
      auto &trig_event = reg_event.triggered;

      std::puts(" {");

      fmt::print("    Register Condition     : {}\n",
                 serialize_conditional(reg_event.condition));
      fmt::print("    Register EdgeType      : {}\n",
                 edge_type_to_string(reg_event.edge_type));
      fmt::print("    Register Trigger index : {}\n", reg_event.trigger_index);
      fmt::print("    Trigger Condition      : {}\n",
                 serialize_conditional(trig_event.condition));
      fmt::print("    Trigger Assertion      : {}\n",
                 trig_event.assertion_sv);
      fmt::print("    Trigger EdgeType       : {}\n",
                 edge_type_to_string(trig_event.edge_type));
      fmt::print("    Trigger hold time      : {}\n", trig_event.hold_time);

      std::puts("  }");
    }

    std::puts("}");
  }

  fmt::print("=======================\n");
}
