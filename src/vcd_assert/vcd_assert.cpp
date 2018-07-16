#include "vcd/types/header_reader.hpp"
#include "vcd_assert/timing_checker.hpp"
#include "vcd/actions/header.hpp"

#include "../actions/control.hpp"
#include "../actions/make_pegtl_template.hpp"
#include <tao/pegtl/memory_input.hpp>
#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/parse.hpp>

#include <CLI/CLI.hpp>
#include <fmt/format.h>
#include <range/v3/algorithm/reverse.hpp>

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

  std::vector<std::string> vcd_nodes;
  auto node_option = cli.add_option("--node,-n", vcd_nodes, "VCD Node");

  std::vector<std::string> sdf_files;
  auto sdf_option = cli.add_option("--sdf,-s", sdf_files, "SDF File to apply");
  sdf_option->check(CLI::ExistingFile);

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
  
  size_t applied_ = 0;


  verilog_parser_init();

  for (auto&& verilog_file : verilog_file_array) {
    // Open A File handle to read data in.
    FILE * fh = fopen("my_verilog_file.v", "r");
  }
  // Parse the file and store the result.
  int result = verilog_parse_file(fh);

  if(result == 1)
    fmt::print(FMT_STRING("ERROR: Verilog parse unsuccessful.\n"));

  fclose(fh);


  VCD::HeaderReader vcd_reader;
  tao::pegtl::file_input<> input(vcd_file);
  tao::pegtl::parse<VCD::Grammar::grammar, VCD::Actions::HeaderAction,
                Parse::capture_control>(input, vcd_reader);

  auto header_p = reader.release();
  assert(header_p.operator bool());
  auto timing_checker = VCDAssert::TimingChecker(header_p);
  
  for (auto&& [node,sdf_file_array] : apply_nodes) {
    size_t scope_index = header_p->.get
    for(auto&& sdf_file : sdf_file_array){

      DelayFileReader sdf_reader;

      tao::pegtl::file_input<> input(sdf_file);
      tao::pegtl::parse<SDF::Grammar::grammar, SDF::Actions::DelayFileAction,
                        Parse::capture_control>(input, sdf_reader);
      
      auto delayfile_p = sdf_reader.release();
      assert(delayfile_p.operator bool());

      timing_checker.apply_sdf(delayfile_p, node);
    }    
  }

  return 0;
}
