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

#ifndef LIBSDF_ENUMS_HPP
#define LIBSDF_ENUMS_HPP

namespace SDF {

enum class HChar {
  dot, slash
};

enum class ConditionalType {
  simple,
  inverted,
  equality
};

enum class EqualityOperator {
  case_inv,
  case_equal,
  logic_inv,
  logic_equal
};

enum class TimeScaleUnit {
  s=15, ms=12, us=9, ns=6, ps=3, fs=0
};

enum class TimeScaleNumber {
  _1=1, _10=10, _100=100
};

enum class TimingSpecType {
  delay,
  timing_check,
  timing_env,
  label
};

enum class TimingDelayType{
  iopath,
  interconnects
};

enum class TimingCheckType {
  setup,
  hold,
  setuphold,
  recovery,
  removal,
  recrem,
  skew,
  bidirectskew,
  width,
  period,
  nochange
};

enum class DataType {
  value,
  triple,
  rvalue,
  rtriple,
  delval,
  delval_list,
  retval
};

enum class EdgeType {
  posedge,
  negedge,
  _01,
  _10,
  _0z,
  _z1,
  _1z,
  _z0
};

enum class NodeType{
  port,
  net,
  unspecified
};

enum class MinTypMax{
  min,
  typ,
  max,
  unspecified
};


} // namespace SDF

#endif // LIBSDF_ENUMS_HPP
