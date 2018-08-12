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

#ifndef LIBVERILOG_IEEE1800_2012_PARSE_HPP
#define LIBVERILOG_IEEE1800_2012_PARSE_HPP

#include "verilog/types/design.hpp"
#include "verilog/types/design_reader.hpp"

#include "verilog/antlr_runtime.hpp"
#include "verilog/util/parse_input.hpp"

#include <SV2012BaseListener.h>
#include <SV2012Lexer.h>
#include <SV2012Parser.h>

#include <parse/util/filesystem.hpp>
#include <parse/util/static_string.hpp>

#include <range/v3/view/indices.hpp>
#include <range/v3/view/zip.hpp>

#include <tuple>

namespace rsv = ranges::view;

namespace Verilog {
namespace IEEE1800_2012 {

using namespace Verilog;
using namespace Verilog::Util;
using namespace antlr4;
using namespace antlr4::tree;

// template <std::size_t n, typename = std::make_index_sequence<n>>
// struct nth_element_impl;

// template <std::size_t n, std::size_t... ignore>
// struct nth_element_impl<n, std::index_sequence<ignore...>> {
//   template <typename Tn>
//   static Tn f(decltype((void *)ignore)..., Tn *, ...);
// };

// template <typename T>
// struct wrapper {
//   using type = T;
// };

// template <std::size_t n, typename... T>
// using nth_element = typename decltype(
//     nth_element_impl<n>::f(static_cast<wrapper<T> *>(0)...))::type;

// // template <typename.. TListeners, class N = sizeof...(TListeners)>
// // template <typename TListener>
// template <class... TListeners, size_t n = sizeof...(TListeners)>
// bool parse_w_listeners(std::shared_ptr<DesignReader> designreader_p,
//                        std::vector<Verilog::Util::ParseInput> parse_input_v)
// {

// template <class TListener, class Parser, class ParseTree, class Reader>
// void walk_w_listeners(Parser parser, ParseTree tree, Reader reader,
//                       std::string source) //, TListenerFirst value)
// {
//   ParseTreeWalker walker;
//   TListener listen(parser, reader, source);

//   Parse::Util::debug_puts("\nDEBUG:Walk tree with listener\n");
//   walker.walk(&listen, tree);
//   Parse::Util::debug_puts("Finish walk");
// }

// template < class TListener, class... TListenersRest, class Parser, class
// ParseTree, class Reader> void walk_w_listeners(Parser parser, ParseTree tree,
// Reader reader,
//                       std::string source) //, TListenerFirst first,
//                                           // TListenerFirstRest... rest)
// {

//   walk_w_listeners<Parser, ParseTree, Reader, TListener>(parser, tree,
//   reader,
//                                                          source);
//   walk_w_listeners<Parser, ParseTree, Reader, TListenersRest...>(
//       parser, tree, reader, source);
// }

// template < class ParseTreeWalker, class ParseTree, class TListener, class...
// TListenersRest> void walk_w_listeners(ParseTreeWalker walker, ParseTree tree,
// SV2012BaseListener... listeners)
// {

template <class ParseTree>
void walk_w_listeners(std::shared_ptr<ParseTreeWalker> walker, ParseTree tree,
                      std::vector<std::shared_ptr<SV2012BaseListener>> listeners)
{
  for (auto &&listen : listeners) {
    Parse::Util::debug_puts("\nDEBUG:Walk tree with listener\n");
    walker->walk(listen.get(), tree.get());
    Parse::Util::debug_puts("Finish walk");
  }
}

/*
  Initialize the ANTRL parser and parse tree (source text context)
*/
std::vector<
    std::tuple<std::shared_ptr<ParseTreeWalker>, std::shared_ptr<SV2012Parser>,
               std::shared_ptr<SV2012Parser::Source_textContext>, std::string>>
init_antlr_parsers(std::vector<Verilog::Util::ParseInput> parse_input_v)
{

  std::vector<std::tuple<
      std::shared_ptr<ParseTreeWalker>, std::shared_ptr<SV2012Parser>,
      std::shared_ptr<SV2012Parser::Source_textContext>, std::string>>
      result{};

  for (auto &&parse_input : parse_input_v) {

    Parse::Util::debug_print("\nDEBUG: Start parse ({})\n", parse_input.name);
    std::string parse_source;
    std::optional<ANTLRInputStream> input_op = {};

    if (parse_input.type == Util::InputTypeEnum::memory) {

      parse_source = std::string(std::get<const char *>(parse_input.value));
      input_op = ANTLRInputStream(parse_source);

    } else if (parse_input.type == Util::InputTypeEnum::source_file) {

      parse_source = std::get<std::string>(parse_input.value);
      std::ifstream stream;
      stream.open(parse_source);
      input_op = ANTLRInputStream(stream);

    } else {
      throw std::runtime_error("InternalError(library_file unsupported)");
    }

    if (input_op.has_value()) {
      SV2012Lexer lexer(&input_op.value());
      lexer.removeErrorListeners();

      CommonTokenStream tokens(&lexer);

      auto parser = std::make_shared<SV2012Parser>(&tokens);
      parser->removeErrorListeners();

      Parse::Util::debug_puts("DEBUG: Create Verilog parse tree");
      auto *tree = parser->source_text();
      std::shared_ptr<SV2012Parser::Source_textContext> tree_sp(tree);
      std::shared_ptr<ParseTreeWalker> walker = std::make_shared<ParseTreeWalker>();

      result.emplace_back(std::make_tuple(std::move(walker), std::move(parser),
                                          std::move(tree_sp), std::move(parse_source)));

    } else {
      throw std::runtime_error(
          "InternalError(could not create antlr stream from input)");
    }
  }
  return result;
}

} // namespace IEEE1800_2012
} // namespace Verilog

#endif // LIBVERILOG_IEEE1800_2012_PARSE_HPP
