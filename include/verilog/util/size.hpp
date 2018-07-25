#ifndef LIBVERILOG_UTIL_SIZE_HPP
#define LIBVERILOG_UTIL_SIZE_HPP

#include "../types/design.hpp"

namespace Verilog::Util {

std::size_t get_max_var_size(const Design &design);
std::size_t get_max_var_size(const Design &design, std::size_t net_index);

} // namespace Verilog::Util

#endif // LIBVERILOG_UTIL_SIZE_HPP
