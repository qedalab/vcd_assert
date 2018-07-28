#include "design.hpp"

#include <range/v3/view/indices.hpp>
#include <catch2/catch.hpp>

#include <range/v3/algorithm/equal.hpp>
// return ranges::equal(value, other.value);

namespace VerilogTest = Verilog::Test::Verilog::IEEE1364_2001;
using namespace ranges::view;


void VerilogTest::catch_design(DesignView wanted, Design test)
{
  SECTION("Verilog Design") {

    SECTION("Member : \"modules_\"") {
      REQUIRE(wanted.modules_.size() == test.num_modules());
      for(auto&& index : indices(test.num_modules())){
        auto test_module = test.get_module(index);
        CAPTURE(test_module);
        catch_module(wanted.modules_[index],test_module);
      } 
    }
    SECTION("Member : \"instances_\"") { // ?? ERROR HERE.
      REQUIRE(wanted.instances_.size() == test.num_instances());
      for(auto&& index : indices(test.num_instances())){
        auto test_instance = test.get_instance(index);
        CAPTURE(test_instance);
        catch_instance(wanted.instances_[index],test_instance);        
      } 
    }
    // SECTION("Member : \"module_lookup_\"") {
    //   CAPTURE(test.module_lookup_);
    //   REQUIRE(wanted.module_lookup_ == test.module_lookup_); 
    //   REQUIRE(ranges::equal(wanted.module_lookup_, test.module_lookup_));
      
    // }
    // SECTION("Member : \"sdf_commands_\"") {
    //   // get_sdf_for_module
    //   REQUIRE(wanted.sdf_commands_.size() == test.num_sdf_commands());
    //   for(auto&& index : indices(test.num_modules())){
    //     auto test_module = test.get_module(index);
    //     CAPTURE(test_module);
    //     catch_module(wanted.sdf_commands_[index],test_module);
    //   } 
    //   REQUIRE(wanted.sdf_commands_ == test.sdf_commands_); 
    // }
    // SECTION("Member : \"sdf_commands_lookup_\"") {
    //   CAPTURE(test.sdf_commands_lookup_);
    //   REQUIRE(wanted.sdf_commands_lookup_ == test.sdf_commands_lookup_); 
    // }
  }
}

void VerilogTest::catch_module(Module wanted, Module test)
{
  CAPTURE(wanted.identifier);
  CAPTURE(test.identifier);
  SECTION("Field : \"identifier\"") {
    REQUIRE(wanted.identifier == test.identifier);
  }
  SECTION("Field : \"file_path\"") {
    REQUIRE(wanted.file_path == test.file_path);
  }
  SECTION("Field : \"instance_lookup_\"") {
    if(!ranges::equal(wanted.instance_lookup_, test.instance_lookup_)){
      CAPTURE(wanted.instance_lookup_);
      CAPTURE(test.instance_lookup_);
      REQUIRE(ranges::equal(wanted.instance_lookup_, test.instance_lookup_));
    }
  }
}

void VerilogTest::catch_instance(Instance wanted, Instance test)
{
  SECTION("Field : \"type_\"") {
    REQUIRE(wanted.type_ == test.type_);
  }
  SECTION("Field : \"identifier_\"") {
    REQUIRE(wanted.identifier_ == test.identifier_);
  }
  SECTION("Field : \"definition_index\"") {
    REQUIRE(wanted.definition_index == test.definition_index);
  }
}

