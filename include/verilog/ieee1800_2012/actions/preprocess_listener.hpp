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

#ifndef LIBVERILOG_IEEE1800_2012_GRAMMAR_PREPROCESS_LISTENER_HPP
#define LIBVERILOG_IEEE1800_2012_GRAMMAR_PREPROCESS_LISTENER_HPP

#include "../../types/design_reader.hpp"

#include <SV2012BaseListener.h>

#include <string>

namespace Verilog {

class PreprocessListener : public SV2012BaseListener
{
private:
  std::shared_ptr<SV2012Parser> parser_;
  std::shared_ptr<DesignReader> reader_;
  std::string file_path_;

public:
  PreprocessListener(std::shared_ptr<SV2012Parser> parser,
                     std::shared_ptr<DesignReader> reader,
                     std::string file_path);

  /*For building MODULE->FILE map/symbols-table */
  void enterModule_declaration(SV2012Parser::Module_declarationContext *ctx);

  /*For convertion to regular timescale annotation format*/
  void enterPp_timescale_declaration(
      SV2012Parser::Pp_timescale_declarationContext *ctx);

  /*For library file includes */
  void enterInclude_statement(SV2012Parser::Include_statementContext *ctx);

  /*For a yet unknown reason*/
  void enterSource_text(SV2012Parser::Source_textContext *ctx);
  void exitSource_text(SV2012Parser::Module_declarationContext *ctx);

  /*For package include statements */
  // virtual void
  // enterPackage_import_declaration(SV2012Parser::Package_import_declarationContext
  // * /*ctx*/) override { } virtual void
  // exitPackage_import_declaration(SV2012Parser::Package_import_declarationContext
  // * /*ctx*/) override { } virtual void
  // enterPackage_import_item(SV2012Parser::Package_import_itemContext *
  // /*ctx*/) override { } virtual void
  // exitPackage_import_item(SV2012Parser::Package_import_itemContext * /*ctx*/)
  // override { }
};

} // namespace Verilog

#endif // LIBVERILOG_IEEE1800_2012_GRAMMAR_PREPROCESS_LISTENER_HPP
