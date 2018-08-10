
#ifndef UNIT_VERILOG_TEST_PARSE_W_LISTENER_HPP
#define UNIT_VERILOG_TEST_PARSE_W_LISTENER_HPP

#include "./test_design.hpp"

#include "verilog/types/design.hpp"
#include "verilog/types/design_reader.hpp"

#include "parse/util/static_string.hpp"

#include "SV2012BaseListener.h"
#include "SV2012Lexer.h"
#include "SV2012Parser.h"

#include "verilog/antlr_runtime.hpp"

#include <catch2/catch.hpp>
#include <range/v3/view/zip.hpp>
#include <string>
#include <string_view>

using namespace Verilog::Test;
using namespace Verilog;
using namespace antlr4;
using namespace antlr4::tree;

namespace Verilog::Test {
using namespace Verilog;

template <typename TListener>
void parse_w_listener(std::shared_ptr<DesignReader> test_out_p,
                      std::string parse_input, std::string parse_source,
                      bool debug_output = false)
{
  INFO("Setup parse");
  ANTLRInputStream input(parse_input);

  SV2012Lexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  auto parser_sp = std::make_shared<SV2012Parser>(&tokens);

  INFO("Parse input into parse tree");
  auto *tree = parser_sp->source_text();

  if (debug_output) {
    Parse::Util::debug_print("DEBUG: parse tree start :\n");
    Parse::Util::debug_print(tree->toStringTree(parser_sp.get()));
    Parse::Util::debug_print("DEBUG: parse tree end :\n");
  }

  INFO("Initialize listener");
  TListener listen(parser_sp, test_out_p, parse_source);

  INFO("Walk tree with listener");
  ParseTreeWalker walker;
  walker.walk(&listen, tree);
}

} // namespace Verilog::Test

#endif // UNIT_VERILOG_TEST_PARSE_W_LISTENER_HPP
