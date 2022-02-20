#include "./test_design.hpp"

#include <catch2/catch.hpp>
#include <range/v3/view/indices.hpp>

#include <range/v3/algorithm/equal.hpp>
#include <range/v3/view/zip.hpp>
// return ranges::equal(value, other.value);

using namespace Verilog;

using namespace ranges::views;

void Verilog::Test::catch_design_view(DesignView wanted, Design test)
{
  SECTION("Verilog Design")
  {

    SECTION("Member : \"modules_\"")
    {
      REQUIRE(wanted.modules_.size() == test.num_modules());
      for (auto &&index : indices(test.num_modules())) {
        auto test_module = test.get_module(index);
        CAPTURE(test_module);
        catch_module(wanted.modules_[index], test_module);
      }
    }
    SECTION("Member : \"instances_\"")
    { // ?? ERROR HERE.
      REQUIRE(wanted.instances_.size() == test.num_instances());
      for (auto &&index : indices(test.num_instances())) {
        auto test_instance = test.get_instance(index);
        CAPTURE(test_instance);
        catch_instance(wanted.instances_[index], test_instance);
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

void Verilog::Test::catch_design(Design &wanted, Design &test)
{
  INFO("Verilog Design");
  // {

    INFO("Member : \"modules_\"");
    // {
      REQUIRE(wanted.num_modules() == test.num_modules());
      for (auto &&index : indices(test.num_modules())) {
        auto test_module = test.get_module(index);
        CAPTURE(test_module);
        catch_module(wanted.get_module(index), test_module);
      }
    // }
    INFO("Member : \"instances_\"");
    // { // ?? ERROR HERE.
      REQUIRE(wanted.num_instances() == test.num_instances());
      for (auto &&index : indices(test.num_instances())) {
        CAPTURE(test.get_instance(index));
        catch_instance(wanted.get_instance(index), test.get_instance(index));
      }
    // }
    // INFO("Member : \"module_lookup_\""); 
    // // {
    //   CAPTURE(test.module_lookup_);
    //   REQUIRE(wanted.module_lookup_ == test.module_lookup_);
    //   REQUIRE(ranges::equal(wanted.module_lookup_, test.module_lookup_));

    // // }
    INFO("Member : \"sdf_commands_\"");
    // {
      // get_sdf_for_module
      REQUIRE(wanted.num_sdf_commands() == test.num_sdf_commands());
      // for(auto&& index : indices(test.num_modules())){
      //   auto test_module = test.get_module(index);
      //   CAPTURE(test_module);
      //   catch_module(wanted.sdf_commands_[index],test_module);
      // }
      // REQUIRE(wanted.get_sdf_command(index) == test.get_sdf_command(index));
    // }
    // SECTION("Member : \"sdf_commands_lookup_\"") {
    //   CAPTURE(test.sdf_commands_lookup_);
    //   REQUIRE(wanted.sdf_commands_lookup_ == test.sdf_commands_lookup_);
    // }
  // }
}

void Verilog::Test::catch_module(Module wanted, Module test)
{
  CAPTURE(wanted.identifier);
  CAPTURE(test.identifier);
  INFO("Field : \"identifier\"");
  // {
    REQUIRE(wanted.identifier == test.identifier);
  // }
  INFO("Field : \"file_path\"");
  // {
    REQUIRE(wanted.file_path == test.file_path);
  // }
  INFO("Field : \"instance_lookup_\"");
  // {
    // if (!ranges::equal(wanted.instance_lookup_, test.instance_lookup_)) {
      REQUIRE(wanted.instance_lookup_.size() == test.instance_lookup_.size());
      CAPTURE(wanted.instance_lookup_);
      CAPTURE(test.instance_lookup_);
      for (auto &&[wanted_lu, test_lu] :
           ranges::view::zip(wanted.instance_lookup_, test.instance_lookup_)) {
        REQUIRE(wanted_lu.first == wanted_lu.first);
        REQUIRE(wanted_lu.second == wanted_lu.second);
      }
    // }
  // }
}

void Verilog::Test::catch_instance(Instance wanted, Instance test)
{
  INFO("Field : \"type_\"");
  { 
    REQUIRE(wanted.type_ == test.type_); 
  }
  INFO("Field : \"identifier_\"");
  {
    REQUIRE(wanted.identifier_ == test.identifier_);
  }
  INFO("Field : \"definition_index\"");
  {
    REQUIRE(wanted.definition_index == test.definition_index);
  }
}
