#include "./timing_check.hpp"

using namespace SDF;
using namespace SDF::Test;
using namespace ranges;

void SDF::Test::catch_test_invertednode(InvertedNode wanted,
                                        InvertedNode test) {

}

void SDF::Test::catch_test_nodeconstantequality(NodeConstantEquality wanted,
                                                NodeConstantEquality test) {


}

void SDF::Test::catch_test_timingcheckcondition(TimingCheckCondition wanted,
                                                TimingCheckCondition test) {
  SECTION("Conditionals should be equal") {
    SECTION("Should be of the same type") {
      CAPTURE(test.get_enum_type());      
      REQUIRE(wanted.get_enum_type() == test.get_enum_type()); 
    }
    SECTION("Should be equal") {
      CAPTURE(test.value);
      CHECK(wanted.value == test.value);   
    }
  }
  // if(!(wanted.value == test.value) && 
  //     (wanted.get_enum_type() == test.get_enum_type()))
  // {   
  //   switch (wanted.get_enum_type()) {
  //   case ConditionalType::none:
  //     catch_test_node(std::get<Node>(wanted.value), std::get<Node>(test.value));
  //     break; 
  //   case ConditionalType::inverted:
  //     catch_test_invertednode(std::get<InvertedNode>(wanted.value), std::get<InvertedNode>(test.value));
  //     break; 
  //   case ConditionalType::equality:
  //     catch_test_nodeconstantequality(std::get<NodeConstantEquality>(wanted.value),
  //                                     std::get<NodeConstantEquality>(test.value));
  //     break; 
  //   default:
  //     FAIL("InternalError");
  //   }
  // }

}
//   if(test.port.edge.has_value()){
//     REQUIRE(pt.port.edge.has_value());
//     REQUIRE(test.port.edge == pt.port.edge) ;
//   }
void SDF::Test::catch_test_porttimingcheck(PortTimingCheck wanted,
                                           PortTimingCheck test) {
  INFO("PortCheck");

  SECTION("Port should be equal") { 
    REQUIRE(wanted.port==test.port);
  }

  if(!(wanted.port ==test.port)){
    catch_test_node(wanted.port, test.port); 
  }

  if (wanted.timing_check_condition.has_value()) {
    SECTION("Should have a timing check condition") {
      REQUIRE(test.timing_check_condition.has_value());
    }
    if (test.timing_check_condition.has_value()) {
        catch_test_timingcheckcondition(wanted.timing_check_condition.value(),
                                        test.timing_check_condition.value());
    }
  }

  if (wanted.symbolic_name.has_value()) {
    SECTION("Should have a symbolic name") {
      REQUIRE(test.symbolic_name.has_value());
    }
    SECTION("Symbolic names should be equal") {
      REQUIRE(wanted.symbolic_name.value() == test.symbolic_name.value());
    }
  }
}

void SDF::Test::catch_test_hold(Hold wanted, Hold test) {
  INFO("Hold Timing Check");
  INFO("Input should be equal");    
  catch_test_porttimingcheck(wanted.input, test.input);

  INFO("Output should be equal");
  catch_test_porttimingcheck(wanted.output, test.output);

  SECTION("Value should be equal") { 
    REQUIRE(wanted.value == test.value); 
  }
}

void SDF::Test::catch_test_timingcheck(TimingCheck wanted, TimingCheck test) {

  SECTION("Timing Check Type") {
    REQUIRE(wanted.get_enum_type() == test.get_enum_type());
  }

  switch (wanted.get_enum_type()) {
  case TimingCheckType::hold:
    catch_test_hold(std::get<Hold>(wanted.value), std::get<Hold>(test.value));
    break;
  case TimingCheckType::setup:
    FAIL("Only Hold Timing Checks are supported");
    break; 
  default:
    FAIL("Only Hold Timing Checks are supported");
  }
}

void SDF::Test::catch_test_timingcheckspec(TimingCheckSpec wanted,
                                           TimingCheckSpec test) {

  SECTION("Timing Check Spec") { 
    REQUIRE(wanted.size() == test.size()); 
  }

  for (auto &&[w_tcheck, t_tcheck] : view::zip(wanted, test))
    catch_test_timingcheck(w_tcheck, t_tcheck);
}
