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
