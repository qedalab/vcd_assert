#include "./timing.hpp"

using namespace SDF::Test;
using namespace SDF;




// TEST_CASE("SDF.Types.Timing") {

// SECTION("Case 1: Empty") {
//     //Write Header file with the same structure as the VCD example
//     HeaderReader reader;
//     Test::read_in_test_header(reader, vcd_empty_header);
//     auto header_p = reader.release();
//     REQUIRE(header_p.operator bool());
//     Test::catch_test_header(*header_p, vcd_empty_header);
//   }

//   SECTION("Case 2: From Example") {
//     Test::read_in_test_header(reader, vcd_4_state_example_header);
//     auto header_p = reader.release();
//     REQUIRE(header_p.operator bool());
//     auto &header = *header_p;
//     Test::catch_test_header(header, vcd_4_state_example_header);
//   }
// }
