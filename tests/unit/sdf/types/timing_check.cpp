#include "./timing_check.hpp"

#include <range/v3/view/zip.hpp>

using namespace SDF;
using namespace SDF::Test;

void SDF::Test::catch_test_invertednode(InvertedNode wanted,
                                        InvertedNode test) {
  Node new_wanted_node{wanted};                                          
  Node new_test_node{test};                                          
  catch_test_node(new_wanted_node, test);
}

void SDF::Test::catch_test_nodeconstantequality(NodeConstantEquality wanted,
                                                NodeConstantEquality test) {

   SECTION("Nodes must be equivalent") {
    CAPTURE(wanted.left);      
    CAPTURE(test.left);      
    REQUIRE(wanted.left == test.left); 
  }
  SECTION("Equality operators must be equivalent") {
    CAPTURE(wanted.op);      
    CAPTURE(test.op);      
    REQUIRE(wanted.op == test.op); 
  }
  SECTION("Scalars must be equivalent") {
    CAPTURE(wanted.right);      
    CAPTURE(test.right);      
    REQUIRE(wanted.right == test.right); 
  }
}

void SDF::Test::catch_test_timingcheckcondition(TimingCheckCondition wanted,
                                                TimingCheckCondition test) {
  SECTION("Timing Check Condition TYPE") {
    CAPTURE(test.get_enum_type());      
    REQUIRE(wanted.get_enum_type() == test.get_enum_type()); 
  }
  SECTION("Timing Check Condition Value") {
    CAPTURE(test.value);
    // REQUIRE(wanted.value == test.value);   
  
  if(!(wanted.value == test.value) && 
      (wanted.get_enum_type() == test.get_enum_type()))
  {   
    CAPTURE(wanted.get_enum_type());
    CAPTURE(test.get_enum_type());      
    switch (wanted.get_enum_type()) {
    case ConditionalType::none:
      catch_test_node(std::get<Node>(wanted.value), std::get<Node>(test.value));
      break; 
    case ConditionalType::inverted:
      catch_test_invertednode(std::get<InvertedNode>(wanted.value), std::get<InvertedNode>(test.value));
      break; 
    case ConditionalType::equality:
      catch_test_nodeconstantequality(std::get<NodeConstantEquality>(wanted.value),
                                      std::get<NodeConstantEquality>(test.value));
      break; 
    default:
      FAIL("ConditionalType Not Found");
    }
    
  }
  }

}
//   if(test.port.edge.has_value()){
//     REQUIRE(pt.port.edge.has_value());
//     REQUIRE(test.port.edge == pt.port.edge) ;
//   }
void SDF::Test::catch_test_porttimingcheck(PortTimingCheck wanted,
                                           PortTimingCheck test) {
  INFO("PortCheck");

  SECTION("Port should be equal") { 
    CHECK(wanted.port==test.port);
  }

  if(!(wanted.port ==test.port)){
    catch_test_node(wanted.port, test.port); 
  }

  if (wanted.timing_check_condition.has_value()) {
    SECTION("Should have a timing check condition") {
      REQUIRE(test.timing_check_condition.has_value());
    }
    if (test.timing_check_condition.has_value()) {
      INFO("Conditionals should be equal");
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
  INFO("Trigger port_tchk should be equal");    
  catch_test_porttimingcheck(wanted.reg, test.reg);

  INFO("Assertion port_tchk should be equal");
  catch_test_porttimingcheck(wanted.trig, test.trig);

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
  default:
    FAIL("Only Hold Timing Checks are supported");
  }
}

void SDF::Test::catch_test_timingcheckspec(TimingCheckSpec wanted,
                                           TimingCheckSpec test) {

  SECTION("Timing Check Spec") { 
    REQUIRE(wanted.size() == test.size()); 
  }

  for (auto &&[w_tcheck, t_tcheck] : ranges::view::zip(wanted, test))
    catch_test_timingcheck(w_tcheck, t_tcheck);
}
