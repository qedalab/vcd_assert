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

#include "vcd_assert/actions.hpp"
#include "vcd_assert/sdf_matching.hpp"
#include "vcd_assert/timing_checker.hpp"
#include "vcd_assert/version.hpp"

#include "vcd/actions/header.hpp"
#include "vcd/grammar/grammar.hpp"
#include "vcd/types/header_reader.hpp"

#include <sdf/actions/base.hpp>
#include <sdf/grammar/base.hpp>
#include <sdf/serialize/base.hpp>
#include <sdf/types/base.hpp>

// #include <verilog/ieee1364_2001/actions/grammar.hpp>
// #include <verilog/ieee1364_2001/actions/module.hpp>
// #include <verilog/ieee1364_2001/grammar/grammar.hpp>
// #include <verilog/ieee1364_2001/grammar/module.hpp>
#include <verilog/ieee1800_2012/parse.hpp>

#include "verilog/ieee1800_2012/actions/command_listener.hpp"
#include "verilog/ieee1800_2012/actions/netlist_listener.hpp"
#include "verilog/ieee1800_2012/actions/preprocess_listener.hpp"

#include <verilog/types/commands.hpp>
#include <verilog/types/design.hpp>
#include <verilog/types/design_reader.hpp>
#include <verilog/util/parse_input.hpp>
// #include <verilog/types/module.hpp>

#include <parse/actions/control.hpp>
#include <parse/actions/make_pegtl_template.hpp>
#include <parse/util/debug_printing.hpp>
#include <parse/util/filesystem.hpp>

#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/parse.hpp>

#include <CLI/CLI.hpp>
#include <fmt/format.h>
#include <fmt/printf.h>
#include <iostream>
#include <range/v3/algorithm/reverse.hpp>
#include <range/v3/distance.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/zip.hpp>
#include <string_view>

// #include "SV2012BaseListener.h"
// #include "SV2012Lexer.h"
// #include "SV2012Parser.h"
// #include "antlr4-runtime.h"
// #include "vcd_assert/antlr_include_wrapper.hpp"

namespace fs = Parse::Util::fs;
namespace rsv = ranges::view;
using namespace Verilog;

struct NodeApply {
  std::string node;
  std::vector<std::string> sdf_files;
};

int main(int argc, char **argv)
{
  VCDAssert::print_version_preamble();

  CLI::App cli("");
  cli.failure_message(CLI::FailureMessage::help);

  std::string vcd_file;
  auto vcd_file_option = cli.add_option("vcd_file", vcd_file, "VCD file");
  vcd_file_option->required();
  vcd_file_option->check(CLI::ExistingFile);

  std::vector<std::string> source_files;
  auto source_file_option =
      cli.add_option("verilog_files", source_files, "Verilog source file(s)");
  source_file_option->check(CLI::ExistingFile);

  std::string top_module;
  cli.add_option("--top,-t", top_module, "Name of top verilog module");

  //   std::vector<std::string> library_files;
  //   cli.add_option("--include,-i", library_files, "Verilog library Files");

  std::vector<std::string> vcd_nodes;
  auto node_option = cli.add_option("--node,-n", vcd_nodes, "VCD Node");

  std::vector<std::string> sdf_files;
  auto sdf_option = cli.add_option("--sdf,-s", sdf_files, "SDF File to apply");
  sdf_option->check(CLI::ExistingFile);

  int verbose;
  cli.add_flag("--verbose,-v", verbose, "Verbosity level [1-3]");

  CLI11_PARSE(cli, argc, argv);

  ranges::reverse(vcd_nodes);
  ranges::reverse(sdf_files);
  // TODO : why reverse? Should I reverse verilog files?

  // Condense vcd_nodes and sdf_files into apply_nodes
  // TODO look into lambda api of CLI11
  std::vector<NodeApply> apply_nodes;
  for (auto option : cli.parse_order()) {
    if (option == node_option) {
      auto cur_node = vcd_nodes.back();
      vcd_nodes.pop_back();

      if (!apply_nodes.empty() && apply_nodes.back().sdf_files.empty()) {
        fmt::print(
            FMT_STRING(
                "WARNING: Node without files matched to it. (Node={})\n"),
            apply_nodes.back().node);
        apply_nodes.back().node = cur_node;
      } else {
        apply_nodes.push_back(NodeApply{cur_node, {}});
      }
    }

    if (option == sdf_option) {
      auto cur_sdf = sdf_files.back();
      sdf_files.pop_back();

      if (apply_nodes.empty())
        apply_nodes.push_back({".", {}});

      apply_nodes.back().sdf_files.push_back(cur_sdf);
    }
  }

  if (!apply_nodes.empty() && apply_nodes.back().sdf_files.empty()) {
    fmt::print(
        FMT_STRING("WARNING: Node without files matched to it. (Node:{})\n"),
        apply_nodes.back().node);
    apply_nodes.pop_back();
  }

  assert(sdf_files.empty());
  assert(vcd_nodes.empty());

  //   if (!library_files.empty()) {
  //     fmt::print(
  //         FMT_STRING("WARNING: Verilog library sources not yet
  //         supported.\n"));
  //   }

  if (apply_nodes.empty() && source_files.empty()) {
    fmt::print(FMT_STRING("ERROR: No timing checks to match!\n"));
    return 1;
  }

  // Initialise the Verilog design reader
  auto design_reader = std::make_shared<DesignReader>();

  if (!source_files.empty()) {
    std::puts("Start Verilog parsing");

    // Util::InputMap inputmap{};
    std::vector<Util::ParseInput> inputs{};
    std::optional<std::size_t> starting_source_file_index_op{};

    // (not using top module at the moment, but MUST be given non the less)
    Parse::Util::debug_puts("DEBUG: Pass 1 : preprocess + symbol table");
    for (auto &&file : source_files) {
      if (fs::exists(file)) {
        Parse::Util::debug_puts("DEBUG: parsing file : ({})", file);

        // auto file_path_normal = fs::path(file).lexically_normal();
        std::string abs_path = fs::canonical(file).string();

        //overwrite stored value with abs version
        file = abs_path;

        //save as ParseInput entry
        inputs.emplace_back(
            Util::ParseInput{file, Util::InputTypeEnum::source_file, abs_path});

      } else {
        fmt::print("ERROR: file not found : {}\n", file);
      }
    }

    assert(source_files.size() == inputs.size());

    // Initialize parser and parse Verilog source files
    using namespace antlr4::tree;
    auto parsers = IEEE1800_2012::init_antlr_parsers(inputs, (verbose >= 3));

    // Parse run 1 : preprocess + module declaration symbol table
    std::puts("\nINFO: Start preprocessor run");
    for (auto &&parse_data : parsers) {

      auto *tree = parse_data.parser->source_text();    

      ParseTreeWalker walker;

      if (verbose > 1) {
        Parse::Util::debug_print("DEBUG: parse tree start :\n");
        Parse::Util::debug_puts(
            // parse_data.
            tree->toStringTree(parse_data.parser.get()));
        Parse::Util::debug_print("DEBUG: parse tree end :\n");
      }

      auto pp_listener = std::make_shared<PreprocessListener>(
          parse_data.parser, design_reader, parse_data.source_name);
                                   
      // IEEE1800_2012::walk_w_listener(parse_data.walker, parse_data.tree_root,
        IEEE1800_2012::walk_w_listener(walker, tree,
                                       pp_listener);
        parse_data.parser->reset();

    }

    // Find file containing top module
    auto design_reader_copy = std::make_shared<DesignReader>(*design_reader);
    auto temp_design = design_reader_copy->release();
    auto search = temp_design->module_find(top_module);
    Parse::Util::debug_puts("DEBUG: Testing for : \"{}\"", top_module);

    // #ifdef VERBOSE_DEBUG_OUTPUT
    //     for (auto &&i : rsv::indices(temp_design->num_modules())) {
    //       auto mod = temp_design->get_module(i);
    //       Parse::Util::debug_puts("DEBUG: case {} : \"{}\" : ({})",i,
    //       mod.identifier, mod.file_path);
    //     }
    // #endif

    if (search.has_value()) {
      Parse::Util::debug_puts("DEBUG: Top module found");
      auto top = temp_design->get_module(search.value());
      auto top_file_path = top.file_path;

      for (auto &&[i, file] : rsv::zip(rsv::indices, source_files)) {
          Parse::Util::debug_puts("DEBUG: (top_file_path : file ) = ({}:{})", top_file_path, file);

        if (file == top_file_path) {
          
          Parse::Util::debug_puts("DEBUG: index of file found : {}", i);
          starting_source_file_index_op = (std::size_t)i;
          break;
        }
      }
    } else {
      throw std::runtime_error("ERROR: top module not found!\n");
    }

    // Parse run 2 : build netlist + get commands
    Parse::Util::debug_puts("\n\nDEBUG: Pass 2 : netlist + commands");
    if (starting_source_file_index_op.has_value()) {

      // auto index = starting_source_file_index_op.value();

      // auto top_file_normal =
      //     fs::path(source_files[index]); //.lexically_normal();
      // auto top_file_abs_path = fs::canonical(top_file_normal);

      // Create input map of library files.
      //       for (auto &&file : library_files) {
      //         auto abs_path = fs::canonical(fs::path(file));

      //         // TODO search in 'include statement' apply action, not here..
      //         inputmap.emplace(abs_path, // relative path from the test bench
      //                          Util::ParseInput{
      //                          Util::InputTypeEnum::library_file,
      //                          abs_path});
      //       }


      // std::shared_ptr<SV2012BaseListener> n_listener =
      //     std::make_shared<NetlistListener>(parse_data.parser, design_reader,
      //                                       parse_data.source_name);

      // std::vector<std::shared_ptr<SV2012BaseListener>>
      //     second_pass_listeners{};

      // second_pass_listeners.emplace_back(c_listener);
      // second_pass_listeners.emplace_back(n_listener);

      for (auto &&parse_data : parsers) {
        // std::shared_ptr<SV2012BaseListener> c_listener =
        // std::make_shared<CommandListener>(parse_data.parser, design_reader,
        //                                   parse_data.source_name);

        auto c_listener = std::make_shared<CommandListener>(
          parse_data.parser, design_reader, parse_data.source_name);

        auto *tree = parse_data.parser->source_text();
        // tree_root = std::make_shared<SV2012Parser::Source_textContext>(tree);
        // auto tree_root = std::shared_ptr<SV2012Parser::Source_textContext>(tree);
        // auto walker = std::make_shared<ParseTreeWalker>();
        ParseTreeWalker walker;
        // IEEE1800_2012::walk_w_listener(parse_data.walker, parse_data.tree_root,
        IEEE1800_2012::walk_w_listener(walker, tree,
        c_listener);
        parse_data.parser->reset();

      }

      for (auto &&parse_data : parsers) {

        auto n_listener = std::make_shared<NetlistListener>(
          parse_data.parser, design_reader, parse_data.source_name);
        // std::shared_ptr<SV2012BaseListener> n_listener =
        // std::make_shared<NetlistListener>(parse_data.parser, design_reader,
        //                                   parse_data.source_name);

        auto *tree = parse_data.parser->source_text();
        // tree_root = std::make_shared<SV2012Parser::Source_textContext>(tree);
        // auto tree_root = std::shared_ptr<SV2012Parser::Source_textContext>(tree);
        // auto walker = std::make_shared<ParseTreeWalker>();                                          
        ParseTreeWalker walker;
        IEEE1800_2012::walk_w_listener(walker, tree,
        n_listener);
        parse_data.parser->reset();
      }
   

      std::puts("Verilog parse successful");

    } else {
      throw std::runtime_error("ERROR: Cannot find indicated top module!\n");
    }
  } else {
    // TODO : optional or mandatory?
    fmt::print(FMT_STRING("WARN: No verilog files supplied for parsing\n"));
  }

  // Finalize verilog parsing into Design object.
  Parse::Util::debug_puts("DEBUG: release designreader");
  auto design_p = design_reader->release();
  assert(design_p.operator bool());

  std::puts("INFO: Starting VCD parsing");
  std::puts("INFO: Parsing VCD header");

  // Read in the VCD file header
  VCD::HeaderReader vcd_reader{};
  tao::pegtl::file_input<> vcd_input(vcd_file);
  tao::pegtl::parse<
      VCD::Grammar::header_commands,
      Parse::make_pegtl_template<VCD::Actions::HeaderAction>::type,
      Parse::capture_control>(vcd_input, vcd_reader);

  std::puts("INFO: Finished parsing VCD header");

  auto header_p = std::make_shared<VCD::Header>(vcd_reader.release());

  // Initialise the timing checker ( applies Verilog SDFs in constructor )
  std::puts("INFO: Initializing TimingChecker");
  auto timing_checker = VCDAssert::TimingChecker(header_p, std::move(design_p));

  // Read in and apply the SDF files for each node supplied on COMMAND LINE
  for (auto &&[node, sdf_file_array] : apply_nodes) {

    Parse::Util::debug_print("DEBUG: Applying SDF files to node ({})\n", node);

    SDF::HierarchicalIdentifier path{};

    // if the node specifed on CMD is a path, parse it, even if single
    // identifier.
    tao::pegtl::memory_input<> path_input(node, "node");
    tao::pegtl::parse<SDF::Grammar::hierarchical_identifier,
                      Parse::make_pegtl_template<
                          SDF::Actions::HierarchicalIdentifierAction>::type,
                      Parse::capture_control>(path_input, path);

    // std::string hi_output;
    // SDF::serialize_hierarchical_identifier(ranges::back_inserter(hi_output),
    // 0, path);

    Parse::Util::debug_puts("DEBUG: trying to find node in vcd header");
    // std::puts("node_scope_index_op found");

    auto node_scope_index_op = VCDAssert::match_scope(*header_p, path.value, 0);
    if (node_scope_index_op.has_value()) {
      Parse::Util::debug_puts("DEBUG: node(scope) found");

      for (auto &&sdf_file : sdf_file_array) {
        Parse::Util::debug_print("DEBUG: applying sdf file ({}) to vcd scope\n",
                                 sdf_file);
        timing_checker.apply_sdf_file(sdf_file, node_scope_index_op.value());
      }

    } else {
      fmt::print("WARNING: supplied node not matched (node : {})\n", node);
      // could not find the supplied scope.
    }
  }

  fmt::print("INFO: Num registered timing assertions: {}\n",
             timing_checker.num_registered_events());

// Print event dump when debugging verbose output
#ifdef VERBOSE_DEBUG_OUTPUT
  timing_checker.dump_registered_event_list();
#endif

  std::puts("INFO: Starting vcd stream");

  // Stream in vcd file
  tao::pegtl::parse<
      Parse::Grammar::star<VCD::Grammar::simulation_command>,
      Parse::make_pegtl_template<VCDAssert::TimingCheckerAction>::type,
      Parse::capture_control>(vcd_input, timing_checker);

  std::puts("INFO: Finished vcd stream");

  if (timing_checker.did_assert()) {
    std::puts("FINISHED: Timing violation(s) did occur");
    return 1;
  } else {
    std::puts("FINISHED: No timing violations occured");
    return 0;
  }
}
