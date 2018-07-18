#include "vcd_assert/timing_checker.hpp"

#include "vcd_assert/edge_type.hpp"

#include <range/v3/view/indices.hpp>

using namespace VCDAssert;
using namespace ranges::view;

TimingChecker::TimingChecker(std::shared_ptr<VCD::Header> header) :
    header_(std::move(header)),
    state_(*header),
    checker_(state_.num_total_values()),
    event_lists_(state_.num_total_values())
{
  index_lookup_.reserve(state_.num_values());

  std::size_t counter = 0;

  for (auto i : indices(state_.num_values())) {
    auto var_id_code_view = header->get_var_id_code(i);
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
}

std::optional<std::size_t>
TimingChecker::match_scope_helper(std::vector<std::string> path,
                                  std::size_t path_index,
                                  std::size_t scope_index)
{
  // Iterate over all scopes. Every part of path must match a scope (instance).
  /*
    If the current scope does not contain the next path segment,
        and it is not the last segment, NO match..
    If it does contain the next segment, get the index of that scope,
      set i to the index and check if it is NOW at the end of the path,
      repeat..
  */
  VCD::Scope cur_scope = header_->get_scope(scope_index);

  if (path[path_index].compare(cur_scope.get_identifier())) {

    // move to next path segment
    std::size_t new_path_index = path_index + 1;

    if (path.size() == new_path_index) {
      return scope_index; // successfully found the last identifier in path.
    } else {
      if (cur_scope.contains_scope(path[new_path_index])) {
        return match_scope_helper(
            path, new_path_index,
            cur_scope.get_scope_index(path[new_path_index]));
      } else {
        return {};
      }
    }
  } else {
    // no match, exit.
    return {};
  }
}



// Starting from index 'scope_index' it tries to match 'path' to a branch of the
// scope tree and if successful, returns the index to the scope the path leads
// to.
std::optional<std::size_t>
TimingChecker::match_scope(std::vector<std::string> path,
                           std::size_t scope_index)
{

  auto base_scope_identifier = header_->get_scope(scope_index).get_identifier();

  // Find index of application scope as supplied on cmd line. if possible.
  if (path.size() == 0) {

    return 0; // Implicitly applied at root.

  } else if (path.size() == 1) {

    if (path[0].compare(base_scope_identifier)) {
      return 0; // Explicitly applied at root.
    } else {
      return {}; // Path specified not applicable/valid.
    }

  } else {
    // Not applied at root, try to find where it is applied:
    if (!path[0].compare(base_scope_identifier)) {
      return {}; // path specified not applicable/valid.
    } else {
      return match_scope_helper(path, 0, 0);
    }
  }
}

void TimingChecker::apply_sdf_hold(std::shared_ptr<SDF::DelayFile> sc,
                                   SDF::Hold hold){

    //should be able to spec edge on either port_tchk.

    //should be able to spec edge on either port_tchk.

  auto value = hold.value.content(); //chooses TYP for now.
  if(value.has_value()){
    // HoldEvent he{index, value};  
    
  }else{

  }
}

void TimingChecker::apply_sdf_timing_specs(std::shared_ptr<SDF::DelayFile> sc,
                                           SDF::Cell cell,
                                           std::size_t scope_index)
{
  /*
    for all timing specs,
      considering only timing checks
        for all hold timing checks
          create hold or conditional hold for the port/values/events involved.
  */
  for (auto &&spec : cell.timing_specs) {
    switch (spec.get_enum_type()) {
    case SDF::TimingSpecType::timing_check:

      for(auto&& check : std::get<SDF::TimingCheckSpec>(spec.value)) {
        switch (check.get_enum_type()) {
        case SDF::TimingCheckType::hold:
          SDF::Hold hold = std::get<SDF::Hold>(check.value);
            apply_sdf_hold(sc, hold);
          break;

        }
      }
      break;

    }
  }
}

// This is called when the * cell instances wildcard is supplied.
// It cannot work without the Verilog parser+ast to convert instance-name ->
// module-name.
void TimingChecker::apply_sdf_cell_helper(std::shared_ptr<SDF::DelayFile> sc,
                                          SDF::Cell cell,
                                          std::size_t scope_index)
{
  VCD::Scope input_scope = header_->get_scope(scope_index);

  for (auto && [ident, index]  : input_scope.get_scopes()) {
    // auto && = i.get(1);
    VCD::Scope scope_i = header_->get_scope(index);

    if (scope_i.get_scope_type() == VCD::ScopeType::module) {
      // std::string module_name =
      // ast->get_instance_type_name(ident);

      // if(cell.cell_type.compare(module_name)){
      apply_sdf_timing_specs(sc, cell, index);
      // }
    }

    apply_sdf_cell_helper(sc, cell, index);
  }
}

void TimingChecker::apply_sdf_cell(std::shared_ptr<SDF::DelayFile> sc,
                                   SDF::Cell cell, 
                                   std::size_t scope_index)
{

  /* IF the cell instance is blank or *, then look for
      verilog scopes of 'cell_type' among the available VCD scopes. */
  if (std::holds_alternative<SDF::Star>(cell.cell_instance)) {

    // for module/instance scopes FROM applied scope DOWN:
    apply_sdf_cell_helper(sc, cell, scope_index);

  } else {

    /*If a specific scope is specified, check if the scope is available
      from the current root scope. */

    auto hi = std::get<SDF::HierarchicalIdentifier>(cell.cell_instance);
    if (hi.value.size() == 0) {
      /* for module/instance scopes in CURRENT scope ONLY: */

      VCD::Scope input_scope = header_->get_scope(scope_index);

      for (auto &&[ident, index] : input_scope.get_scopes()) {

        VCD::Scope scope_i = header_->get_scope(index);

        if (scope_i.get_scope_type() == VCD::ScopeType::module) {
          // std::string module_name =
          // ast->get_instance_type_name(scope_i.get_identifier());

          // if(cell.cell_type.compare(module_name)){
          apply_sdf_timing_specs(sc, cell, index);
          // }
        }
      }

    } else {

      // ONLY the module/instance scope supplied:
      auto match_index = match_scope(hi.value, scope_index);
      if (match_index.has_value()) {
        apply_sdf_timing_specs(sc, cell, match_index.value());
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

For every scope in the vcd, check whether the given node falls within the scope.
If not, increment the index and check its inner scopes(could record the indexes
that are checked so they can be skipped). Once the the application scope is
found, it becomes the SDF's root.

The cells with explicit instances are incrementally matched via scope walking to
  get to the "leaf" scope. Once the leaf scope is found, check its type in the
verilog to make sure it matches the type (optional).

The cells with no instances given only applicable at the current scope to cells
of the given type. In this case, get the scope type and go through the top level
scopes checking each's type. When scopes are found that match, go through the
assertions in the cell and map each to the variables.

//Timing checker should also consolodate that all sdf files contain the same :
//    sdf_version
//    design_name
//    [process]
//    [voltage]
//    [temperature]
*/
void TimingChecker::apply_sdf_file(/*VerilogSourceTree *ast, */
                                   std::shared_ptr<SDF::DelayFile> delayfile,
                                   std::vector<std::string> vcd_node_path)
{
  std::optional<std::size_t> apply_at_index = match_scope(vcd_node_path, 0);

  // Should always match the SDF file timescale with that of the VCD.
  // ..which could require conversion of the value.
  auto timescale = delayfile->get_timescale();
  std::vector<SDF::Cell> cells = delayfile->get_cells();
  /*etc*/

  if (apply_at_index.has_value()) {
    for (auto &cell : cells) {
      apply_sdf_cell(delayfile, cell, apply_at_index.value());
    }
  } else {
    // could not find the supplied scope.
  }
}

[[nodiscard]] bool TimingChecker::handle_event(const Event &event) {
  return std::visit(
      [&](auto &typed_event) -> bool {
        using T = typename std::decay<decltype(typed_event)>::type;

        if constexpr (std::is_same_v<T, HoldEvent>) {
          // Hold Event
          checker_.hold(sim_time_, typed_event.index, typed_event.hold_time);
          return false;

        } else if constexpr (std::is_same_v<T, SetupEvent>) {
          // Setup Event
          return checker_.setup(sim_time_, typed_event.index,
                                typed_event.setup_time);

        } else if constexpr (std::is_same_v<T, ConditionalSetupEvent>) {
          // Conditional Setup Event
          if (typed_event.condition.value() != VCD::Value::one)
            return false;

          auto e = typed_event.event;
          return checker_.setup(sim_time_, e.index, e.setup_time);
        } else if constexpr (std::is_same_v<T, ConditionalHoldEvent>) {
          // Conditional Hold Event
          if (typed_event.condition.value() != VCD::Value::one)
            return false;

          auto e = typed_event.event;
          checker_.hold(sim_time_, e.index, e.hold_time);
          return false;
        } else {
          // Did not handle type
          static_assert(Parse::Util::dependent_value<false, T>);
        }
      },
      event);
}

    [[nodiscard]] bool TimingChecker::event(std::size_t time, std::size_t index,
                                            VCD::Value value)
{
  update_sim_time(time);

  auto prev_value = state_.get_scalar_value(index);

  auto edge_type = get_edge_type(prev_value, value);

  auto events = event_lists_.at(index).get_event_list(edge_type);

  // Check for timing violation
  bool timing_violation = false;
  for (const auto &event : events)
    timing_violation |= handle_event(event);

  timing_violation |= checker_.event(index, sim_time_);

  // Update state
  state_.set_value(index, value);

  return timing_violation;
}

[[nodiscard]] bool TimingChecker::event(std::size_t time, std::size_t index,
                                        ranges::span<VCD::Value> values) {
  update_sim_time(time);

  auto prev_values = state_.get_vector_value(index);

  assert(prev_values.size() == values.size());

  bool timing_violation = false;

  // For each updated value
  for (auto i : indices(values.size())) {
    auto prev_value = prev_values[i];
    auto value = values[i];

    auto edge_type = get_edge_type(prev_value, value);
    auto events = event_lists_.at(index).get_event_list(edge_type);

    // Check for timing violation
    for (const auto &event : events)
      timing_violation |= handle_event(event);

    timing_violation |= checker_.event(index, sim_time_);
  }

  // Update values
  state_.set_value(index, values);

  return timing_violation;
}

void TimingChecker::update_sim_time(std::size_t sim_time_)
{
}
