#include "verilog/util/size.hpp"

using namespace Verilog;

std::size_t Util::get_max_var_size(const Design& design) {
  if (design.num_nets() == 0)
    return 0;

  return get_max_var_size(design, 0);
}

std::size_t Util::get_max_var_size(const Design& design, std::size_t net_index) {
  const Net& net = design.get_net(net_index);
  std::size_t out = 0;

  for(const auto& var_pair: net.get_variables()) {
    const auto& var_ref = design.get_var(var_pair.second);
    const auto& var_id_ref = design.get_var_id_code(var_ref.get_id_code_index());

    out = std::max(out, var_id_ref.get_size());
  }

  for(const auto& net_pair: net.get_nets()) {
    auto net_max_size = get_max_var_size(design, net_pair.second);
    out = std::max(out, net_max_size);
  }

  return out;
}
