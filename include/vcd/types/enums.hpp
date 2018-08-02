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

#ifndef LIBVCD_TYPES_ENUMS_HPP
#define LIBVCD_TYPES_ENUMS_HPP

namespace VCD {

/// VCD Scope type enum
enum class ScopeType {
  begin, fork, function, module, task
};

/// VCD Time number enum
enum class TimeNumber {
  _1=1, _10=10, _100=100
};

/// VCD Time unit enum
enum class TimeUnit {
  s=15, ms=12, us=9, ns=6, ps=3, fs=0
};

/// VCD Variable type enum
enum class VarType {
  event, integer, parameter, real, realtime, reg, supply0, supply1, time,
  tri, triand, trior, trireg, tri0, tri1, wand, wire, wor
};

/// VCD Variable value enum
enum class Value {
  zero, one, x, z
};

/// VCD $dump types enum
enum class DumpType {
  all, off, on, vars
};

} // namespace VCD

#endif // LIBVCD_TYPES_ENUMS_HPP
