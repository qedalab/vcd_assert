#include "../types/delayfile.hpp"

#include <parse/test/parse.hpp>
using namespace Parse::Test;

#include <sdf/grammar/delayfile.hpp>
#include <sdf/actions/delayfile.hpp>
#include <sdf/types/delayfile.hpp>
#include <sdf/serialize/delayfile.hpp>

// using namespace SDF;
// using namespace SDF::Test;

// constexpr auto project_source_dir =
//     Parse::Util::static_string(PROJECT_SOURCE_DIR);


// constexpr auto dro_gate_input_path_ =
//     "" + project_source_dir + "/examples/basic_dro_success/";
// constexpr auto and_gate_input_path_ =
//     "" + project_source_dir + "/examples/basic_dro_success/";

// constexpr auto dro_file_path_abs_ = dro_gate_input_path_ + "dro.v";

// constexpr auto and_file_path_abs_ = and_gate_input_path_ + "and.v";

#include <catch2/catch.hpp>
namespace SDF::Test{

TEST_CASE("SDF.Actions.Delayfile", "[SDF][Actions][Delayfile]") {

  SECTION("Case 1: From test SDF file") {

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

  // SECTION("Case 2: From SDF examples") {
  //   SECTION("DRO gate SDF") {

  //     tao::pegtl::file_input<> input(dro_gate_input_path_.to_string());

  //     DelayFileReader test_reader{};
  //     require_parse<Grammar::delay_file, Actions::DelayFileAction>(
  //         serialized, test_reader);

  //     //get Delayfile from parse result
  //     auto test_p = test_reader.release();
  //     REQUIRE(test_p.operator bool());
  //     // auto& test = ;

  //     //compare delayfile from parse with original delayfile view.
  //     catch_test_delayfile(test_delayfile_1, *test_p);

  //     CHECK(test.num_cells() > 0);
  //     SDF::Test::catch_test_delayfile(test_delayfile_1, test);
  //   }

  //   SECTION("AND gate SDF") {

  //     tao::pegtl::file_input<> input(and_gate_input_path_.to_string());

  //     DelayFileReader test_reader{};
  //     require_parse<Grammar::delay_file, Actions::DelayFileAction>(
  //         serialized, test_reader);

  //     //get Delayfile from parse result
  //     auto test_p = test_reader.release();
  //     REQUIRE(test_p.operator bool());
  //     // auto& test = ;

  //     //compare delayfile from parse with original delayfile view.
  //     catch_test_delayfile(test_delayfile_1, *test_p);

  //     CHECK(test.num_cells() > 0);
  //     SDF::Test::catch_test_delayfile(test_delayfile_1, test);
  //   }
  // }
}

}
