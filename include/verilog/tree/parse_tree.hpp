// ============================================================================
// Copyright 2018 Paul le Roux and Calvin Maree
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// ============================================================================

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
