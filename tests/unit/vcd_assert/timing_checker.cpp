#include "timing_checker.hpp"


TEST_CASE("VCDAssert.TimingChecker") {


  SECTION("Empty ") {
    auto header = std::make_shared<Header>();
    auto design = std::make_shared<Design>();
    TimingChecker ttc(header, design);
  }

  SECTION("Without SDF annotation"){
    SECTION("No Design") {
      HeaderReader h_reader;
      VCD::Test::read_in_test_header(h_reader, basic_dro_vcd_header);
      auto header = std::make_shared<Header>(h_reader.release());
      auto design = std::make_shared<Design>(); 

      TimingChecker ttc(header,design);
    }

    // SECTION("Matching Design") {
    //   HeaderReader h_reader;
    //   DesignReader d_reader;
      
    //   VCD::Test::read_in_test_header(h_reader, basic_dro_vcd_header);
    //   auto header = std::make_shared<Header>(h_reader.release());
    //   // auto design = std::make_shared<Design>(d_reader.release());
    //   auto design = std::make_shared<Design>();

    //   auto dft = SDF::Test::DelayFileTester();
    //   auto delayfile = dft.get_test_delayfile(basic_dro_delayfile);

    //   TimingChecker ttc(header,design);
    // }
  }

  SECTION("With SDF Annotation"){


    SECTION("No Design") {
      HeaderReader h_reader;
      
      VCD::Test::read_in_test_header(h_reader, basic_dro_vcd_header);
      auto header = std::make_shared<Header>(h_reader.release());
      auto design = std::make_shared<Design>(); 

      auto dft = SDF::Test::DelayFileTester();
      auto delayfile = dft.get_test_delayfile(basic_dro_delayfile);

      TimingChecker ttc(header,design);
      
    }


    // SECTION("Non-matching Design and VCD Header"){

    //   // //SHOULD FAIL ? TODO: REVISE REQUIREMENTS..
    //   // TODO : NEED * instance example to really know if it works
    //   // SECTION("Verilog embedded annotation commands (should fail)") {
    //   //   HeaderReader h_reader;
    //   //   DesignReader d_reader;
        
    //   //   VCD::Test::read_in_test_header(h_reader, basic_dro_vcd_header);
    //   //   auto header = std::make_shared<Header>(h_reader.release());
    //   //   // auto design = std::make_shared<Design>(d_reader.release());
    //   //   auto design = std::make_shared<Design>();

    //   //   auto dft = SDF::Test::DelayFileTester();
    //   //   auto delayfile = dft.get_test_delayfile(basic_dro_delayfile);

    //   //   TimingChecker ttc(header,design);
    //   // }

    //   SECTION("Externally supplied SDF annotation") {
    //     HeaderReader h_reader;
    //     DesignReader d_reader;
        
    //     VCD::Test::read_in_test_header(h_reader, basic_dro_vcd_header);
    //     auto header = std::make_shared<Header>(h_reader.release());
    //     // auto design = std::make_shared<Design>(d_reader.release());
    //     auto design = std::make_shared<Design>();

    //     auto dft = SDF::Test::DelayFileTester();
    //     auto delayfile = dft.get_test_delayfile(basic_dro_delayfile);

    //     // REQUIRE_THROW(
    //     TimingChecker ttc(header,design);

    //   }
    // }

    // SECTION("Matching Design and VCD Header"){

    //   // TODO : NEED * instance example to really know if it works

    //   // SECTION("Verilog embedded annotation commands") {
    //   //   HeaderReader h_reader;
    //   //   DesignReader d_reader;
        
    //   //   VCD::Test::read_in_test_header(h_reader, basic_dro_vcd_header);
    //   //   auto header = std::make_shared<Header>(h_reader.release());
    //   //   // auto design = std::make_shared<Design>(d_reader.release());
    //   //   auto design = std::make_shared<Design>();

    //   //   auto dft = SDF::Test::DelayFileTester();
    //   //   auto delayfile = dft.get_test_delayfile(basic_dro_delayfile);

    //   //   TimingChecker ttc(header,design);
    //   // }

    //   SECTION("Externally supplied SDF annotation") {
    //     HeaderReader h_reader;
    //     DesignReader d_reader;
        
    //     VCD::Test::read_in_test_header(h_reader, basic_dro_vcd_header);
    //     auto header = std::make_shared<Header>(h_reader.release());
    //     // auto design = std::make_shared<Design>(d_reader.release());
    //     auto design = std::make_shared<Design>();

    //     auto dft = SDF::Test::DelayFileTester();
    //     auto delayfile = dft.get_test_delayfile(basic_dro_delayfile);

    //     TimingChecker ttc(header,design);
    //   }
    // }

  }


}

