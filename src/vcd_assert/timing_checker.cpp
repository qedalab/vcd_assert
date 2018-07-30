#include "vcd_assert/timing_checker.hpp"

#include "vcd_assert/edge_type.hpp"
#include "vcd_assert/sdf_matching.hpp"

#include "vcd/util/size.hpp"

#include <range/v3/view/indices.hpp>
#include <range/v3/view/linear_distribute.hpp>
#include <range/v3/view/zip.hpp>

using namespace VCDAssert;
using namespace ranges::view;
namespace rsv = ranges::view;

TimingChecker::TimingChecker(std::shared_ptr<VCD::Header> header, std::shared_ptr<Verilog::Design> design) :
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

    // If single value
    if (var_type == VCD::VarType::real || var_size == 1) {
      index_lookup_.push_back({counter, counter + 1});
      counter += 1;
      continue;
    }

    // Else Vector
    index_lookup_.push_back({counter, counter + var_size});
    counter += var_size;
  };

  /*
    Module names are unique but instance names not. Thus need to traverse two 
    trees simultaneously to match them.
  */
  if(design_->num_modules() != 0){
    auto root_scope = header_->get_root_scope();
    auto root_net_op = design_->module_find(std::string(root_scope.get_identifier()));
    if(root_net_op.has_value()){
      netlist_lookup_.reserve(design_->num_modules());
      netlist_reverse_lookup_.reserve(design_->num_modules());
  
      netlist_lookup_.emplace(0,0);
      netlist_reverse_lookup_.emplace(0,0);
      build_netlist_lookup(0,root_net_op.value());
    }else{
      // incorrect-design error?
    }
  }else{
    // no-design error?
  }

  /* Process and apply the SDF files specified in Verilog file (from scope derived call location). */ 
  // ONLY IF DESIGN WAS GIVEN
  if((design_->num_modules() != 0) && (design_->num_sdf_commands() != 0)){
    for (auto &&sdf_set_index : indices(design_->num_sdf_commands())) {
      
      // get commands
      auto sdf_command_set = design_->get_sdf_commands(sdf_set_index);

      // get apply scope as hierarchical identifier
      auto source_module_index = design_->sdf_reverse_lookup(sdf_set_index);
      auto module_identifier = design_->get_module(source_module_index).identifier;
     
      auto scope_path_index = netlist_reverse_lookup_.at(source_module_index);
      auto scope_path_str = header_->get_scope(source_module_index);

      // apply each sdf found to the scope.
      for (auto &&sdf_command : sdf_command_set) {

        // narrow down the scope at which to apply based on command
        std::optional<std::size_t> local_scope_index_op = scope_path_index;
        SDF::HierarchicalIdentifier local_scope_path{};

        // EITHER APPLY TO THIS SCOPE, A CHILD SCOPE.
        if(sdf_command.name_of_instance.has_value()){
          if(sdf_command.name_of_instance.value() != module_identifier){

            auto stem_path_str = sdf_command.name_of_instance.value();
            
            //SHOULD BE ADDITIVE, TODO TEST.
            tao::pegtl::memory_input<> stem_path_input(stem_path_str, stem_path_str);
            tao::pegtl::parse<SDF::Grammar::hierarchical_identifier,
                              Parse::make_pegtl_template<
                                  SDF::Actions::HierarchicalIdentifierAction>::type,
                              Parse::capture_control>(stem_path_input, local_scope_path);
            
            local_scope_index_op = match_scope(*header_, local_scope_path.value, scope_path_index);
          }
        }

        // apply
        if(local_scope_index_op.has_value()){
          apply_sdf_file(sdf_command.sdf_file, local_scope_index_op.value());
        }else{
          // Error : annotate command specidies instance that could not be found.
        }
      }
    }
  }
}

 
void TimingChecker::build_netlist_lookup(std::size_t scope_index, std::size_t net_index)
{  
  auto child_scopes = header_->get_scope(scope_index).get_scopes();
  auto verilog_instances = design_->get_module(net_index).instance_lookup_;

  for (auto&& scope_tup : child_scopes) {
    
    auto child_scope = header_->get_scope(scope_tup.second);

    if(child_scope.get_scope_type() == VCD::ScopeType::module){

      auto instance_iter = verilog_instances.find(scope_tup.first);
      if(instance_iter != verilog_instances.end()){

        auto child_module_index = std::get<1>(*instance_iter);

        netlist_lookup_.emplace(scope_tup.second, child_module_index);
        netlist_reverse_lookup_.emplace(child_module_index,scope_tup.second);
        build_netlist_lookup(scope_tup.second, child_module_index);

      }else{
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
      break;
    case SDF::EdgeType::_01:
      edge = VCDAssert::EdgeType::_01;
      break;
    case SDF::EdgeType::negedge:
      edge = VCDAssert::EdgeType::NegEdge;
      break;
    case SDF::EdgeType::_10:
      edge = VCDAssert::EdgeType::_10;
      break;
    case SDF::EdgeType::_z0:
      edge = VCDAssert::EdgeType::_z0;
      break;
    case SDF::EdgeType::_0z:
      edge = VCDAssert::EdgeType::_0z;
      break;
    case SDF::EdgeType::_z1:
      edge = VCDAssert::EdgeType::_z1;
      break;
    case SDF::EdgeType::_1z:
      edge = VCDAssert::EdgeType::_1z;
      break;
    default:
      throw std::runtime_error("InternalError : unsupported edgetype");
    }
  } else {
    edge = VCDAssert::EdgeType::Edge;
  }

  if (port_tchk.timing_check_condition.has_value()) {
    auto cond_cvd_option = get_sdf_conditional_ptr(*header_, state_,
        port_tchk.timing_check_condition.value(), scope_index, scope);

    if (cond_cvd_option.has_value()) {
      return {{std::move(cond_cvd_option.value()), edge}};
    } else {
      return {};
    }

  } else {
    return {{std::move(VCD::Value::one), edge}};
  }
}

std::vector<std::size_t>
TimingChecker::get_hold_event_range(SDF::Node port, std::size_t port_vcd_index)
{
  std::vector<std::size_t> result{};

  /* if range */
  if (port.end.has_value()) {
    if (port.start.has_value()) {

      auto sdf_port_start = port.start.value();
      auto sdf_port_end = port.end.value();

      auto [vcd_val_start, vcd_val_end] = index_lookup_[port_vcd_index];

      // verify range size corresponds
      if (vcd_val_start + sdf_port_end > vcd_val_end) {
        fmt::printf("WARN : Ignoring extra indices specified for signal : {}",
                    port.basename_identifier);
      }

      if (vcd_val_start + sdf_port_start <= vcd_val_end) {
        for (auto &&index : indices(sdf_port_start, sdf_port_end)) {
          result.push_back(vcd_val_start + index);
        }
      } else {
        // Specified starting index out of bounds.
        // Ignore the HOLD.
      }
    }

    /* if single value from a range */
  } else if (port.start.has_value()) {

    auto sdf_port_start = port.start.value();

    auto [vcd_val_start, vcd_val_end] = index_lookup_[port_vcd_index];

    if (vcd_val_start + sdf_port_start <= vcd_val_end) {
      result.push_back(vcd_val_start + sdf_port_start);
    } else {
      // Specified index does not exist.
      // Ignore the HOLD.
    }

    /* if single value only */
  } else {
    result.push_back(index_lookup_[port_vcd_index].from);
  }
  return result;
}

void TimingChecker::apply_sdf_hold(SDF::Hold hold, std::size_t scope_index,
                                   VCD::Scope &scope)
{
  auto sdf_value = hold.value.content(); // chooses TYP for now.

  auto reg = hold.reg;
  auto trig = hold.trig;

  if (sdf_value.has_value()) {

    // get the indexes to reg and trig port in header
    auto reg_port_index_option =
        get_sdf_node_index(*header_, reg.port, scope_index, scope);
    auto trig_port_index_option =
        get_sdf_node_index(*header_, trig.port, scope_index, scope);

    if (reg_port_index_option.has_value() &&
        trig_port_index_option.has_value()) {

      // auto trig_port_index = trig_port_index_option.value();
      auto reg_port_index = reg_port_index_option.value();

      auto reg_apply_data_option =
          apply_sdf_hold_port_tchk_helper(reg, scope_index, scope);

      auto trig_apply_data_option =
          apply_sdf_hold_port_tchk_helper(trig, scope_index, scope);

      if (reg_apply_data_option.has_value() &&
          trig_apply_data_option.has_value()) {

        auto &&[reg_conditional_cvp, reg_edge] = reg_apply_data_option.value();
        auto &&[trig_conditional_cvp, trig_edge] =
            trig_apply_data_option.value();

        auto reg_event_range = get_hold_event_range(reg.port, reg_port_index);

        if (!reg_event_range.empty()) {
          for (auto &&index : reg_event_range) {
            event_lists_[index].events.emplace_back(RegisterEvent{
                std::move(reg_conditional_cvp), reg_edge,
                TriggeredEvent{std::move(trig_conditional_cvp), trig_edge,
                               (std::size_t)0,
                               (std::size_t)(sdf_value.value() * 1000)}}); //TODO timescale
          }
        } else {
          // failed to get applicable range
        }
      }
    }
  }
}

/*
  for all timing specifications
    considering only timing checks
      for all hold timing checks
        create hold or conditional hold for the port/values/events involved.
*/
void TimingChecker::apply_sdf_timing_specs(SDF::Cell cell,
                                           std::size_t scope_index, // remove
                                           VCD::Scope &scope)
{
  for (auto &&spec : cell.timing_specs) {
    switch (spec.get_enum_type()) {
    case SDF::TimingSpecType::timing_check:

      for (auto &&check : std::get<SDF::TimingCheckSpec>(spec.value)) {
        switch (check.get_enum_type()) {
        case SDF::TimingCheckType::hold: {
          apply_sdf_hold(std::get<SDF::Hold>(check.value), scope_index, scope);
          // auto var_svp = state_.get_value_pointer(0);
          // auto var_cvp = ConditionalValuePointer(var_svp);
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
void TimingChecker::apply_sdf_cell_helper(SDF::Cell cell, VCD::Scope &scope)
{
  for (auto &child_scope_tup : scope.get_scopes()) {
    auto index = child_scope_tup.second;

    // cell instance scope
    VCD::Scope child_scope = header_->get_scope(index);

    if (child_scope.get_scope_type() == VCD::ScopeType::module) {

      auto verilog_module_index = netlist_lookup_.find(index);
      if(verilog_module_index != netlist_lookup_.end()){
      
        auto module_name = design_->get_module(
          std::get<1>(*verilog_module_index)).identifier;

        if(cell.cell_type != module_name){
          apply_sdf_timing_specs(cell, index, child_scope);
        }

      }else{
        // else ignore..
      }

    }
      //TODO : GO DOWN FOR NESTED MODULE ONLY OR ALL NESTED SCOPES? 
      apply_sdf_cell_helper(cell, child_scope); 

  }
}

void TimingChecker::apply_sdf_cell(SDF::Cell cell,
                                   std::size_t apply_scope_index)
{

  VCD::Scope apply_scope = header_->get_scope(apply_scope_index);

  /* IF the cell instance is blank or *, then look for
      verilog scopes of 'cell_type' among the available VCD scopes. */
  if (std::holds_alternative<SDF::Star>(cell.cell_instance)) {

    static bool did_warn = false;
    if (!did_warn) {
      fmt::print(
          "WARNING: No Verilog design supplied. All SDF cells with (CELLINSTANCE *) ignored.\n");
      did_warn = true;
    }
    // for module/instance scopes FROM applied scope DOWN:
    apply_sdf_cell_helper(cell, apply_scope);

  } else {

    static bool did_warn = false;
    if (!did_warn) {
      fmt::print(
          "WARNING: No Verilog design supplied. All SDF cells with (CELLINSTANCE ) ignored.\n");
      did_warn = true;
    }

    /*If a specific scope is specified, check if the scope is available
      from the current root scope. */
    auto hi = std::get<SDF::HierarchicalIdentifier>(cell.cell_instance);
    if (hi.value.empty()) {
      /* for module/instance scopes in CURRENT scope ONLY: */

      // For every module in *this* scope, apply.
      for (auto &child_scope_tup : apply_scope.get_scopes()) {
        auto index = child_scope_tup.second;

        VCD::Scope child_scope = header_->get_scope(index);

        if (child_scope.get_scope_type() == VCD::ScopeType::module) {

          auto verilog_module_index = netlist_lookup_.find(index);        
          if(verilog_module_index != netlist_lookup_.end()){
          
            auto module_name = design_->get_module(
              std::get<1>(*verilog_module_index)).identifier;

            if(cell.cell_type != module_name){
              apply_sdf_timing_specs(cell, index, child_scope);
            }

          }else{
            // else ignore..
          }

        }
      }

    } else {

      // ONLY the module/instance scope supplied:
      std::optional<size_t> index = match_scope(*header_, hi.value, apply_scope_index);

      if (index.has_value()) {
        VCD::Scope scope = header_->get_scope(index.value());

        // apply sdf timing specs withing cell instance
        apply_sdf_timing_specs(cell, index.value(), scope);

      } else {
        // cell instance was not found.
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
    apply_sdf_cell(cell, vcd_node_scope_index);
  }

}

[[nodiscard]] bool TimingChecker::handle_event(const RegisterEvent &event,
                                               std::size_t index,
                                               VCD::Value from, VCD::Value to) {
  bool out = checker_.event(index, from, to);

  if (!edge_type_matches(event.edge_type, from, to))
    return out;

  if (!(event.condition.value() == VCD::Value::one))
    return out;

  checker_.hold(event.triggered, index);

  return out;
}

    [[nodiscard]] bool TimingChecker::internal_event(std::size_t vcd_index,
                                                     VCD::Value value)
{
  auto prev_value = state_.get_scalar_value(vcd_index);
  auto index = index_lookup_[vcd_index].from;
  auto &events = event_lists_.at(vcd_index).events;

  // Check for timing violation
  bool timing_violation = false;
  for (const auto &event : events)
    timing_violation |= handle_event(event, index, prev_value, value);

  // Update state
  state_.set_value(index, value);

  return timing_violation;
}

[[nodiscard]] bool
TimingChecker::internal_event(std::size_t vcd_range_index,
                              ranges::span<VCD::Value> values) {
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
    for (const auto &event : events)
      timing_violation |= handle_event(event, index, prev_value, value);
  }

  // Update values
  state_.set_value(vcd_range_index, values);

  return timing_violation;
}

void TimingChecker::internal_update_sim_time(std::size_t sim_time)
{
  this->sim_time_ = sim_time;
  this->checker_.set_sim_time(sim_time_);
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

  if (!header_->has_var_id_code(identifier_code_str)) {
    fmt::print("ERROR: Unknown identifier code\n"
               "  To continue execution the scalar value change is ignored\n");
    return;
  }

  auto index = header_->get_var_id_code_index(identifier_code_str);

  if (internal_event(index, value_change.value)) {
    // TODO Timing assert message
    fmt::print("TIMING ASSERT: Timing violation occurred during parsing of "
               "scalar value change\n");
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
    switch (value_char) {
    // clang-format off
      case 'x': case 'X': value_buffer_[buffer_index] = VCD::Value::x; break;
      case 'z': case 'Z': value_buffer_[buffer_index] = VCD::Value::z; break;
      case '1': value_buffer_[buffer_index] = VCD::Value::one; break;
      case '0': value_buffer_[buffer_index] = VCD::Value::x; break;
      // clang-format on
    }
  }

  // Do left extention
  VCD::Value left_extend_value;

  switch (value_buffer_[padded]) {
    // clang-format off
    case VCD::Value::one: left_extend_value = VCD::Value::zero; break;
    case VCD::Value::zero: left_extend_value = VCD::Value::zero; break;
    case VCD::Value::x: left_extend_value = VCD::Value::x; break;
    case VCD::Value::z: left_extend_value = VCD::Value::z; break;
    default:                                              // LCOV_EXCL_LINE
      puts("INTERNAL ERROR: Code should be unreachable"); // LCOV_EXCL_LINE
      std::abort();                                       // LCOV_EXCL_LINE
    // clang-format on
  }

  for (auto i : indices(padded)) {
    value_buffer_[i] = left_extend_value;
  }

  // Get range of values
  ranges::span<VCD::Value> range = value_buffer_;
  range = range.subspan(0, var_id_code.get_size());

  if (internal_event(vcd_index, range)) {
    // TODO Better timing assert message
    fmt::print("TIMING ASSERT: Timing violation occured during parsing of "
               "vector value change\n");
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

bool TimingChecker::did_assert() {
  return did_assert_;
}
