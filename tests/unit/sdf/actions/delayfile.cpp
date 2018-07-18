#include "../types/delayfile.hpp"

#include <parse/test/parse.hpp>
using namespace Parse::Test;

#include <sdf/grammar/delayfile.hpp>
#include <sdf/actions/delayfile.hpp>
#include <sdf/types/delayfile.hpp>
#include <sdf/serialize/delayfile.hpp>

// using namespace SDF;
// using namespace SDF::Test;

#include <catch2/catch.hpp>
namespace SDF::Test{

TEST_CASE("SDF.Actions.Delayfile", "[SDF][Actions][Delayfile]") {

  const DelayFileView wanted = test_delayfile_1;

  //Delayfile from test delayfile view 
  DelayFileTester dft = DelayFileTester();
  auto test_delayfile_p = dft.get_test_delayfile(wanted);

  //serialize test delayfile
  std::string serialized;
  serialize_delayfile(ranges::back_inserter(serialized), test_delayfile_p);

  //parse serialized delayfile using DelayFileReader
  DelayFileReader test_reader{};
  require_parse<Grammar::delay_file, Actions::DelayFileAction>(
      serialized, test_reader);

  //get Delayfile from parse result
  auto test_p = test_reader.release();
  REQUIRE(test_p.operator bool());
  // auto& test = ;

  //compare delayfile from parse with original delayfile view.
  catch_test_delayfile(test_delayfile_1, *test_p);
}
}
