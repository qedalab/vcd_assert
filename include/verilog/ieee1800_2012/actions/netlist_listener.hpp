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

#ifndef LIBVERILOG_IEEE1800_2012_GRAMMAR_NETLIST_LISTENER_HPP
#define LIBVERILOG_IEEE1800_2012_GRAMMAR_NETLIST_LISTENER_HPP

#include "../../types/design_reader.hpp"
#include <SV2012BaseListener.h>
#include <string>

namespace Verilog {

class NetlistListener : SV2012BaseListener
{
private:
  std::shared_ptr<SV2012Parser> parser_;
  std::shared_ptr<DesignReader> reader_;
  // size_t module_i_;

public:
  NetlistListener(std::shared_ptr<SV2012Parser> parser,
                  std::shared_ptr<DesignReader> reader);

  void enterModule_declaration(SV2012Parser::Module_declarationContext *ctx);
  void exitModule_declaration(SV2012Parser::Module_declarationContext *ctx);

  void
  enterModule_instantiation(SV2012Parser::Module_instantiationContext *ctx);
  void exitModule_instantiation(SV2012Parser::Module_instantiationContext *ctx);

  void enterGate_instantiation(SV2012Parser::Gate_instantiationContext *ctx);
  void exitGate_instantiation(SV2012Parser::Gate_instantiationContext *ctx);
};

} // namespace Verilog

#endif // LIBVERILOG_IEEE1800_2012_GRAMMAR_NETLIST_LISTENER_HPP
