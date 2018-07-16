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

//Assuming the scope node is the header (as in the LRM), I dont see 
//what the "std::size_t vcd_scope_node" was meant for.
void TimingChecker::apply_sdf(std::shared_ptr<SDF::DelayFile> delayfile, std::size_t vcd_scope_node)
{
  //Timing checker should consolodate that all sdf files contain the same :
  //    sdf_version
  //    design_name
  //    [process]
  //    [voltage]
  //    [temperature]

  // Should always match the SDF file timescale with that of the VCD.
  // ..which could require conversion of the value.
  SDF::TimeScale delayfile.get_timescale();
  std::vector<Cell> cells = delayfile.get_cells();

  for(auto&& cell : cells) {

    // IF the cell instance is blank or *, then look for 
    //   verilog scopes of 'cell_type' among the available VCD scopes.

 

    if(std::holds_alternative<SDF::Star>(cell.cell_instance)){
      for(auto&& scope : header_.get_scopes) {
      // For the given scopes found, apply the specs.      
        for all scopes.
    }else{
      /*IF a specific scope is specified, check if the scope is available 
        from the current root scope. */
      auto hi = std::get<SDF::HierarchicalIdentifier>(cell.cell_instance);
      only for scope hi.
    }
  }
}

void TimingChecker::match_scope(){
    /* 
      for all timing specs, 
        considering only timing checks 
          for all hold timing checks
            create hold or conditional hold for the 
  */ 

    for(auto&& spec : cell.timing_specs) {
      switch(spec.get_enum_type()) {
      case TimingSpecType::TimingCheck:
        for(auto&& check : std::get<TimingCheckSpec>) {
          switch(check.get_enum_type()) {
          case TimingCheckType::Hold:
            
          default:
            assert(false && "Invalid enum state");
            abort();
          }
        }
      default:
        assert(false && "Invalid enum state");
        abort();
      }
    }
  }

}

[[nodiscard]] bool TimingChecker::handle_event(const Event &event)
{
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
      }, event);
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
                                        ranges::span<VCD::Value> values)
{
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
