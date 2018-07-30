#ifndef LIBVERILOG_IEEE1364_2001_GRAMMAR_UPD_HPP
#define LIBVERILOG_IEEE1364_2001_GRAMMAR_UPD_HPP

#include <iostream>
#include <string>
#include <type_traits>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

namespace Verilog {
namespace IEEE1364_2001 {

// select which rules in the grammar will produce parse tree nodes:

// clang-format off

// by default, nodes are not generated/stored
template< typename > struct store : std::false_type {};

// select which rules in the grammar will produce parse tree nodes:
template<> struct store< integer > : std::true_type {};
template<> struct store< variable > : std::true_type {};

template<> struct store< plus > : parse_tree::remove_content {};
template<> struct store< minus > : parse_tree::remove_content {};
template<> struct store< multiply > : parse_tree::remove_content {};
template<> struct store< divide > : parse_tree::remove_content {};

} // namespace Grammar
} // namespace Verilog

#endif // LIBVERILOG_IEEE1364_2001_GRAMMAR_UPD_HPP
