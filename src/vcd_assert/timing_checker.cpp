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


/*

For every application scope(appscope), find its node in the verilog ast.
Create the path to the appscope in therms of instance names(not module/type names)
Then go through

For every scope in the vcd, check whether the given node falls within the scope. If not, increment the index and check its inner scopes(could record the indexes that are checked so they can be skipped). Once the the application scope is found, it becomes the SDF's root. 

The cells with explicit instances are incrementally matched via scope walking to 
  get to the "leaf" scope. Once the leaf scope is found, check its type in the verilog
  to make sure it matches the type (optional).

The cells with no instances given only applicable at the current scope to cells of the given type.  
  In this case, get the scope type and go through the top level scopes checking each's type.
  When scopes are found that match, go through the assertions in the cell and map each to the variables.

*/
void TimingChecker::match_scope_helper(){
  // for (auto &inner_test_scope : test.scopes) {
  //   auto scope_index = scope.get_scope_index(inner_test_scope.identifier);
  //   auto &inner_scope = get_scope(scope_index);
  //   recursive(inner_scope, inner_test_scope);
  // }
}

bool TimingChecker::match_scope(SDF::Cell cell, std::size_t scope_index) {
    /* 
      for all timing specs, 
        considering only timing checks 
          for all hold timing checks
            create hold or conditional hold for the 
  */
  // for(auto&& spec : cell.timing_specs) {
  //   switch(spec.get_enum_type()) {
  //   case TimingSpecType::TimingCheck:
  //     for(auto&& check : std::get<TimingCheckSpec>) {
  //       switch(check.get_enum_type()) {
  //       case TimingCheckType::Hold:
  //         break;
  //       default:
  //         assert(false && "Invalid enum state");
  //         abort();
  //       }
  //     }
  //   default:
  //     assert(false && "Invalid enum state");
  //     abort();
  //   }
  // }
  return 0;
}

void TimingChecker::apply_sdf(VerilogSourceTree *ast, 
                              std::shared_ptr<SDF::DelayFile> delayfile, 
                              std::vector<std::string> vcd_node_path)
{
  //Timing checker should consolodate that all sdf files contain the same :
  //    sdf_version
  //    design_name
  //    [process]
  //    [voltage]
  //    [temperature]

  std::optional<size_t> apply_at_index;
  VCD::Scope cur_scope = header_->get_root_scope(); //TODO node->scope not root.
  auto& root_identifier = cur_scope.get_identifier();
  // std::vector<std::string> path{root_identifier};
  if(vcd_node_path.size() == 0){
    apply_at_index = 0;
  }else if(vcd_node_path.size() == 1){
    /*ASSUMPTION: single node ident must be root..*/
    if(vcd_node_path[0].compare(root_identifier) ){
      apply_at_index = 0;
    }else{
      //path specified not applicable/valid.
    }
  }else{
    //Iterate over all scopes. Every part of path must match a (instance) scope.
    size_t path_index = 0;
    // size_t scope_index = 0;
    for (auto&& i : ranges::view::indices(header_->num_scopes()) {
      cur_scope = header_->get_scope(i);
      
      if(vcd_node_path[path_index].compare(scope.get_identifier())){
        path_index++;
        scope_index++;
        if(vcd_node_path.size() == path_index){
          //successfully found the last identifier in path.
          break;
        }
        if(scope.contains_scope(node)){
        apply_at_index = i;
        /*OR
          scope_index = cur_scope.get_scope_index(node);
        */
      }
      }else{

      }
      
    }//hence the sdf file was applied at node with index i.
    if(scope_index)
    apply_at_index = scope_index

  }

  // Find the scope as supplied on cmd line. if possible.
  if(apply_at_index.has_value(){
    //Not applied at root, try to find where it is applied:


  }else{
    //could not find the supplied scope.
  }
  



  // // Should always match the SDF file timescale with that of the VCD.
  // // ..which could require conversion of the value.
  // SDF::TimeScale delayfile.get_timescale();
  // std::vector<Cell> cells = delayfile.get_cells();
  // /*etc*/

  // for(auto&& cell : cells) {

  //   // IF the cell instance is blank or *, then look for 
  //   //   verilog scopes of 'cell_type' among the available VCD scopes.

  //   if(std::holds_alternative<SDF::Star>(cell.cell_instance)){
  //     for(auto&& scope : header_.get_scopes) {
  //     // For the given scopes found, apply the specs.      
  //       for all scopes.
  //   }else{
  //     /*IF a specific scope is specified, check if the scope is available 
  //       from the current root scope. */
  //     auto hi = std::get<SDF::HierarchicalIdentifier>(cell.cell_instance);
  //     only for scope hi.
  //   }
  // }
  
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
