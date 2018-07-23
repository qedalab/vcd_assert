#include "vcd/util/size.hpp"

using namespace VCD;

std::size_t Util::get_max_var_size(const Header& header) {
  if (header.num_scopes() == 0)
    return 0;

  return get_max_var_size(header, 0);
}

std::size_t Util::get_max_var_size(const Header& header, std::size_t scope_index) {
  const Scope& scope = header.get_scope(scope_index);
  std::size_t out = 0;

  for(const auto& var_pair: scope.get_variables()) {
    const auto& var_ref = header.get_var(var_pair.second);
    const auto& var_id_ref = header.get_var_id_code(var_ref.get_id_code_index());

    out = std::max(out, var_id_ref.get_size());
  }

  for(const auto& scope_pair: scope.get_scopes()) {
    auto scope_max_size = get_max_var_size(header, scope_pair.second);
    out = std::max(out, scope_max_size);
  }

  return out;
}
