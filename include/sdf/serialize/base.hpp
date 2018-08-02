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

#ifndef LIBSDF_SERIALIZE_BASE_HPP
#define LIBSDF_SERIALIZE_BASE_HPP

#include <sdf/types/base.hpp>

#include <range/v3/algorithm/copy.hpp>
#include <string_view>


namespace SDF {


template <class OutputIterator>
void serialize_indent(OutputIterator oi,
                      int indent) noexcept(noexcept(*oi++ = '!')) {
  for (int i = 0; i < indent; i++) {
    ranges::copy(std::string_view("  "), oi);
  }
}


template <class OutputIterator>
void serialize_quoted(OutputIterator oi,
                      std::string_view input) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("\""), oi);
  ranges::copy(input, oi);
  ranges::copy(std::string_view("\""), oi);
}

template <class OutputIterator, typename T, typename... Ts>
void serialize_quoted_alt(OutputIterator oi, T (*inner)(Ts...),
                          Ts &&... args) noexcept(noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("\""), oi);
  inner(oi, std::forward<Ts>(args)...);
  ranges::copy(std::string_view("\""), oi);
}

/// Serialize hierarchical identifier 
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param hi The HierarchicalIdentifier to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_hierarchical_identifier(
    OutputIterator oi, int /*unused*/,
    HierarchicalIdentifier hi) noexcept(noexcept(*oi++ = '!')) {
  auto sep = hi.sep == HChar::dot ? std::string_view(".") : std::string_view("/");
  auto size = hi.value.size();
  for(auto&& str : hi.value){
    --size;
    ranges::copy(str, oi);
    if(size > 0)
      ranges::copy(sep, oi);    
  }
}

// /// Serialize SDF HierarchicalIdentifier
// /// \tparam OutputIterator must meet the requirements of OutputIterator
// /// \param oi The OutputIterator being written to
// /// \param comment The comment to write
// /// \exception Throws if writing to the OutputIterator throws otherwise noexcept
// template <class OutputIterator>
// void serialize_hierarchical_identifier(
//     OutputIterator oi, int indent, std::string_view hi) noexcept(noexcept(*oi++ = '!')) {

//   for
//   ranges::copy(hi, oi);

// }

/// Serialize SDF comment
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param comment The comment to write
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_comment_ml(OutputIterator oi, std::string_view comment) noexcept(
    noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("/*"), oi);
  ranges::copy(comment, oi);
  ranges::copy(std::string_view("*/"), oi);
}

/// Serialize SDF comment
/// \tparam OutputIterator must meet the requirements of OutputIterator
/// \param oi The OutputIterator being written to
/// \param comment The comment to write (may not contain new line character)
/// \exception Throws if writing to the OutputIterator throws otherwise noexcept
template <class OutputIterator>
void serialize_comment_sl(OutputIterator oi, std::string_view comment) noexcept(
    noexcept(*oi++ = '!')) {
  ranges::copy(std::string_view("//"), oi);
  ranges::copy(comment, oi);
  ranges::copy(std::string_view("\n"), oi);
}

} // namespace SDF

#endif // LIBSDF_SERIALIZE_BASE_HPP
