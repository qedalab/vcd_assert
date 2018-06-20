#include "vcd/grammar/grammar.hpp"
#include "vcd/version.hpp"

#include <docopt.h>
#include <tao/pegtl/file_input.hpp>
#include <tao/pegtl/parse.hpp>

static constexpr char usage[] =
R"(LibVCD Grammar benchmark

Run grammar and only grammar parse on a file for benchmark purposes

Usage:
  libvcd_bench_grammar <file>
  libvcd_bench_grammar (-h | --help)

Options:
  <file>       File to do a grammar parse on
  -h --help    Show this help message
)";

int main(int argc, const char** argv) {
  using tao::pegtl::file_input;
  using tao::pegtl::parse;

  // Parse commandline args
  auto args = docopt::docopt(
    usage,
    {argv+1, argv+argc},
    true,
    LIBVCD_MACRO_VERSION " Grammar benchmark");

  auto file_path = args["<file>"].asString();

  file_input<> input(file_path);
  bool success = parse<VCD::Grammar::value_change_dump>(input);

  if(!success) {
    throw std::runtime_error("Failed parsing file: " + file_path);
  }

  return 0;
}
