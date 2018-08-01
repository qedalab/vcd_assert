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

#ifndef LIBVCD_SERIALIZE_VARIABLE_HPP
#define LIBVCD_SERIALIZE_VARIABLE_HPP

#include "../types/variable.hpp"
#include "./enums.hpp"

#include <range/v3/algorithm/copy.hpp>
#include <string_view>

namespace VCD {

/// Serialize VCD variable declaration
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param vv The variable to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_variable(OutputIterator oi,
                        VariableView vv) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("$var "), oi);
  ranges::copy(var_type_to_string(vv.type), oi);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(std::to_string(vv.size), oi);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(vv.identifier_code, oi);
  ranges::copy(std::string_view(" "), oi);
  ranges::copy(vv.reference, oi);
  ranges::copy(std::string_view(" $end\n"), oi);
}

} // namespace VCD

#endif //LIBVCD_SERIALIZE_VARIABLE_HPP
