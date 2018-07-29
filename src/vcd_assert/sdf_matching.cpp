#include "vcd_assert/sdf_matching.hpp"

using namespace VCDAssert;

ConditionalValuePointer VCDAssert::get_sdf_node_ptr(State &state,
                                                    std::size_t var_index)
{
  // get the conditional value pointer of the variable
  auto var_svp = state.get_value_pointer(var_index);
  if (std::holds_alternative<VCD::Value *>(var_svp)) {
    auto var_svp_val = std::get<VCD::Value *>(var_svp);
    auto var_cvp = ConditionalValuePointer(var_svp_val);
    return var_cvp;
  } else {
    throw std::runtime_error("InternalError");
  }
}

// Starting from index 'scope_index' it tries to match 'path' to a branch of the
// scope tree and if successful, returns the index to the scope the path leads
// to.
std::optional<std::size_t> VCDAssert::match_scope(const VCD::Header &header,
                                                  std::vector<std::string> path,
                                                  std::size_t scope_index)
{
  auto starting_scope = header.get_scope(scope_index);
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
      return match_scope_helper(header, path, 0, 0);
    }
  }
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
VCDAssert::match_scope_helper(const VCD::Header &header,
                              std::vector<std::string> path,
                              std::size_t path_index, std::size_t scope_index)
{
  VCD::Scope cur_scope = header.get_scope(scope_index);

  if (path[path_index] != cur_scope.get_identifier()) {

    // move to next path segment
    std::size_t new_path_index = path_index + 1;

    if (path.size() == new_path_index) {
      return scope_index; // successfully found the last identifier in path.
    } else {
      if (cur_scope.contains_scope(path[new_path_index])) {
        return match_scope_helper(
            header, path, new_path_index,
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

ConditionalValuePointer
VCDAssert::get_sdf_conditional_ptr_helper(SDF::EqualityOperator op,
                                          ConditionalValuePointer left,
                                          ConditionalValuePointer right)
{
  switch (op) {
  case SDF::EqualityOperator::case_inv:
    return ConditionalOperator<EqualityOperator::case_not_equal>(
        std::move(left), std::move(right));
    break;

  case SDF::EqualityOperator::case_equal:
    return ConditionalOperator<EqualityOperator::case_equal>(std::move(left),
                                                             std::move(right));
    break;

  case SDF::EqualityOperator::logic_inv:
    return ConditionalOperator<EqualityOperator::logical_not_equal>(
        std::move(left), std::move(right));
    break;

  case SDF::EqualityOperator::logic_equal:
    return ConditionalOperator<EqualityOperator::logical_equal>(
        std::move(left), std::move(right));
    break;

  default:                                         // LCOV_EXCL_LINE
    std::puts("INTERNAL ERROR: Unreachable code"); // LCOV_EXCL_LINE
    std::abort();                                  // LCOV_EXCL_LINE
  }
}

std::optional<std::size_t>
VCDAssert::get_sdf_node_index(const VCD::Header &header, SDF::Node node,
                              std::size_t scope_index, const VCD::Scope &scope)
{

  auto inner_scope = scope;

  // update the scope if node name is a path
  if (node.hierarchical_identifier.has_value()) {
    auto hi = node.hierarchical_identifier.value();
    auto inner_scope_index = match_scope(header, hi.value, scope_index);
    if (inner_scope_index.has_value()) {
      inner_scope = header.get_scope(inner_scope_index.value());
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

std::optional<ConditionalValuePointer>
VCDAssert::get_sdf_conditional_ptr(const VCD::Header &header, State &state,
                        SDF::TimingCheckCondition cond, std::size_t scope_index,
                        VCD::Scope &scope)
{

  auto inner_scope = scope;

  switch (cond.get_enum_type()) {
  case SDF::ConditionalType::none: /* node==1 is condition */
  {

    SDF::Node node = std::get<SDF::Node>(cond.value);

    // get the conditional value pointer of the variable
    auto left_index_option = get_sdf_node_index(header, node, scope_index, scope);

    if (left_index_option.has_value()) {

      auto left_cvp = get_sdf_node_ptr(state, left_index_option.value());

      auto right_cvp = ConditionalValuePointer(VCD::Value::zero); /// <<<<

      auto cond_op = ConditionalOperator<EqualityOperator::logical_equal>(
          std::move(left_cvp), std::move(right_cvp));

      return ConditionalValuePointer(std::move(cond_op));

    } else {
      return {}; // not found
    }

  } break;
  case SDF::ConditionalType::inverted: /* ~node or node~=1 is condition */
  {

    SDF::InvertedNode node = std::get<SDF::InvertedNode>(cond.value);

    // get the conditional value pointer of the variable
    auto left_index_option = get_sdf_node_index(header, node, scope_index, scope);

    if (left_index_option.has_value()) {

      auto left_cvp = get_sdf_node_ptr(state, left_index_option.value());

      auto right_cvp = ConditionalValuePointer(VCD::Value::zero); /// <<<<

      auto cond_op = ConditionalOperator<EqualityOperator::logical_equal>(
          std::move(left_cvp), std::move(right_cvp));

      return ConditionalValuePointer(std::move(cond_op));

    } else {
      return {}; // not found
    }

  } break;
  case SDF::ConditionalType::equality: /* node <operator> <constant> */
  {

    auto equality = std::get<SDF::NodeConstantEquality>(cond.value);
    // std::size_t var_index;
    SDF::Node node = equality.left;

    // get the conditional value pointer of the variable
    auto left_index_option = get_sdf_node_index(header, node, scope_index, scope);

    if (left_index_option.has_value()) {

      auto left_cvp = get_sdf_node_ptr(state, left_index_option.value());

      auto right_cvp = equality.right
                           ? ConditionalValuePointer(VCD::Value::one)
                           : ConditionalValuePointer(VCD::Value::zero);

      return {get_sdf_conditional_ptr_helper(equality.op, std::move(left_cvp), std::move(right_cvp))};

    } else {
      return {}; // not found
    }

  } break;
  default:
    break;
  }

  // Should return before this
  std::puts("INTERNAL ERROR: Code should not be reachable");
  std::abort();
}
