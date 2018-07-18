#include "vcd_assert/timing_checker.hpp"

#include "vcd/grammar/grammar.hpp"
#include "vcd/types/header_reader.hpp"
#include "vcd/actions/header.hpp"

#include <sdf/actions/base.hpp>
#include <sdf/actions/delayfile.hpp>
#include <sdf/grammar/base.hpp>
#include <sdf/grammar/grammar.hpp>
#include <sdf/grammar/delayfile.hpp>
#include <sdf/types/base.hpp>
#include <sdf/types/delayfile.hpp>
#include <sdf/types/delayfile_reader.hpp>

#include <parse/actions/control.hpp>
#include <parse/actions/make_pegtl_template.hpp>

#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/parse.hpp>

// #include <verilog_ast.h>
// #include <verilog_ast_util.h>
// #include <verilog_parser.h>

#include <CLI/CLI.hpp>
#include <fmt/format.h>
#include <fmt/printf.h>
#include <iostream>
#include <string_view>
#include <range/v3/algorithm/reverse.hpp>
#include <range/v3/view/indices.hpp>


struct NodeApply {
  std::string node;
  std::vector<std::string> sdf_files;
};

int main(int argc, char **argv) {
  CLI::App cli("VCDAssert: Post processing VCD files for timing violations");
  cli.failure_message(CLI::FailureMessage::help);

  std::string vcd_file;
  auto vcd_file_option = cli.add_option("file", vcd_file, "VCD file");
  vcd_file_option->required();
  vcd_file_option->check(CLI::ExistingFile);

  std::vector<std::string> verilog_files;
  auto verilog_file_option = cli.add_option("file", verilog_files, "Verilog file(s)");
  verilog_file_option->required();
  verilog_file_option->check(CLI::ExistingFile); //TODO : is this necessary?

  std::vector<std::string> vcd_nodes;
  auto node_option = cli.add_option("--node,-n", vcd_nodes, "VCD Node");

  std::vector<std::string> sdf_files;
  auto sdf_option = cli.add_option("--sdf,-s", sdf_files, "SDF File to apply");
  
  int verbose;
  /*CLI::Option *v_option = */cli.add_flag("--verbose,-v", verbose, "Verbosity level [1-3]");


  CLI11_PARSE(cli, argc, argv);

  ranges::reverse(vcd_nodes);
  ranges::reverse(sdf_files);

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

  if (apply_nodes.empty()) {
    fmt::print(FMT_STRING("ERROR: No timing checks to match!\n"));
    return 1;
  }

  assert(sdf_files.empty());
  assert(vcd_nodes.empty());
  
  /*
  // Initialise the Verilog parser.
  verilog_parser_init();

  // Parse the Verilog files
  for (auto&& verilog_file : verilog_files) {

    // Open A File handle to read data in.
    FILE * input_file = fopen(verilog_file.c_str(),"r");
    if(input_file){
    
      // Parse our input file.
      int result = verilog_parse_file(input_file);

      // If the parse didn't work, print an error message and quit.
      if(result != 0){
        fmt::print(FMT_STRING("ERROR: Failed to parse Verilog file:\n"));
        fmt::print(fmt::sprintf("\t%s\n",verilog_file));
      }
      else if(verbose){
        fmt::print(FMT_STRING("INFO: Parsing Verilog file: "));
        fmt::print(fmt::sprintf("%s\n",verilog_file));
      }
    }else{
      fmt::print(FMT_STRING("ERROR: Failed to parse Verilog file:\n"));
      fmt::printf("ERROR Could not open file for reading: %s\n", verilog_file);//test
         
    }
    fclose(input_file);
  }

  // This is how we access the parsed source tree.
  verilog_source_tree * ast = yy_verilog_source_tree;

  // Resolve all of the names in the syntax tree.
  verilog_resolve_modules(ast);
  */

  // Read in the VCD file
  VCD::HeaderReader vcd_reader{};
  tao::pegtl::file_input<> vcd_input(vcd_file);
  tao::pegtl::parse<VCD::Grammar::header_commands,
                    Parse::make_pegtl_template<VCD::Actions::HeaderAction>::type,
                    Parse::capture_control>(vcd_input, vcd_reader);

  auto header_p = vcd_reader.release();
  assert(header_p.operator bool());
  auto timing_checker = VCDAssert::TimingChecker(std::move(header_p));
  
  // Read in corresponding SDF files
  for (auto&& [node,sdf_file_array] : apply_nodes) {
    
    // std::string_view node_view(std::begin(node), std::size(node));

    SDF::HierarchicalIdentifier path{};
    //if the node specifed on CMD is a path, parse it, even if single identifier.
    tao::pegtl::memory_input<> path_input(node, "node");
    tao::pegtl::parse<
        SDF::Grammar::hierarchical_identifier,
        Parse::make_pegtl_template<SDF::Actions::HierarchicalIdentifierAction>::type,
        Parse::capture_control
      >(path_input, path);
    
    for(auto&& sdf_file : sdf_files){
      // (void)sdf_file;
      SDF::DelayFileReader sdf_reader{};

      tao::pegtl::file_input<> sdf_input(sdf_file);
      tao::pegtl::parse<SDF::Grammar::delay_file, 
                        Parse::make_pegtl_template<SDF::Actions::DelayFileAction>::type,
                        // SDF::Actions::DelayFileAction,
                        Parse::capture_control>(sdf_input, sdf_reader);
      
      auto delayfile_p = sdf_reader.release();
      assert(delayfile_p.operator bool());

      timing_checker.apply_sdf_file(/*ast,*/ std::move(delayfile_p), path.value);
    }    
  }

  return 0;
}
