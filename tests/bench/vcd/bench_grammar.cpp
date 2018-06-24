#include "vcd/grammar/grammar.hpp"
#include "vcd/version.hpp"

#include <CLI/CLI.hpp>
#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/parse.hpp>

int main(int argc, char** argv) {
  using tao::pegtl::file_input;
  using tao::pegtl::parse;

  CLI::App cli("LibVCD Grammar benchmark");

  std::string file_path;
  cli.add_option("file", file_path, "File to do a grammar parse on");

  CLI11_PARSE(cli, argc, argv);

  file_input<> input(file_path);
  bool success = parse<VCD::Grammar::value_change_dump>(input);

  if(!success) {
    throw std::runtime_error("Failed parsing file: " + file_path);
  }

  return 0;
}
