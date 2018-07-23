#ifndef LIBVCD_UTIL_SIZE_HPP
#define LIBVCD_UTIL_SIZE_HPP

#include "../types/header.hpp"

namespace VCD::Util {

std::size_t get_max_var_size(const Header& header);
std::size_t get_max_var_size(const Header& header, std::size_t scope_index);

} // sadf

#endif // LIBVCD_UTIL_SIZE_HPP
