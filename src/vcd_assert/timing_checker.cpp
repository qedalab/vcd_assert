#include "vcd_assert/timing_checker.hpp"

#include "vcd_assert/edge_type.hpp"

#include <range/v3/view/indices.hpp>
#include <range/v3/view/linear_distribute.hpp>

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

// Iterate over all scopes. Every part of path must match a scope (instance).
/*
  If the current scope does not contain the next path segment,
      and it is not the last segment, NO match..
  If it does contain the next segment, get the index of that scope,
    set i to the index and check if it is NOW at the end of the path,
    repeat..
*/
std::optional<std::size_t>
TimingChecker::match_scope_helper(std::vector<std::string> path,
                                  std::size_t path_index,
                                  std::size_t scope_index)
{
  VCD::Scope cur_scope = header_->get_scope(scope_index);

  if (path[path_index] != cur_scope.get_identifier()) {

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
        return {/*EMPTY*/};
      }
    }
  } else {
    // no match, exit.
    return {/*EMPTY*/};
  }
}

// Starting from index 'scope_index' it tries to match 'path' to a branch of the
// scope tree and if successful, returns the index to the scope the path leads
// to.
std::optional<std::size_t>
TimingChecker::match_scope(std::vector<std::string> path,
                           std::size_t scope_index)
{
  auto starting_scope = header_->get_scope(scope_index);
  auto base_scope_identifier = starting_scope.get_identifier();

  // Find index of application scope as supplied on cmd line. if possible.
  if (path.empty()) {

    return 0; // Implicitly applied at root.

  } else if (path.size() == 1) {

    if (path[0] != base_scope_identifier) {
      return 0; // Explicitly applied at root.
    } else {
      return {/*EMPTY*/}; // Path specified not applicable/valid.
    }

  } else {
    // Not applied at root, try to find where it is applied:
    if (path[0] == base_scope_identifier) {
      return {/*EMPTY*/}; // path specified not applicable/valid.
    } else {
      return match_scope_helper(path, 0, 0);
    }
  }
}

std::optional<std::size_t>
TimingChecker::get_sdf_node_index(SDF::Node node, std::size_t scope_index,
                                  VCD::Scope &scope)
{

  auto inner_scope = scope;

  // update the scope if node name is a path
  if (node.hierarchical_identifier.has_value()) {
    auto hi = node.hierarchical_identifier.value();
    auto inner_scope_index = match_scope(hi.value, scope_index);
    if (inner_scope_index.has_value()) {
      inner_scope = header_->get_scope(inner_scope_index.value());
    } else {
      return {}; // path to variable not understood. Ignore.
    }
  }

  // get the variable from the scope
  if (inner_scope.contains_variable(node.basename_identifier)) {
    return inner_scope.get_variable_index(node.basename_identifier);
  } else {
    return {};
  }
}

// std::optional<ConditionalValuePointer>
// TimingChecker::get_sdf_node_ptr(SDF::Node node, std::size_t scope_index,
//                                   VCD::Scope &scope)
ConditionalValuePointer TimingChecker::get_sdf_node_ptr(std::size_t var_index)
{
  // get the conditional value pointer of the variable
  auto var_svp = state_.get_value_pointer(var_index);
  if (std::holds_alternative<VCD::Value *>(var_svp)) {
    auto var_svp_val = std::get<VCD::Value *>(var_svp);
    auto var_cvp = ConditionalValuePointer(var_svp_val);
    return var_cvp;
  } else {
    throw std::runtime_error("InternalError");
  }
}

ConditionalValuePointer
TimingChecker::get_sdf_conditional_ptr_helper(SDF::EqualityOperator &op,
                                              ConditionalValuePointer &left,
                                              ConditionalValuePointer &right)
{
  switch (op) {
  case SDF::EqualityOperator::case_inv:

    return ConditionalValuePointer(
        std::move(ConditionalOperator<EqualityOperator::case_not_equal>(
            std::move(left), std::move(right))));

    break;

  case SDF::EqualityOperator::case_equal:

    return ConditionalValuePointer(
        std::move(ConditionalOperator<EqualityOperator::case_equal>(
            std::move(left), std::move(right))));

    break;

  case SDF::EqualityOperator::logic_inv:

    return ConditionalValuePointer(
        std::move(ConditionalOperator<EqualityOperator::logical_not_equal>(
            std::move(left), std::move(right))));

    break;

  case SDF::EqualityOperator::logic_equal:

    return ConditionalValuePointer(
        std::move(ConditionalOperator<EqualityOperator::logical_equal>(
            std::move(left), std::move(right))));

    break;

  default:
    throw std::runtime_error("InternalError");
  }
}

std::optional<ConditionalValuePointer> TimingChecker::get_sdf_conditional_ptr(
    SDF::TimingCheckCondition cond, std::size_t scope_index, VCD::Scope &scope)
{

  auto inner_scope = scope;

  switch (cond.get_enum_type()) {
  case SDF::ConditionalType::none: /* node==1 is condition */
  {

    SDF::Node node = std::get<SDF::Node>(cond.value);

    // get the conditional value pointer of the variable
    auto left_index_op = get_sdf_node_index(node, scope_index, scope);

    if (left_index_op.has_value()) {

      auto left_cvp = get_sdf_node_ptr(left_index_op.value());

      auto right_cvp = ConditionalValuePointer(VCD::Value::zero); /// <<<<

      auto cond_op = ConditionalOperator<EqualityOperator::logical_equal>(
          std::move(left_cvp), std::move(right_cvp));

      return ConditionalValuePointer(std::move(cond_op));

    } else {
      return {};
    }

  } break;
  case SDF::ConditionalType::inverted: /* ~node or node~=1 is condition */
  {

    SDF::InvertedNode node = std::get<SDF::InvertedNode>(cond.value);

    // get the conditional value pointer of the variable
    auto left_index_op = get_sdf_node_index(node, scope_index, scope);

    if (left_index_op.has_value()) {

      auto left_cvp = get_sdf_node_ptr(left_index_op.value());

      auto right_cvp = ConditionalValuePointer(VCD::Value::zero); /// <<<<

      auto cond_op = ConditionalOperator<EqualityOperator::logical_equal>(
          std::move(left_cvp), std::move(right_cvp));

      return ConditionalValuePointer(std::move(cond_op));

    } else {
      return {};
    }

  } break;
  case SDF::ConditionalType::equality: /* node <operator> <constant> */
  {

    auto equality = std::get<SDF::NodeConstantEquality>(cond.value);
    std::size_t var_index;
    SDF::Node node = equality.left;

    // get the conditional value pointer of the variable
    auto left_index_op = get_sdf_node_index(node, scope_index, scope);

    if (left_index_op.has_value()) {

      auto left_cvp = get_sdf_node_ptr(left_index_op.value());

      auto right_cvp = equality.right
                           ? ConditionalValuePointer(VCD::Value::one)
                           : ConditionalValuePointer(VCD::Value::zero);

      return get_sdf_conditional_ptr_helper(equality.op, left_cvp, right_cvp);

    } else {
      return {};
    }

  } break;
  default:
    throw std::runtime_error("InternalError");
  }
}

// template <class ConditionalEventType, class EventType>
// std::vector<std::tuple<Event, std::size_t>>
// TimingChecker::get_sdf_port_tchk_events(std::size_t event_value,
//                                         SDF::PortTimingCheck port_tchk,
//                                         std::size_t port_vcd_index,
//                                         std::size_t scope_index,
//                                         VCD::Scope &scope)
// {
//   std::vector<std::tuple<Event, std::size_t>> events{};

//   auto port = port_tchk.port;
//   auto port_cvp = get_sdf_node_ptr(port_vcd_index);

//   std::optional<ConditionalValuePointer> cond_op_cvp_optional{};

//   if (port_tchk.timing_check_condition.has_value()) {
//     auto conditional_node_cvp_option = get_sdf_conditional_ptr(
//         port_tchk.timing_check_condition.value(), scope_index, scope);

//     if (conditional_node_cvp_option.has_value()) {

//       auto cond_op = ConditionalOperator<EqualityOperator::logical_equal>(
//           std::move(conditional_node_cvp_option.value()), std::move(port_cvp));

//       cond_op_cvp_optional = ConditionalValuePointer(std::move(cond_op));
//     }
//   }

//   /* if range */
//   if (port.end.has_value()) {
//     if (port.start.has_value()) {

//       auto sdf_port_start = port.start.value();
//       auto sdf_port_end = port.end.value();

//       auto [vcd_val_start, vcd_val_end] = index_lookup_[port_vcd_index];

//       // verify range size corresponds
//       if (vcd_val_start + sdf_port_end > vcd_val_end) {
//         fmt::printf("WARN : Ignoring extra indices specified for signal : {}",
//                     port.basename_identifier);
//       }

//       if (vcd_val_start + sdf_port_start <= vcd_val_end) {
//         for (auto &&index : indices(sdf_port_start, sdf_port_end)) {
//           if (cond_op_cvp_optional.has_value()) {
//             events.push_back(
//                 {ConditionalHoldEvent{
//                      std::move(cond_op_cvp_optional.value()),
//                      std::move(EventType{vcd_val_start + index, event_value})},
//                  vcd_val_start + index});
//           } else {
//             events.push_back(
//                 {std::move(EventType{vcd_val_start + index, event_value}),
//                  vcd_val_start + index});
//           }
//         }
//       } else {
//         // Specified starting index out of bounds.
//         // Ignore the HOLD.
//       }
//     }

//     /* if single value from a range */
//   } else if (port.start.has_value()) {

//     auto sdf_port_start = port.start.value();

//     auto [vcd_val_start, vcd_val_end] = index_lookup_[port_vcd_index];

//     if (vcd_val_start + sdf_port_start <= vcd_val_end) {
//       if (cond_op_cvp_optional.has_value()) {
//         events.push_back(
//             {ConditionalEventType{
//                  std::move(cond_op_cvp_optional.value()),
//                  EventType{vcd_val_start + sdf_port_start, event_value}},
//              vcd_val_start + sdf_port_start});
//       } else {
//         events.push_back(
//             {EventType{vcd_val_start + sdf_port_start, event_value},
//              vcd_val_start + sdf_port_start});
//       }
//     } else {
//       // Specified index does not exist.
//       // Ignore the HOLD.
//     }

//     /* if single value only */
//   } else {
//     if (cond_op_cvp_optional.has_value()) {
//       events.push_back(
//           {ConditionalEventType{std::move(cond_op_cvp_optional.value()),
//                                 EventType{port_vcd_index, event_value}},
//            port_vcd_index});
//     } else {
//       events.push_back(
//           {EventType{port_vcd_index, event_value}, port_vcd_index});
//     }
//   }
//   return std::move(events);
// }

void TimingChecker::apply_sdf_hold(std::shared_ptr<SDF::DelayFile> /*sc*/,
                                   SDF::Hold hold, std::size_t scope_index,
                                   VCD::Scope &scope)
{

  auto sdf_value = hold.value.content(); // chooses TYP for now.

  if (sdf_value.has_value()) {

    // get the indexes to reg and trig port in header
    auto reg_port_index_option =
        get_sdf_node_index(hold.reg.port, scope_index, scope);
    auto trig_port_index_option =
        get_sdf_node_index(hold.trig.port, scope_index, scope);

    if (reg_port_index_option.has_value() &&
        trig_port_index_option.has_value()) {

      auto reg_port_index = reg_port_index_option.value();
      auto trig_port_index = trig_port_index_option.value();

      // std::vector<std::tuple<Event, std::size_t>> reg_events{
      //     get_sdf_port_tchk_events<ConditionalHoldEvent, HoldEvent>(
      //         (std::size_t)(sdf_value.value() * 1000), // todo
      //         hold.reg, reg_port_index, scope_index, scope)};

      // std::vector<std::tuple<Event, std::size_t>> trig_events{
      //     get_sdf_port_tchk_events<ConditionalHoldEvent, HoldEvent>(
      //         (std::size_t)(sdf_value.value() * 1000), hold.trig,
      //         trig_port_index, scope_index, scope)};

      // if (trig_events.size() >= 1) {
      //   if (hold.trig.port.edge.has_value()) {
      //     switch (hold.trig.port.edge.value()) {
      //     case SDF::EdgeType::posedge:
      //     case SDF::EdgeType::_01:
      //       for (auto &&[event, index] : trig_events) {
      //         event_lists_[index].pos_edge.push_back(std::move(event));
      //       }
      //       break;
      //     case SDF::EdgeType::negedge:
      //     case SDF::EdgeType::_10:
      //       for (auto &&[event, index] : trig_events) {
      //         event_lists_[index].pos_edge.push_back(std::move(event));
      //       }
      //       break;
      //     default:
      //       throw std::runtime_error("InternalError : unsupported edgetype");
      //     }
      //   } else {
      //     for (auto &&[event, index] : trig_events) {
      //       event_lists_[index].pos_edge.push_back(std::move(event));
      //       event_lists_[index].neg_edge.push_back(std::move(event));
      //     }
      //   }
      // }
    }
  }
}

/*
  for all timing specifications
    considering only timing checks
      for all hold timing checks
        create hold or conditional hold for the port/values/events involved.
*/
void TimingChecker::apply_sdf_timing_specs(std::shared_ptr<SDF::DelayFile> sc,
                                           SDF::Cell cell,
                                           std::size_t scope_index, // remove
                                           VCD::Scope &scope)
{
  for (auto &&spec : cell.timing_specs) {
    switch (spec.get_enum_type()) {
    case SDF::TimingSpecType::timing_check:

      for (auto &&check : std::get<SDF::TimingCheckSpec>(spec.value)) {
        switch (check.get_enum_type()) {
        case SDF::TimingCheckType::hold: {
          apply_sdf_hold(sc, std::get<SDF::Hold>(check.value), scope_index,
                         scope);
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
// It cannot work without the Verilog parser+ast to convert instance-name ->
// module-name.
void TimingChecker::apply_sdf_cell_helper(std::shared_ptr<SDF::DelayFile> sc,
                                          SDF::Cell cell, VCD::Scope &scope)
{
  for (auto &&[ident, index] : scope.get_scopes()) {

    // cell instance scope
    VCD::Scope next_scope = header_->get_scope(index);

    if (next_scope.get_scope_type() == VCD::ScopeType::module) {
      // std::string module_name =
      // ast->get_instance_type_name(ident);

      // if(cell.cell_type.compare(module_name)){
      apply_sdf_timing_specs(sc, cell, index, next_scope);
      // }
    }

    apply_sdf_cell_helper(sc, cell, next_scope);
  }
}

void TimingChecker::apply_sdf_cell(std::shared_ptr<SDF::DelayFile> sc,
                                   SDF::Cell cell,
                                   std::size_t apply_scope_index)
{

  VCD::Scope apply_scope = header_->get_scope(apply_scope_index);

  /* IF the cell instance is blank or *, then look for
      verilog scopes of 'cell_type' among the available VCD scopes. */
  if (std::holds_alternative<SDF::Star>(cell.cell_instance)) {

    // for module/instance scopes FROM applied scope DOWN:
    apply_sdf_cell_helper(sc, cell, apply_scope);

  } else {

    /*If a specific scope is specified, check if the scope is available
      from the current root scope. */

    auto hi = std::get<SDF::HierarchicalIdentifier>(cell.cell_instance);
    if (hi.value.empty()) {
      /* for module/instance scopes in CURRENT scope ONLY: */

      for (auto &&[ident, index] : apply_scope.get_scopes()) {

        VCD::Scope scope = header_->get_scope(index);

        if (scope.get_scope_type() == VCD::ScopeType::module) {
          // std::string module_name =
          // ast->get_instance_type_name(scope.get_identifier());

          // if(cell.cell_type.compare(module_name)){
          apply_sdf_timing_specs(sc, cell, index, scope);
          // }
        }
      }

    } else {

      // ONLY the module/instance scope supplied:
      std::optional<size_t> index = match_scope(hi.value, apply_scope_index);

      if (index.has_value()) {
        VCD::Scope scope = header_->get_scope(index.value());

        // apply sdf timing specs withing cell instance
        apply_sdf_timing_specs(sc, cell, index.value(), scope);

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

  // TODO: Should always match the SDF file timescale with that of the VCD.
  // ..which could require conversion of the value.

  // auto timescale = delayfile->get_timescale();
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

[[nodiscard]] bool TimingChecker::handle_event(const RegisterEvent &event, std::size_t index, VCD::Value from, VCD::Value to)
{
  bool out = checker_.event(index, from, to);

  if (!edge_type_matches(event.edge_type, from, to))
    return out;

  if (!(event.condition.value() == VCD::Value::one))
    return out;

  checker_.hold(event.triggered, index);

  return out;
}

[[nodiscard]] bool TimingChecker::event(std::size_t index, VCD::Value value)
{
  auto& events = event_lists_.at(index).events;
  auto prev_value = state_.get_scalar_value(index);

  // Check for timing violation
  bool timing_violation = false;
  for (const auto &event : events)
    timing_violation |= handle_event(event, index, prev_value, value);

  // Update state
  state_.set_value(index, value);

  return timing_violation;
}

[[nodiscard]] bool TimingChecker::event(std::size_t range_index,
                                        ranges::span<VCD::Value> values) {
  auto prev_values = state_.get_vector_value(range_index);
  assert(values.size() == prev_values.size());

  bool timing_violation = false;
  auto range_indices = index_lookup_.at(range_index);

  // For each updated value
  for (auto i : indices(values.size())) {
    auto value = values[i];
    auto prev_value = prev_values[i];
    auto index = range_indices.from + i;

    auto& events = event_lists_.at(index).events;

    // Check for timing violation
    for (const auto &event : events)
      timing_violation |= handle_event(event, index, prev_value, values[i]);
  }

  // Update values
  state_.set_value(range_index, values);

  return timing_violation;
}

void TimingChecker::update_sim_time(std::size_t sim_time)
{
  this->sim_time_ = sim_time;
  this->checker_.update_sim_time(sim_time_);
}
