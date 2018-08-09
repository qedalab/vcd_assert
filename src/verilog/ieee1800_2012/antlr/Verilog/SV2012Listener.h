
// Generated from /home/userd/Workspace/git-local-repos/supertools__libvcdassert/src/verilog/ieee1800_2012/SV2012.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SV2012Parser.h"


namespace Verilog {

/**
 * This interface defines an abstract listener for a parse tree produced by SV2012Parser.
 */
class  SV2012Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterLibrary_text(SV2012Parser::Library_textContext *ctx) = 0;
  virtual void exitLibrary_text(SV2012Parser::Library_textContext *ctx) = 0;

  virtual void enterLibrary_description(SV2012Parser::Library_descriptionContext *ctx) = 0;
  virtual void exitLibrary_description(SV2012Parser::Library_descriptionContext *ctx) = 0;

  virtual void enterLibrary_declaration(SV2012Parser::Library_declarationContext *ctx) = 0;
  virtual void exitLibrary_declaration(SV2012Parser::Library_declarationContext *ctx) = 0;

  virtual void enterInclude_statement(SV2012Parser::Include_statementContext *ctx) = 0;
  virtual void exitInclude_statement(SV2012Parser::Include_statementContext *ctx) = 0;

  virtual void enterPp_include_statement(SV2012Parser::Pp_include_statementContext *ctx) = 0;
  virtual void exitPp_include_statement(SV2012Parser::Pp_include_statementContext *ctx) = 0;

  virtual void enterPp_timescale_declaration(SV2012Parser::Pp_timescale_declarationContext *ctx) = 0;
  virtual void exitPp_timescale_declaration(SV2012Parser::Pp_timescale_declarationContext *ctx) = 0;

  virtual void enterCompiler_directive_catchall(SV2012Parser::Compiler_directive_catchallContext *ctx) = 0;
  virtual void exitCompiler_directive_catchall(SV2012Parser::Compiler_directive_catchallContext *ctx) = 0;

  virtual void enterSource_text(SV2012Parser::Source_textContext *ctx) = 0;
  virtual void exitSource_text(SV2012Parser::Source_textContext *ctx) = 0;

  virtual void enterDescription(SV2012Parser::DescriptionContext *ctx) = 0;
  virtual void exitDescription(SV2012Parser::DescriptionContext *ctx) = 0;

  virtual void enterModule_nonansi_header(SV2012Parser::Module_nonansi_headerContext *ctx) = 0;
  virtual void exitModule_nonansi_header(SV2012Parser::Module_nonansi_headerContext *ctx) = 0;

  virtual void enterModule_ansi_header(SV2012Parser::Module_ansi_headerContext *ctx) = 0;
  virtual void exitModule_ansi_header(SV2012Parser::Module_ansi_headerContext *ctx) = 0;

  virtual void enterModule_declaration(SV2012Parser::Module_declarationContext *ctx) = 0;
  virtual void exitModule_declaration(SV2012Parser::Module_declarationContext *ctx) = 0;

  virtual void enterModule_keyword(SV2012Parser::Module_keywordContext *ctx) = 0;
  virtual void exitModule_keyword(SV2012Parser::Module_keywordContext *ctx) = 0;

  virtual void enterInterface_declaration(SV2012Parser::Interface_declarationContext *ctx) = 0;
  virtual void exitInterface_declaration(SV2012Parser::Interface_declarationContext *ctx) = 0;

  virtual void enterInterface_nonansi_header(SV2012Parser::Interface_nonansi_headerContext *ctx) = 0;
  virtual void exitInterface_nonansi_header(SV2012Parser::Interface_nonansi_headerContext *ctx) = 0;

  virtual void enterInterface_ansi_header(SV2012Parser::Interface_ansi_headerContext *ctx) = 0;
  virtual void exitInterface_ansi_header(SV2012Parser::Interface_ansi_headerContext *ctx) = 0;

  virtual void enterProgram_declaration(SV2012Parser::Program_declarationContext *ctx) = 0;
  virtual void exitProgram_declaration(SV2012Parser::Program_declarationContext *ctx) = 0;

  virtual void enterProgram_nonansi_header(SV2012Parser::Program_nonansi_headerContext *ctx) = 0;
  virtual void exitProgram_nonansi_header(SV2012Parser::Program_nonansi_headerContext *ctx) = 0;

  virtual void enterProgram_ansi_header(SV2012Parser::Program_ansi_headerContext *ctx) = 0;
  virtual void exitProgram_ansi_header(SV2012Parser::Program_ansi_headerContext *ctx) = 0;

  virtual void enterChecker_declaration(SV2012Parser::Checker_declarationContext *ctx) = 0;
  virtual void exitChecker_declaration(SV2012Parser::Checker_declarationContext *ctx) = 0;

  virtual void enterClass_declaration(SV2012Parser::Class_declarationContext *ctx) = 0;
  virtual void exitClass_declaration(SV2012Parser::Class_declarationContext *ctx) = 0;

  virtual void enterInterface_class_type(SV2012Parser::Interface_class_typeContext *ctx) = 0;
  virtual void exitInterface_class_type(SV2012Parser::Interface_class_typeContext *ctx) = 0;

  virtual void enterInterface_class_declaration(SV2012Parser::Interface_class_declarationContext *ctx) = 0;
  virtual void exitInterface_class_declaration(SV2012Parser::Interface_class_declarationContext *ctx) = 0;

  virtual void enterInterface_class_item(SV2012Parser::Interface_class_itemContext *ctx) = 0;
  virtual void exitInterface_class_item(SV2012Parser::Interface_class_itemContext *ctx) = 0;

  virtual void enterInterface_class_method(SV2012Parser::Interface_class_methodContext *ctx) = 0;
  virtual void exitInterface_class_method(SV2012Parser::Interface_class_methodContext *ctx) = 0;

  virtual void enterPackage_declaration(SV2012Parser::Package_declarationContext *ctx) = 0;
  virtual void exitPackage_declaration(SV2012Parser::Package_declarationContext *ctx) = 0;

  virtual void enterTimeunits_declaration(SV2012Parser::Timeunits_declarationContext *ctx) = 0;
  virtual void exitTimeunits_declaration(SV2012Parser::Timeunits_declarationContext *ctx) = 0;

  virtual void enterParameter_port_list(SV2012Parser::Parameter_port_listContext *ctx) = 0;
  virtual void exitParameter_port_list(SV2012Parser::Parameter_port_listContext *ctx) = 0;

  virtual void enterParameter_port_declaration(SV2012Parser::Parameter_port_declarationContext *ctx) = 0;
  virtual void exitParameter_port_declaration(SV2012Parser::Parameter_port_declarationContext *ctx) = 0;

  virtual void enterList_of_ports(SV2012Parser::List_of_portsContext *ctx) = 0;
  virtual void exitList_of_ports(SV2012Parser::List_of_portsContext *ctx) = 0;

  virtual void enterList_of_port_declarations(SV2012Parser::List_of_port_declarationsContext *ctx) = 0;
  virtual void exitList_of_port_declarations(SV2012Parser::List_of_port_declarationsContext *ctx) = 0;

  virtual void enterPort_declaration(SV2012Parser::Port_declarationContext *ctx) = 0;
  virtual void exitPort_declaration(SV2012Parser::Port_declarationContext *ctx) = 0;

  virtual void enterPort(SV2012Parser::PortContext *ctx) = 0;
  virtual void exitPort(SV2012Parser::PortContext *ctx) = 0;

  virtual void enterPort_expression(SV2012Parser::Port_expressionContext *ctx) = 0;
  virtual void exitPort_expression(SV2012Parser::Port_expressionContext *ctx) = 0;

  virtual void enterPort_reference(SV2012Parser::Port_referenceContext *ctx) = 0;
  virtual void exitPort_reference(SV2012Parser::Port_referenceContext *ctx) = 0;

  virtual void enterPort_direction(SV2012Parser::Port_directionContext *ctx) = 0;
  virtual void exitPort_direction(SV2012Parser::Port_directionContext *ctx) = 0;

  virtual void enterNet_port_header(SV2012Parser::Net_port_headerContext *ctx) = 0;
  virtual void exitNet_port_header(SV2012Parser::Net_port_headerContext *ctx) = 0;

  virtual void enterVariable_port_header(SV2012Parser::Variable_port_headerContext *ctx) = 0;
  virtual void exitVariable_port_header(SV2012Parser::Variable_port_headerContext *ctx) = 0;

  virtual void enterInterface_port_header(SV2012Parser::Interface_port_headerContext *ctx) = 0;
  virtual void exitInterface_port_header(SV2012Parser::Interface_port_headerContext *ctx) = 0;

  virtual void enterAnsi_port_declaration(SV2012Parser::Ansi_port_declarationContext *ctx) = 0;
  virtual void exitAnsi_port_declaration(SV2012Parser::Ansi_port_declarationContext *ctx) = 0;

  virtual void enterElaboration_system_task(SV2012Parser::Elaboration_system_taskContext *ctx) = 0;
  virtual void exitElaboration_system_task(SV2012Parser::Elaboration_system_taskContext *ctx) = 0;

  virtual void enterFinish_number(SV2012Parser::Finish_numberContext *ctx) = 0;
  virtual void exitFinish_number(SV2012Parser::Finish_numberContext *ctx) = 0;

  virtual void enterModule_common_item(SV2012Parser::Module_common_itemContext *ctx) = 0;
  virtual void exitModule_common_item(SV2012Parser::Module_common_itemContext *ctx) = 0;

  virtual void enterModule_item(SV2012Parser::Module_itemContext *ctx) = 0;
  virtual void exitModule_item(SV2012Parser::Module_itemContext *ctx) = 0;

  virtual void enterModule_or_generate_item(SV2012Parser::Module_or_generate_itemContext *ctx) = 0;
  virtual void exitModule_or_generate_item(SV2012Parser::Module_or_generate_itemContext *ctx) = 0;

  virtual void enterModule_or_generate_item_declaration(SV2012Parser::Module_or_generate_item_declarationContext *ctx) = 0;
  virtual void exitModule_or_generate_item_declaration(SV2012Parser::Module_or_generate_item_declarationContext *ctx) = 0;

  virtual void enterNon_port_module_item(SV2012Parser::Non_port_module_itemContext *ctx) = 0;
  virtual void exitNon_port_module_item(SV2012Parser::Non_port_module_itemContext *ctx) = 0;

  virtual void enterParameter_override(SV2012Parser::Parameter_overrideContext *ctx) = 0;
  virtual void exitParameter_override(SV2012Parser::Parameter_overrideContext *ctx) = 0;

  virtual void enterBind_directive(SV2012Parser::Bind_directiveContext *ctx) = 0;
  virtual void exitBind_directive(SV2012Parser::Bind_directiveContext *ctx) = 0;

  virtual void enterBind_target_scope(SV2012Parser::Bind_target_scopeContext *ctx) = 0;
  virtual void exitBind_target_scope(SV2012Parser::Bind_target_scopeContext *ctx) = 0;

  virtual void enterBind_target_instance(SV2012Parser::Bind_target_instanceContext *ctx) = 0;
  virtual void exitBind_target_instance(SV2012Parser::Bind_target_instanceContext *ctx) = 0;

  virtual void enterBind_target_instance_list(SV2012Parser::Bind_target_instance_listContext *ctx) = 0;
  virtual void exitBind_target_instance_list(SV2012Parser::Bind_target_instance_listContext *ctx) = 0;

  virtual void enterBind_instantiation(SV2012Parser::Bind_instantiationContext *ctx) = 0;
  virtual void exitBind_instantiation(SV2012Parser::Bind_instantiationContext *ctx) = 0;

  virtual void enterConfig_declaration(SV2012Parser::Config_declarationContext *ctx) = 0;
  virtual void exitConfig_declaration(SV2012Parser::Config_declarationContext *ctx) = 0;

  virtual void enterDesign_statement(SV2012Parser::Design_statementContext *ctx) = 0;
  virtual void exitDesign_statement(SV2012Parser::Design_statementContext *ctx) = 0;

  virtual void enterConfig_rule_statement(SV2012Parser::Config_rule_statementContext *ctx) = 0;
  virtual void exitConfig_rule_statement(SV2012Parser::Config_rule_statementContext *ctx) = 0;

  virtual void enterDefault_clause(SV2012Parser::Default_clauseContext *ctx) = 0;
  virtual void exitDefault_clause(SV2012Parser::Default_clauseContext *ctx) = 0;

  virtual void enterInst_clause(SV2012Parser::Inst_clauseContext *ctx) = 0;
  virtual void exitInst_clause(SV2012Parser::Inst_clauseContext *ctx) = 0;

  virtual void enterInst_name(SV2012Parser::Inst_nameContext *ctx) = 0;
  virtual void exitInst_name(SV2012Parser::Inst_nameContext *ctx) = 0;

  virtual void enterCell_clause(SV2012Parser::Cell_clauseContext *ctx) = 0;
  virtual void exitCell_clause(SV2012Parser::Cell_clauseContext *ctx) = 0;

  virtual void enterLiblist_clause(SV2012Parser::Liblist_clauseContext *ctx) = 0;
  virtual void exitLiblist_clause(SV2012Parser::Liblist_clauseContext *ctx) = 0;

  virtual void enterUse_clause(SV2012Parser::Use_clauseContext *ctx) = 0;
  virtual void exitUse_clause(SV2012Parser::Use_clauseContext *ctx) = 0;

  virtual void enterInterface_or_generate_item(SV2012Parser::Interface_or_generate_itemContext *ctx) = 0;
  virtual void exitInterface_or_generate_item(SV2012Parser::Interface_or_generate_itemContext *ctx) = 0;

  virtual void enterExtern_tf_declaration(SV2012Parser::Extern_tf_declarationContext *ctx) = 0;
  virtual void exitExtern_tf_declaration(SV2012Parser::Extern_tf_declarationContext *ctx) = 0;

  virtual void enterInterface_item(SV2012Parser::Interface_itemContext *ctx) = 0;
  virtual void exitInterface_item(SV2012Parser::Interface_itemContext *ctx) = 0;

  virtual void enterNon_port_interface_item(SV2012Parser::Non_port_interface_itemContext *ctx) = 0;
  virtual void exitNon_port_interface_item(SV2012Parser::Non_port_interface_itemContext *ctx) = 0;

  virtual void enterProgram_item(SV2012Parser::Program_itemContext *ctx) = 0;
  virtual void exitProgram_item(SV2012Parser::Program_itemContext *ctx) = 0;

  virtual void enterNon_port_program_item(SV2012Parser::Non_port_program_itemContext *ctx) = 0;
  virtual void exitNon_port_program_item(SV2012Parser::Non_port_program_itemContext *ctx) = 0;

  virtual void enterProgram_generate_item(SV2012Parser::Program_generate_itemContext *ctx) = 0;
  virtual void exitProgram_generate_item(SV2012Parser::Program_generate_itemContext *ctx) = 0;

  virtual void enterChecker_port_list(SV2012Parser::Checker_port_listContext *ctx) = 0;
  virtual void exitChecker_port_list(SV2012Parser::Checker_port_listContext *ctx) = 0;

  virtual void enterChecker_port_item(SV2012Parser::Checker_port_itemContext *ctx) = 0;
  virtual void exitChecker_port_item(SV2012Parser::Checker_port_itemContext *ctx) = 0;

  virtual void enterChecker_port_direction(SV2012Parser::Checker_port_directionContext *ctx) = 0;
  virtual void exitChecker_port_direction(SV2012Parser::Checker_port_directionContext *ctx) = 0;

  virtual void enterChecker_or_generate_item(SV2012Parser::Checker_or_generate_itemContext *ctx) = 0;
  virtual void exitChecker_or_generate_item(SV2012Parser::Checker_or_generate_itemContext *ctx) = 0;

  virtual void enterChecker_or_generate_item_declaration(SV2012Parser::Checker_or_generate_item_declarationContext *ctx) = 0;
  virtual void exitChecker_or_generate_item_declaration(SV2012Parser::Checker_or_generate_item_declarationContext *ctx) = 0;

  virtual void enterChecker_generate_item(SV2012Parser::Checker_generate_itemContext *ctx) = 0;
  virtual void exitChecker_generate_item(SV2012Parser::Checker_generate_itemContext *ctx) = 0;

  virtual void enterClass_item(SV2012Parser::Class_itemContext *ctx) = 0;
  virtual void exitClass_item(SV2012Parser::Class_itemContext *ctx) = 0;

  virtual void enterClass_property(SV2012Parser::Class_propertyContext *ctx) = 0;
  virtual void exitClass_property(SV2012Parser::Class_propertyContext *ctx) = 0;

  virtual void enterClass_method(SV2012Parser::Class_methodContext *ctx) = 0;
  virtual void exitClass_method(SV2012Parser::Class_methodContext *ctx) = 0;

  virtual void enterClass_constructor_prototype(SV2012Parser::Class_constructor_prototypeContext *ctx) = 0;
  virtual void exitClass_constructor_prototype(SV2012Parser::Class_constructor_prototypeContext *ctx) = 0;

  virtual void enterClass_constraint(SV2012Parser::Class_constraintContext *ctx) = 0;
  virtual void exitClass_constraint(SV2012Parser::Class_constraintContext *ctx) = 0;

  virtual void enterClass_item_qualifier(SV2012Parser::Class_item_qualifierContext *ctx) = 0;
  virtual void exitClass_item_qualifier(SV2012Parser::Class_item_qualifierContext *ctx) = 0;

  virtual void enterProperty_qualifier(SV2012Parser::Property_qualifierContext *ctx) = 0;
  virtual void exitProperty_qualifier(SV2012Parser::Property_qualifierContext *ctx) = 0;

  virtual void enterRandom_qualifier(SV2012Parser::Random_qualifierContext *ctx) = 0;
  virtual void exitRandom_qualifier(SV2012Parser::Random_qualifierContext *ctx) = 0;

  virtual void enterMethod_qualifier(SV2012Parser::Method_qualifierContext *ctx) = 0;
  virtual void exitMethod_qualifier(SV2012Parser::Method_qualifierContext *ctx) = 0;

  virtual void enterMethod_prototype(SV2012Parser::Method_prototypeContext *ctx) = 0;
  virtual void exitMethod_prototype(SV2012Parser::Method_prototypeContext *ctx) = 0;

  virtual void enterClass_constructor_declaration(SV2012Parser::Class_constructor_declarationContext *ctx) = 0;
  virtual void exitClass_constructor_declaration(SV2012Parser::Class_constructor_declarationContext *ctx) = 0;

  virtual void enterConstraint_declaration(SV2012Parser::Constraint_declarationContext *ctx) = 0;
  virtual void exitConstraint_declaration(SV2012Parser::Constraint_declarationContext *ctx) = 0;

  virtual void enterConstraint_block(SV2012Parser::Constraint_blockContext *ctx) = 0;
  virtual void exitConstraint_block(SV2012Parser::Constraint_blockContext *ctx) = 0;

  virtual void enterConstraint_block_item(SV2012Parser::Constraint_block_itemContext *ctx) = 0;
  virtual void exitConstraint_block_item(SV2012Parser::Constraint_block_itemContext *ctx) = 0;

  virtual void enterSolve_before_list(SV2012Parser::Solve_before_listContext *ctx) = 0;
  virtual void exitSolve_before_list(SV2012Parser::Solve_before_listContext *ctx) = 0;

  virtual void enterConstraint_primary(SV2012Parser::Constraint_primaryContext *ctx) = 0;
  virtual void exitConstraint_primary(SV2012Parser::Constraint_primaryContext *ctx) = 0;

  virtual void enterConstraint_expression(SV2012Parser::Constraint_expressionContext *ctx) = 0;
  virtual void exitConstraint_expression(SV2012Parser::Constraint_expressionContext *ctx) = 0;

  virtual void enterUniqueness_constraint(SV2012Parser::Uniqueness_constraintContext *ctx) = 0;
  virtual void exitUniqueness_constraint(SV2012Parser::Uniqueness_constraintContext *ctx) = 0;

  virtual void enterConstraint_set(SV2012Parser::Constraint_setContext *ctx) = 0;
  virtual void exitConstraint_set(SV2012Parser::Constraint_setContext *ctx) = 0;

  virtual void enterDist_list(SV2012Parser::Dist_listContext *ctx) = 0;
  virtual void exitDist_list(SV2012Parser::Dist_listContext *ctx) = 0;

  virtual void enterDist_item(SV2012Parser::Dist_itemContext *ctx) = 0;
  virtual void exitDist_item(SV2012Parser::Dist_itemContext *ctx) = 0;

  virtual void enterDist_weight(SV2012Parser::Dist_weightContext *ctx) = 0;
  virtual void exitDist_weight(SV2012Parser::Dist_weightContext *ctx) = 0;

  virtual void enterConstraint_prototype(SV2012Parser::Constraint_prototypeContext *ctx) = 0;
  virtual void exitConstraint_prototype(SV2012Parser::Constraint_prototypeContext *ctx) = 0;

  virtual void enterConstraint_prototype_qualifier(SV2012Parser::Constraint_prototype_qualifierContext *ctx) = 0;
  virtual void exitConstraint_prototype_qualifier(SV2012Parser::Constraint_prototype_qualifierContext *ctx) = 0;

  virtual void enterExtern_constraint_declaration(SV2012Parser::Extern_constraint_declarationContext *ctx) = 0;
  virtual void exitExtern_constraint_declaration(SV2012Parser::Extern_constraint_declarationContext *ctx) = 0;

  virtual void enterIdentifier_list(SV2012Parser::Identifier_listContext *ctx) = 0;
  virtual void exitIdentifier_list(SV2012Parser::Identifier_listContext *ctx) = 0;

  virtual void enterPackage_item(SV2012Parser::Package_itemContext *ctx) = 0;
  virtual void exitPackage_item(SV2012Parser::Package_itemContext *ctx) = 0;

  virtual void enterPackage_or_generate_item_declaration(SV2012Parser::Package_or_generate_item_declarationContext *ctx) = 0;
  virtual void exitPackage_or_generate_item_declaration(SV2012Parser::Package_or_generate_item_declarationContext *ctx) = 0;

  virtual void enterAnonymous_program(SV2012Parser::Anonymous_programContext *ctx) = 0;
  virtual void exitAnonymous_program(SV2012Parser::Anonymous_programContext *ctx) = 0;

  virtual void enterAnonymous_program_item(SV2012Parser::Anonymous_program_itemContext *ctx) = 0;
  virtual void exitAnonymous_program_item(SV2012Parser::Anonymous_program_itemContext *ctx) = 0;

  virtual void enterLocal_parameter_declaration(SV2012Parser::Local_parameter_declarationContext *ctx) = 0;
  virtual void exitLocal_parameter_declaration(SV2012Parser::Local_parameter_declarationContext *ctx) = 0;

  virtual void enterParameter_declaration(SV2012Parser::Parameter_declarationContext *ctx) = 0;
  virtual void exitParameter_declaration(SV2012Parser::Parameter_declarationContext *ctx) = 0;

  virtual void enterSpecparam_declaration(SV2012Parser::Specparam_declarationContext *ctx) = 0;
  virtual void exitSpecparam_declaration(SV2012Parser::Specparam_declarationContext *ctx) = 0;

  virtual void enterInout_declaration(SV2012Parser::Inout_declarationContext *ctx) = 0;
  virtual void exitInout_declaration(SV2012Parser::Inout_declarationContext *ctx) = 0;

  virtual void enterInput_declaration(SV2012Parser::Input_declarationContext *ctx) = 0;
  virtual void exitInput_declaration(SV2012Parser::Input_declarationContext *ctx) = 0;

  virtual void enterOutput_declaration(SV2012Parser::Output_declarationContext *ctx) = 0;
  virtual void exitOutput_declaration(SV2012Parser::Output_declarationContext *ctx) = 0;

  virtual void enterInterface_port_declaration(SV2012Parser::Interface_port_declarationContext *ctx) = 0;
  virtual void exitInterface_port_declaration(SV2012Parser::Interface_port_declarationContext *ctx) = 0;

  virtual void enterRef_declaration(SV2012Parser::Ref_declarationContext *ctx) = 0;
  virtual void exitRef_declaration(SV2012Parser::Ref_declarationContext *ctx) = 0;

  virtual void enterData_declaration(SV2012Parser::Data_declarationContext *ctx) = 0;
  virtual void exitData_declaration(SV2012Parser::Data_declarationContext *ctx) = 0;

  virtual void enterPackage_import_declaration(SV2012Parser::Package_import_declarationContext *ctx) = 0;
  virtual void exitPackage_import_declaration(SV2012Parser::Package_import_declarationContext *ctx) = 0;

  virtual void enterPackage_import_item(SV2012Parser::Package_import_itemContext *ctx) = 0;
  virtual void exitPackage_import_item(SV2012Parser::Package_import_itemContext *ctx) = 0;

  virtual void enterPackage_export_declaration(SV2012Parser::Package_export_declarationContext *ctx) = 0;
  virtual void exitPackage_export_declaration(SV2012Parser::Package_export_declarationContext *ctx) = 0;

  virtual void enterGenvar_declaration(SV2012Parser::Genvar_declarationContext *ctx) = 0;
  virtual void exitGenvar_declaration(SV2012Parser::Genvar_declarationContext *ctx) = 0;

  virtual void enterNet_declaration(SV2012Parser::Net_declarationContext *ctx) = 0;
  virtual void exitNet_declaration(SV2012Parser::Net_declarationContext *ctx) = 0;

  virtual void enterType_declaration(SV2012Parser::Type_declarationContext *ctx) = 0;
  virtual void exitType_declaration(SV2012Parser::Type_declarationContext *ctx) = 0;

  virtual void enterNet_type_declaration(SV2012Parser::Net_type_declarationContext *ctx) = 0;
  virtual void exitNet_type_declaration(SV2012Parser::Net_type_declarationContext *ctx) = 0;

  virtual void enterLifetime(SV2012Parser::LifetimeContext *ctx) = 0;
  virtual void exitLifetime(SV2012Parser::LifetimeContext *ctx) = 0;

  virtual void enterCasting_type(SV2012Parser::Casting_typeContext *ctx) = 0;
  virtual void exitCasting_type(SV2012Parser::Casting_typeContext *ctx) = 0;

  virtual void enterData_type(SV2012Parser::Data_typeContext *ctx) = 0;
  virtual void exitData_type(SV2012Parser::Data_typeContext *ctx) = 0;

  virtual void enterData_type_or_implicit(SV2012Parser::Data_type_or_implicitContext *ctx) = 0;
  virtual void exitData_type_or_implicit(SV2012Parser::Data_type_or_implicitContext *ctx) = 0;

  virtual void enterImplicit_data_type(SV2012Parser::Implicit_data_typeContext *ctx) = 0;
  virtual void exitImplicit_data_type(SV2012Parser::Implicit_data_typeContext *ctx) = 0;

  virtual void enterEnum_base_type(SV2012Parser::Enum_base_typeContext *ctx) = 0;
  virtual void exitEnum_base_type(SV2012Parser::Enum_base_typeContext *ctx) = 0;

  virtual void enterEnum_name_declaration(SV2012Parser::Enum_name_declarationContext *ctx) = 0;
  virtual void exitEnum_name_declaration(SV2012Parser::Enum_name_declarationContext *ctx) = 0;

  virtual void enterClass_scope(SV2012Parser::Class_scopeContext *ctx) = 0;
  virtual void exitClass_scope(SV2012Parser::Class_scopeContext *ctx) = 0;

  virtual void enterClass_type(SV2012Parser::Class_typeContext *ctx) = 0;
  virtual void exitClass_type(SV2012Parser::Class_typeContext *ctx) = 0;

  virtual void enterInteger_type(SV2012Parser::Integer_typeContext *ctx) = 0;
  virtual void exitInteger_type(SV2012Parser::Integer_typeContext *ctx) = 0;

  virtual void enterInteger_atom_type(SV2012Parser::Integer_atom_typeContext *ctx) = 0;
  virtual void exitInteger_atom_type(SV2012Parser::Integer_atom_typeContext *ctx) = 0;

  virtual void enterInteger_vector_type(SV2012Parser::Integer_vector_typeContext *ctx) = 0;
  virtual void exitInteger_vector_type(SV2012Parser::Integer_vector_typeContext *ctx) = 0;

  virtual void enterNon_integer_type(SV2012Parser::Non_integer_typeContext *ctx) = 0;
  virtual void exitNon_integer_type(SV2012Parser::Non_integer_typeContext *ctx) = 0;

  virtual void enterNet_type(SV2012Parser::Net_typeContext *ctx) = 0;
  virtual void exitNet_type(SV2012Parser::Net_typeContext *ctx) = 0;

  virtual void enterNet_port_type(SV2012Parser::Net_port_typeContext *ctx) = 0;
  virtual void exitNet_port_type(SV2012Parser::Net_port_typeContext *ctx) = 0;

  virtual void enterVariable_port_type(SV2012Parser::Variable_port_typeContext *ctx) = 0;
  virtual void exitVariable_port_type(SV2012Parser::Variable_port_typeContext *ctx) = 0;

  virtual void enterVar_data_type(SV2012Parser::Var_data_typeContext *ctx) = 0;
  virtual void exitVar_data_type(SV2012Parser::Var_data_typeContext *ctx) = 0;

  virtual void enterSigning(SV2012Parser::SigningContext *ctx) = 0;
  virtual void exitSigning(SV2012Parser::SigningContext *ctx) = 0;

  virtual void enterSimple_type(SV2012Parser::Simple_typeContext *ctx) = 0;
  virtual void exitSimple_type(SV2012Parser::Simple_typeContext *ctx) = 0;

  virtual void enterStruct_union_member(SV2012Parser::Struct_union_memberContext *ctx) = 0;
  virtual void exitStruct_union_member(SV2012Parser::Struct_union_memberContext *ctx) = 0;

  virtual void enterData_type_or_void(SV2012Parser::Data_type_or_voidContext *ctx) = 0;
  virtual void exitData_type_or_void(SV2012Parser::Data_type_or_voidContext *ctx) = 0;

  virtual void enterStruct_union(SV2012Parser::Struct_unionContext *ctx) = 0;
  virtual void exitStruct_union(SV2012Parser::Struct_unionContext *ctx) = 0;

  virtual void enterType_reference(SV2012Parser::Type_referenceContext *ctx) = 0;
  virtual void exitType_reference(SV2012Parser::Type_referenceContext *ctx) = 0;

  virtual void enterDrive_strength(SV2012Parser::Drive_strengthContext *ctx) = 0;
  virtual void exitDrive_strength(SV2012Parser::Drive_strengthContext *ctx) = 0;

  virtual void enterStrength0(SV2012Parser::Strength0Context *ctx) = 0;
  virtual void exitStrength0(SV2012Parser::Strength0Context *ctx) = 0;

  virtual void enterStrength1(SV2012Parser::Strength1Context *ctx) = 0;
  virtual void exitStrength1(SV2012Parser::Strength1Context *ctx) = 0;

  virtual void enterCharge_strength(SV2012Parser::Charge_strengthContext *ctx) = 0;
  virtual void exitCharge_strength(SV2012Parser::Charge_strengthContext *ctx) = 0;

  virtual void enterDelay3(SV2012Parser::Delay3Context *ctx) = 0;
  virtual void exitDelay3(SV2012Parser::Delay3Context *ctx) = 0;

  virtual void enterDelay2(SV2012Parser::Delay2Context *ctx) = 0;
  virtual void exitDelay2(SV2012Parser::Delay2Context *ctx) = 0;

  virtual void enterDelay_value(SV2012Parser::Delay_valueContext *ctx) = 0;
  virtual void exitDelay_value(SV2012Parser::Delay_valueContext *ctx) = 0;

  virtual void enterList_of_defparam_assignments(SV2012Parser::List_of_defparam_assignmentsContext *ctx) = 0;
  virtual void exitList_of_defparam_assignments(SV2012Parser::List_of_defparam_assignmentsContext *ctx) = 0;

  virtual void enterList_of_genvar_identifiers(SV2012Parser::List_of_genvar_identifiersContext *ctx) = 0;
  virtual void exitList_of_genvar_identifiers(SV2012Parser::List_of_genvar_identifiersContext *ctx) = 0;

  virtual void enterList_of_interface_identifiers(SV2012Parser::List_of_interface_identifiersContext *ctx) = 0;
  virtual void exitList_of_interface_identifiers(SV2012Parser::List_of_interface_identifiersContext *ctx) = 0;

  virtual void enterList_of_net_decl_assignments(SV2012Parser::List_of_net_decl_assignmentsContext *ctx) = 0;
  virtual void exitList_of_net_decl_assignments(SV2012Parser::List_of_net_decl_assignmentsContext *ctx) = 0;

  virtual void enterList_of_param_assignments(SV2012Parser::List_of_param_assignmentsContext *ctx) = 0;
  virtual void exitList_of_param_assignments(SV2012Parser::List_of_param_assignmentsContext *ctx) = 0;

  virtual void enterList_of_port_identifiers(SV2012Parser::List_of_port_identifiersContext *ctx) = 0;
  virtual void exitList_of_port_identifiers(SV2012Parser::List_of_port_identifiersContext *ctx) = 0;

  virtual void enterList_of_udp_port_identifiers(SV2012Parser::List_of_udp_port_identifiersContext *ctx) = 0;
  virtual void exitList_of_udp_port_identifiers(SV2012Parser::List_of_udp_port_identifiersContext *ctx) = 0;

  virtual void enterList_of_specparam_assignments(SV2012Parser::List_of_specparam_assignmentsContext *ctx) = 0;
  virtual void exitList_of_specparam_assignments(SV2012Parser::List_of_specparam_assignmentsContext *ctx) = 0;

  virtual void enterList_of_tf_variable_identifiers(SV2012Parser::List_of_tf_variable_identifiersContext *ctx) = 0;
  virtual void exitList_of_tf_variable_identifiers(SV2012Parser::List_of_tf_variable_identifiersContext *ctx) = 0;

  virtual void enterList_of_type_assignments(SV2012Parser::List_of_type_assignmentsContext *ctx) = 0;
  virtual void exitList_of_type_assignments(SV2012Parser::List_of_type_assignmentsContext *ctx) = 0;

  virtual void enterList_of_variable_decl_assignments(SV2012Parser::List_of_variable_decl_assignmentsContext *ctx) = 0;
  virtual void exitList_of_variable_decl_assignments(SV2012Parser::List_of_variable_decl_assignmentsContext *ctx) = 0;

  virtual void enterList_of_variable_identifiers(SV2012Parser::List_of_variable_identifiersContext *ctx) = 0;
  virtual void exitList_of_variable_identifiers(SV2012Parser::List_of_variable_identifiersContext *ctx) = 0;

  virtual void enterList_of_variable_port_identifiers(SV2012Parser::List_of_variable_port_identifiersContext *ctx) = 0;
  virtual void exitList_of_variable_port_identifiers(SV2012Parser::List_of_variable_port_identifiersContext *ctx) = 0;

  virtual void enterDefparam_assignment(SV2012Parser::Defparam_assignmentContext *ctx) = 0;
  virtual void exitDefparam_assignment(SV2012Parser::Defparam_assignmentContext *ctx) = 0;

  virtual void enterNet_decl_assignment(SV2012Parser::Net_decl_assignmentContext *ctx) = 0;
  virtual void exitNet_decl_assignment(SV2012Parser::Net_decl_assignmentContext *ctx) = 0;

  virtual void enterParam_assignment(SV2012Parser::Param_assignmentContext *ctx) = 0;
  virtual void exitParam_assignment(SV2012Parser::Param_assignmentContext *ctx) = 0;

  virtual void enterSpecparam_assignment(SV2012Parser::Specparam_assignmentContext *ctx) = 0;
  virtual void exitSpecparam_assignment(SV2012Parser::Specparam_assignmentContext *ctx) = 0;

  virtual void enterType_assignment(SV2012Parser::Type_assignmentContext *ctx) = 0;
  virtual void exitType_assignment(SV2012Parser::Type_assignmentContext *ctx) = 0;

  virtual void enterPulse_control_specparam(SV2012Parser::Pulse_control_specparamContext *ctx) = 0;
  virtual void exitPulse_control_specparam(SV2012Parser::Pulse_control_specparamContext *ctx) = 0;

  virtual void enterError_limit_value(SV2012Parser::Error_limit_valueContext *ctx) = 0;
  virtual void exitError_limit_value(SV2012Parser::Error_limit_valueContext *ctx) = 0;

  virtual void enterReject_limit_value(SV2012Parser::Reject_limit_valueContext *ctx) = 0;
  virtual void exitReject_limit_value(SV2012Parser::Reject_limit_valueContext *ctx) = 0;

  virtual void enterLimit_value(SV2012Parser::Limit_valueContext *ctx) = 0;
  virtual void exitLimit_value(SV2012Parser::Limit_valueContext *ctx) = 0;

  virtual void enterVariable_decl_assignment(SV2012Parser::Variable_decl_assignmentContext *ctx) = 0;
  virtual void exitVariable_decl_assignment(SV2012Parser::Variable_decl_assignmentContext *ctx) = 0;

  virtual void enterClass_new(SV2012Parser::Class_newContext *ctx) = 0;
  virtual void exitClass_new(SV2012Parser::Class_newContext *ctx) = 0;

  virtual void enterDynamic_array_new(SV2012Parser::Dynamic_array_newContext *ctx) = 0;
  virtual void exitDynamic_array_new(SV2012Parser::Dynamic_array_newContext *ctx) = 0;

  virtual void enterUnpacked_dimension(SV2012Parser::Unpacked_dimensionContext *ctx) = 0;
  virtual void exitUnpacked_dimension(SV2012Parser::Unpacked_dimensionContext *ctx) = 0;

  virtual void enterPacked_dimension(SV2012Parser::Packed_dimensionContext *ctx) = 0;
  virtual void exitPacked_dimension(SV2012Parser::Packed_dimensionContext *ctx) = 0;

  virtual void enterAssociative_dimension(SV2012Parser::Associative_dimensionContext *ctx) = 0;
  virtual void exitAssociative_dimension(SV2012Parser::Associative_dimensionContext *ctx) = 0;

  virtual void enterVariable_dimension(SV2012Parser::Variable_dimensionContext *ctx) = 0;
  virtual void exitVariable_dimension(SV2012Parser::Variable_dimensionContext *ctx) = 0;

  virtual void enterQueue_dimension(SV2012Parser::Queue_dimensionContext *ctx) = 0;
  virtual void exitQueue_dimension(SV2012Parser::Queue_dimensionContext *ctx) = 0;

  virtual void enterUnsized_dimension(SV2012Parser::Unsized_dimensionContext *ctx) = 0;
  virtual void exitUnsized_dimension(SV2012Parser::Unsized_dimensionContext *ctx) = 0;

  virtual void enterFunction_data_type_or_implicit(SV2012Parser::Function_data_type_or_implicitContext *ctx) = 0;
  virtual void exitFunction_data_type_or_implicit(SV2012Parser::Function_data_type_or_implicitContext *ctx) = 0;

  virtual void enterFunction_declaration(SV2012Parser::Function_declarationContext *ctx) = 0;
  virtual void exitFunction_declaration(SV2012Parser::Function_declarationContext *ctx) = 0;

  virtual void enterFunction_body_declaration(SV2012Parser::Function_body_declarationContext *ctx) = 0;
  virtual void exitFunction_body_declaration(SV2012Parser::Function_body_declarationContext *ctx) = 0;

  virtual void enterFunction_prototype(SV2012Parser::Function_prototypeContext *ctx) = 0;
  virtual void exitFunction_prototype(SV2012Parser::Function_prototypeContext *ctx) = 0;

  virtual void enterDpi_import_export(SV2012Parser::Dpi_import_exportContext *ctx) = 0;
  virtual void exitDpi_import_export(SV2012Parser::Dpi_import_exportContext *ctx) = 0;

  virtual void enterDpi_spec_string(SV2012Parser::Dpi_spec_stringContext *ctx) = 0;
  virtual void exitDpi_spec_string(SV2012Parser::Dpi_spec_stringContext *ctx) = 0;

  virtual void enterDpi_function_import_property(SV2012Parser::Dpi_function_import_propertyContext *ctx) = 0;
  virtual void exitDpi_function_import_property(SV2012Parser::Dpi_function_import_propertyContext *ctx) = 0;

  virtual void enterDpi_task_import_property(SV2012Parser::Dpi_task_import_propertyContext *ctx) = 0;
  virtual void exitDpi_task_import_property(SV2012Parser::Dpi_task_import_propertyContext *ctx) = 0;

  virtual void enterDpi_function_proto(SV2012Parser::Dpi_function_protoContext *ctx) = 0;
  virtual void exitDpi_function_proto(SV2012Parser::Dpi_function_protoContext *ctx) = 0;

  virtual void enterDpi_task_proto(SV2012Parser::Dpi_task_protoContext *ctx) = 0;
  virtual void exitDpi_task_proto(SV2012Parser::Dpi_task_protoContext *ctx) = 0;

  virtual void enterTask_declaration(SV2012Parser::Task_declarationContext *ctx) = 0;
  virtual void exitTask_declaration(SV2012Parser::Task_declarationContext *ctx) = 0;

  virtual void enterTask_body_declaration(SV2012Parser::Task_body_declarationContext *ctx) = 0;
  virtual void exitTask_body_declaration(SV2012Parser::Task_body_declarationContext *ctx) = 0;

  virtual void enterTf_item_declaration(SV2012Parser::Tf_item_declarationContext *ctx) = 0;
  virtual void exitTf_item_declaration(SV2012Parser::Tf_item_declarationContext *ctx) = 0;

  virtual void enterTf_port_list(SV2012Parser::Tf_port_listContext *ctx) = 0;
  virtual void exitTf_port_list(SV2012Parser::Tf_port_listContext *ctx) = 0;

  virtual void enterTf_port_item(SV2012Parser::Tf_port_itemContext *ctx) = 0;
  virtual void exitTf_port_item(SV2012Parser::Tf_port_itemContext *ctx) = 0;

  virtual void enterTf_port_direction(SV2012Parser::Tf_port_directionContext *ctx) = 0;
  virtual void exitTf_port_direction(SV2012Parser::Tf_port_directionContext *ctx) = 0;

  virtual void enterTf_port_declaration(SV2012Parser::Tf_port_declarationContext *ctx) = 0;
  virtual void exitTf_port_declaration(SV2012Parser::Tf_port_declarationContext *ctx) = 0;

  virtual void enterTf_prototype_port_item(SV2012Parser::Tf_prototype_port_itemContext *ctx) = 0;
  virtual void exitTf_prototype_port_item(SV2012Parser::Tf_prototype_port_itemContext *ctx) = 0;

  virtual void enterTf_prototype_port_list(SV2012Parser::Tf_prototype_port_listContext *ctx) = 0;
  virtual void exitTf_prototype_port_list(SV2012Parser::Tf_prototype_port_listContext *ctx) = 0;

  virtual void enterTask_prototype(SV2012Parser::Task_prototypeContext *ctx) = 0;
  virtual void exitTask_prototype(SV2012Parser::Task_prototypeContext *ctx) = 0;

  virtual void enterBlock_item_declaration(SV2012Parser::Block_item_declarationContext *ctx) = 0;
  virtual void exitBlock_item_declaration(SV2012Parser::Block_item_declarationContext *ctx) = 0;

  virtual void enterOverload_declaration(SV2012Parser::Overload_declarationContext *ctx) = 0;
  virtual void exitOverload_declaration(SV2012Parser::Overload_declarationContext *ctx) = 0;

  virtual void enterOverload_operator(SV2012Parser::Overload_operatorContext *ctx) = 0;
  virtual void exitOverload_operator(SV2012Parser::Overload_operatorContext *ctx) = 0;

  virtual void enterOverload_proto_formals(SV2012Parser::Overload_proto_formalsContext *ctx) = 0;
  virtual void exitOverload_proto_formals(SV2012Parser::Overload_proto_formalsContext *ctx) = 0;

  virtual void enterModport_declaration(SV2012Parser::Modport_declarationContext *ctx) = 0;
  virtual void exitModport_declaration(SV2012Parser::Modport_declarationContext *ctx) = 0;

  virtual void enterModport_item(SV2012Parser::Modport_itemContext *ctx) = 0;
  virtual void exitModport_item(SV2012Parser::Modport_itemContext *ctx) = 0;

  virtual void enterModport_ports_declaration(SV2012Parser::Modport_ports_declarationContext *ctx) = 0;
  virtual void exitModport_ports_declaration(SV2012Parser::Modport_ports_declarationContext *ctx) = 0;

  virtual void enterModport_clocking_declaration(SV2012Parser::Modport_clocking_declarationContext *ctx) = 0;
  virtual void exitModport_clocking_declaration(SV2012Parser::Modport_clocking_declarationContext *ctx) = 0;

  virtual void enterModport_simple_ports_declaration(SV2012Parser::Modport_simple_ports_declarationContext *ctx) = 0;
  virtual void exitModport_simple_ports_declaration(SV2012Parser::Modport_simple_ports_declarationContext *ctx) = 0;

  virtual void enterModport_simple_port(SV2012Parser::Modport_simple_portContext *ctx) = 0;
  virtual void exitModport_simple_port(SV2012Parser::Modport_simple_portContext *ctx) = 0;

  virtual void enterModport_tf_ports_declaration(SV2012Parser::Modport_tf_ports_declarationContext *ctx) = 0;
  virtual void exitModport_tf_ports_declaration(SV2012Parser::Modport_tf_ports_declarationContext *ctx) = 0;

  virtual void enterModport_tf_port(SV2012Parser::Modport_tf_portContext *ctx) = 0;
  virtual void exitModport_tf_port(SV2012Parser::Modport_tf_portContext *ctx) = 0;

  virtual void enterImport_export(SV2012Parser::Import_exportContext *ctx) = 0;
  virtual void exitImport_export(SV2012Parser::Import_exportContext *ctx) = 0;

  virtual void enterConcurrent_assertion_item(SV2012Parser::Concurrent_assertion_itemContext *ctx) = 0;
  virtual void exitConcurrent_assertion_item(SV2012Parser::Concurrent_assertion_itemContext *ctx) = 0;

  virtual void enterConcurrent_assertion_statement(SV2012Parser::Concurrent_assertion_statementContext *ctx) = 0;
  virtual void exitConcurrent_assertion_statement(SV2012Parser::Concurrent_assertion_statementContext *ctx) = 0;

  virtual void enterAssert_property_statement(SV2012Parser::Assert_property_statementContext *ctx) = 0;
  virtual void exitAssert_property_statement(SV2012Parser::Assert_property_statementContext *ctx) = 0;

  virtual void enterAssume_property_statement(SV2012Parser::Assume_property_statementContext *ctx) = 0;
  virtual void exitAssume_property_statement(SV2012Parser::Assume_property_statementContext *ctx) = 0;

  virtual void enterCover_property_statement(SV2012Parser::Cover_property_statementContext *ctx) = 0;
  virtual void exitCover_property_statement(SV2012Parser::Cover_property_statementContext *ctx) = 0;

  virtual void enterExpect_property_statement(SV2012Parser::Expect_property_statementContext *ctx) = 0;
  virtual void exitExpect_property_statement(SV2012Parser::Expect_property_statementContext *ctx) = 0;

  virtual void enterCover_sequence_statement(SV2012Parser::Cover_sequence_statementContext *ctx) = 0;
  virtual void exitCover_sequence_statement(SV2012Parser::Cover_sequence_statementContext *ctx) = 0;

  virtual void enterRestrict_property_statement(SV2012Parser::Restrict_property_statementContext *ctx) = 0;
  virtual void exitRestrict_property_statement(SV2012Parser::Restrict_property_statementContext *ctx) = 0;

  virtual void enterProperty_instance(SV2012Parser::Property_instanceContext *ctx) = 0;
  virtual void exitProperty_instance(SV2012Parser::Property_instanceContext *ctx) = 0;

  virtual void enterProperty_list_of_arguments(SV2012Parser::Property_list_of_argumentsContext *ctx) = 0;
  virtual void exitProperty_list_of_arguments(SV2012Parser::Property_list_of_argumentsContext *ctx) = 0;

  virtual void enterProperty_actual_arg(SV2012Parser::Property_actual_argContext *ctx) = 0;
  virtual void exitProperty_actual_arg(SV2012Parser::Property_actual_argContext *ctx) = 0;

  virtual void enterAssertion_item_declaration(SV2012Parser::Assertion_item_declarationContext *ctx) = 0;
  virtual void exitAssertion_item_declaration(SV2012Parser::Assertion_item_declarationContext *ctx) = 0;

  virtual void enterProperty_declaration(SV2012Parser::Property_declarationContext *ctx) = 0;
  virtual void exitProperty_declaration(SV2012Parser::Property_declarationContext *ctx) = 0;

  virtual void enterProperty_port_list(SV2012Parser::Property_port_listContext *ctx) = 0;
  virtual void exitProperty_port_list(SV2012Parser::Property_port_listContext *ctx) = 0;

  virtual void enterProperty_port_item(SV2012Parser::Property_port_itemContext *ctx) = 0;
  virtual void exitProperty_port_item(SV2012Parser::Property_port_itemContext *ctx) = 0;

  virtual void enterProperty_lvar_port_direction(SV2012Parser::Property_lvar_port_directionContext *ctx) = 0;
  virtual void exitProperty_lvar_port_direction(SV2012Parser::Property_lvar_port_directionContext *ctx) = 0;

  virtual void enterProperty_formal_type(SV2012Parser::Property_formal_typeContext *ctx) = 0;
  virtual void exitProperty_formal_type(SV2012Parser::Property_formal_typeContext *ctx) = 0;

  virtual void enterProperty_spec(SV2012Parser::Property_specContext *ctx) = 0;
  virtual void exitProperty_spec(SV2012Parser::Property_specContext *ctx) = 0;

  virtual void enterProperty_expr(SV2012Parser::Property_exprContext *ctx) = 0;
  virtual void exitProperty_expr(SV2012Parser::Property_exprContext *ctx) = 0;

  virtual void enterProperty_case_item(SV2012Parser::Property_case_itemContext *ctx) = 0;
  virtual void exitProperty_case_item(SV2012Parser::Property_case_itemContext *ctx) = 0;

  virtual void enterSequence_declaration(SV2012Parser::Sequence_declarationContext *ctx) = 0;
  virtual void exitSequence_declaration(SV2012Parser::Sequence_declarationContext *ctx) = 0;

  virtual void enterSequence_port_list(SV2012Parser::Sequence_port_listContext *ctx) = 0;
  virtual void exitSequence_port_list(SV2012Parser::Sequence_port_listContext *ctx) = 0;

  virtual void enterSequence_port_item(SV2012Parser::Sequence_port_itemContext *ctx) = 0;
  virtual void exitSequence_port_item(SV2012Parser::Sequence_port_itemContext *ctx) = 0;

  virtual void enterSequence_lvar_port_direction(SV2012Parser::Sequence_lvar_port_directionContext *ctx) = 0;
  virtual void exitSequence_lvar_port_direction(SV2012Parser::Sequence_lvar_port_directionContext *ctx) = 0;

  virtual void enterSequence_formal_type(SV2012Parser::Sequence_formal_typeContext *ctx) = 0;
  virtual void exitSequence_formal_type(SV2012Parser::Sequence_formal_typeContext *ctx) = 0;

  virtual void enterSequence_expr(SV2012Parser::Sequence_exprContext *ctx) = 0;
  virtual void exitSequence_expr(SV2012Parser::Sequence_exprContext *ctx) = 0;

  virtual void enterCycle_delay_range(SV2012Parser::Cycle_delay_rangeContext *ctx) = 0;
  virtual void exitCycle_delay_range(SV2012Parser::Cycle_delay_rangeContext *ctx) = 0;

  virtual void enterSequence_method_call(SV2012Parser::Sequence_method_callContext *ctx) = 0;
  virtual void exitSequence_method_call(SV2012Parser::Sequence_method_callContext *ctx) = 0;

  virtual void enterSequence_match_item(SV2012Parser::Sequence_match_itemContext *ctx) = 0;
  virtual void exitSequence_match_item(SV2012Parser::Sequence_match_itemContext *ctx) = 0;

  virtual void enterSequence_instance(SV2012Parser::Sequence_instanceContext *ctx) = 0;
  virtual void exitSequence_instance(SV2012Parser::Sequence_instanceContext *ctx) = 0;

  virtual void enterSequence_list_of_arguments(SV2012Parser::Sequence_list_of_argumentsContext *ctx) = 0;
  virtual void exitSequence_list_of_arguments(SV2012Parser::Sequence_list_of_argumentsContext *ctx) = 0;

  virtual void enterSequence_actual_arg(SV2012Parser::Sequence_actual_argContext *ctx) = 0;
  virtual void exitSequence_actual_arg(SV2012Parser::Sequence_actual_argContext *ctx) = 0;

  virtual void enterBoolean_abbrev(SV2012Parser::Boolean_abbrevContext *ctx) = 0;
  virtual void exitBoolean_abbrev(SV2012Parser::Boolean_abbrevContext *ctx) = 0;

  virtual void enterSequence_abbrev(SV2012Parser::Sequence_abbrevContext *ctx) = 0;
  virtual void exitSequence_abbrev(SV2012Parser::Sequence_abbrevContext *ctx) = 0;

  virtual void enterConsecutive_repetition(SV2012Parser::Consecutive_repetitionContext *ctx) = 0;
  virtual void exitConsecutive_repetition(SV2012Parser::Consecutive_repetitionContext *ctx) = 0;

  virtual void enterNon_consecutive_repetition(SV2012Parser::Non_consecutive_repetitionContext *ctx) = 0;
  virtual void exitNon_consecutive_repetition(SV2012Parser::Non_consecutive_repetitionContext *ctx) = 0;

  virtual void enterGoto_repetition(SV2012Parser::Goto_repetitionContext *ctx) = 0;
  virtual void exitGoto_repetition(SV2012Parser::Goto_repetitionContext *ctx) = 0;

  virtual void enterConst_or_range_expression(SV2012Parser::Const_or_range_expressionContext *ctx) = 0;
  virtual void exitConst_or_range_expression(SV2012Parser::Const_or_range_expressionContext *ctx) = 0;

  virtual void enterCycle_delay_const_range_expression(SV2012Parser::Cycle_delay_const_range_expressionContext *ctx) = 0;
  virtual void exitCycle_delay_const_range_expression(SV2012Parser::Cycle_delay_const_range_expressionContext *ctx) = 0;

  virtual void enterExpression_or_dist(SV2012Parser::Expression_or_distContext *ctx) = 0;
  virtual void exitExpression_or_dist(SV2012Parser::Expression_or_distContext *ctx) = 0;

  virtual void enterAssertion_variable_declaration(SV2012Parser::Assertion_variable_declarationContext *ctx) = 0;
  virtual void exitAssertion_variable_declaration(SV2012Parser::Assertion_variable_declarationContext *ctx) = 0;

  virtual void enterLet_declaration(SV2012Parser::Let_declarationContext *ctx) = 0;
  virtual void exitLet_declaration(SV2012Parser::Let_declarationContext *ctx) = 0;

  virtual void enterLet_identifier(SV2012Parser::Let_identifierContext *ctx) = 0;
  virtual void exitLet_identifier(SV2012Parser::Let_identifierContext *ctx) = 0;

  virtual void enterLet_port_list(SV2012Parser::Let_port_listContext *ctx) = 0;
  virtual void exitLet_port_list(SV2012Parser::Let_port_listContext *ctx) = 0;

  virtual void enterLet_port_item(SV2012Parser::Let_port_itemContext *ctx) = 0;
  virtual void exitLet_port_item(SV2012Parser::Let_port_itemContext *ctx) = 0;

  virtual void enterLet_formal_type(SV2012Parser::Let_formal_typeContext *ctx) = 0;
  virtual void exitLet_formal_type(SV2012Parser::Let_formal_typeContext *ctx) = 0;

  virtual void enterLet_expression(SV2012Parser::Let_expressionContext *ctx) = 0;
  virtual void exitLet_expression(SV2012Parser::Let_expressionContext *ctx) = 0;

  virtual void enterLet_list_of_arguments(SV2012Parser::Let_list_of_argumentsContext *ctx) = 0;
  virtual void exitLet_list_of_arguments(SV2012Parser::Let_list_of_argumentsContext *ctx) = 0;

  virtual void enterLet_actual_arg(SV2012Parser::Let_actual_argContext *ctx) = 0;
  virtual void exitLet_actual_arg(SV2012Parser::Let_actual_argContext *ctx) = 0;

  virtual void enterCovergroup_declaration(SV2012Parser::Covergroup_declarationContext *ctx) = 0;
  virtual void exitCovergroup_declaration(SV2012Parser::Covergroup_declarationContext *ctx) = 0;

  virtual void enterCoverage_spec_or_option(SV2012Parser::Coverage_spec_or_optionContext *ctx) = 0;
  virtual void exitCoverage_spec_or_option(SV2012Parser::Coverage_spec_or_optionContext *ctx) = 0;

  virtual void enterCoverage_option(SV2012Parser::Coverage_optionContext *ctx) = 0;
  virtual void exitCoverage_option(SV2012Parser::Coverage_optionContext *ctx) = 0;

  virtual void enterCoverage_spec(SV2012Parser::Coverage_specContext *ctx) = 0;
  virtual void exitCoverage_spec(SV2012Parser::Coverage_specContext *ctx) = 0;

  virtual void enterCoverage_event(SV2012Parser::Coverage_eventContext *ctx) = 0;
  virtual void exitCoverage_event(SV2012Parser::Coverage_eventContext *ctx) = 0;

  virtual void enterBlock_event_expression(SV2012Parser::Block_event_expressionContext *ctx) = 0;
  virtual void exitBlock_event_expression(SV2012Parser::Block_event_expressionContext *ctx) = 0;

  virtual void enterHierarchical_btf_identifier(SV2012Parser::Hierarchical_btf_identifierContext *ctx) = 0;
  virtual void exitHierarchical_btf_identifier(SV2012Parser::Hierarchical_btf_identifierContext *ctx) = 0;

  virtual void enterCover_point(SV2012Parser::Cover_pointContext *ctx) = 0;
  virtual void exitCover_point(SV2012Parser::Cover_pointContext *ctx) = 0;

  virtual void enterBins_or_empty(SV2012Parser::Bins_or_emptyContext *ctx) = 0;
  virtual void exitBins_or_empty(SV2012Parser::Bins_or_emptyContext *ctx) = 0;

  virtual void enterBins_or_options(SV2012Parser::Bins_or_optionsContext *ctx) = 0;
  virtual void exitBins_or_options(SV2012Parser::Bins_or_optionsContext *ctx) = 0;

  virtual void enterBins_keyword(SV2012Parser::Bins_keywordContext *ctx) = 0;
  virtual void exitBins_keyword(SV2012Parser::Bins_keywordContext *ctx) = 0;

  virtual void enterTrans_list(SV2012Parser::Trans_listContext *ctx) = 0;
  virtual void exitTrans_list(SV2012Parser::Trans_listContext *ctx) = 0;

  virtual void enterTrans_set(SV2012Parser::Trans_setContext *ctx) = 0;
  virtual void exitTrans_set(SV2012Parser::Trans_setContext *ctx) = 0;

  virtual void enterTrans_range_list(SV2012Parser::Trans_range_listContext *ctx) = 0;
  virtual void exitTrans_range_list(SV2012Parser::Trans_range_listContext *ctx) = 0;

  virtual void enterTrans_item(SV2012Parser::Trans_itemContext *ctx) = 0;
  virtual void exitTrans_item(SV2012Parser::Trans_itemContext *ctx) = 0;

  virtual void enterRepeat_range(SV2012Parser::Repeat_rangeContext *ctx) = 0;
  virtual void exitRepeat_range(SV2012Parser::Repeat_rangeContext *ctx) = 0;

  virtual void enterCover_cross(SV2012Parser::Cover_crossContext *ctx) = 0;
  virtual void exitCover_cross(SV2012Parser::Cover_crossContext *ctx) = 0;

  virtual void enterList_of_cross_items(SV2012Parser::List_of_cross_itemsContext *ctx) = 0;
  virtual void exitList_of_cross_items(SV2012Parser::List_of_cross_itemsContext *ctx) = 0;

  virtual void enterCross_item(SV2012Parser::Cross_itemContext *ctx) = 0;
  virtual void exitCross_item(SV2012Parser::Cross_itemContext *ctx) = 0;

  virtual void enterCross_body(SV2012Parser::Cross_bodyContext *ctx) = 0;
  virtual void exitCross_body(SV2012Parser::Cross_bodyContext *ctx) = 0;

  virtual void enterCross_body_item(SV2012Parser::Cross_body_itemContext *ctx) = 0;
  virtual void exitCross_body_item(SV2012Parser::Cross_body_itemContext *ctx) = 0;

  virtual void enterBins_selection_or_option(SV2012Parser::Bins_selection_or_optionContext *ctx) = 0;
  virtual void exitBins_selection_or_option(SV2012Parser::Bins_selection_or_optionContext *ctx) = 0;

  virtual void enterBins_selection(SV2012Parser::Bins_selectionContext *ctx) = 0;
  virtual void exitBins_selection(SV2012Parser::Bins_selectionContext *ctx) = 0;

  virtual void enterSelect_expression(SV2012Parser::Select_expressionContext *ctx) = 0;
  virtual void exitSelect_expression(SV2012Parser::Select_expressionContext *ctx) = 0;

  virtual void enterSelect_condition(SV2012Parser::Select_conditionContext *ctx) = 0;
  virtual void exitSelect_condition(SV2012Parser::Select_conditionContext *ctx) = 0;

  virtual void enterBins_expression(SV2012Parser::Bins_expressionContext *ctx) = 0;
  virtual void exitBins_expression(SV2012Parser::Bins_expressionContext *ctx) = 0;

  virtual void enterCovergroup_range_list(SV2012Parser::Covergroup_range_listContext *ctx) = 0;
  virtual void exitCovergroup_range_list(SV2012Parser::Covergroup_range_listContext *ctx) = 0;

  virtual void enterCovergroup_value_range(SV2012Parser::Covergroup_value_rangeContext *ctx) = 0;
  virtual void exitCovergroup_value_range(SV2012Parser::Covergroup_value_rangeContext *ctx) = 0;

  virtual void enterWith_covergroup_expression(SV2012Parser::With_covergroup_expressionContext *ctx) = 0;
  virtual void exitWith_covergroup_expression(SV2012Parser::With_covergroup_expressionContext *ctx) = 0;

  virtual void enterSet_covergroup_expression(SV2012Parser::Set_covergroup_expressionContext *ctx) = 0;
  virtual void exitSet_covergroup_expression(SV2012Parser::Set_covergroup_expressionContext *ctx) = 0;

  virtual void enterInteger_covergroup_expression(SV2012Parser::Integer_covergroup_expressionContext *ctx) = 0;
  virtual void exitInteger_covergroup_expression(SV2012Parser::Integer_covergroup_expressionContext *ctx) = 0;

  virtual void enterCross_set_expression(SV2012Parser::Cross_set_expressionContext *ctx) = 0;
  virtual void exitCross_set_expression(SV2012Parser::Cross_set_expressionContext *ctx) = 0;

  virtual void enterCovergroup_expression(SV2012Parser::Covergroup_expressionContext *ctx) = 0;
  virtual void exitCovergroup_expression(SV2012Parser::Covergroup_expressionContext *ctx) = 0;

  virtual void enterGate_instantiation(SV2012Parser::Gate_instantiationContext *ctx) = 0;
  virtual void exitGate_instantiation(SV2012Parser::Gate_instantiationContext *ctx) = 0;

  virtual void enterCmos_switch_instance(SV2012Parser::Cmos_switch_instanceContext *ctx) = 0;
  virtual void exitCmos_switch_instance(SV2012Parser::Cmos_switch_instanceContext *ctx) = 0;

  virtual void enterEnable_gate_instance(SV2012Parser::Enable_gate_instanceContext *ctx) = 0;
  virtual void exitEnable_gate_instance(SV2012Parser::Enable_gate_instanceContext *ctx) = 0;

  virtual void enterMos_switch_instance(SV2012Parser::Mos_switch_instanceContext *ctx) = 0;
  virtual void exitMos_switch_instance(SV2012Parser::Mos_switch_instanceContext *ctx) = 0;

  virtual void enterN_input_gate_instance(SV2012Parser::N_input_gate_instanceContext *ctx) = 0;
  virtual void exitN_input_gate_instance(SV2012Parser::N_input_gate_instanceContext *ctx) = 0;

  virtual void enterN_output_gate_instance(SV2012Parser::N_output_gate_instanceContext *ctx) = 0;
  virtual void exitN_output_gate_instance(SV2012Parser::N_output_gate_instanceContext *ctx) = 0;

  virtual void enterPass_switch_instance(SV2012Parser::Pass_switch_instanceContext *ctx) = 0;
  virtual void exitPass_switch_instance(SV2012Parser::Pass_switch_instanceContext *ctx) = 0;

  virtual void enterPass_enable_switch_instance(SV2012Parser::Pass_enable_switch_instanceContext *ctx) = 0;
  virtual void exitPass_enable_switch_instance(SV2012Parser::Pass_enable_switch_instanceContext *ctx) = 0;

  virtual void enterPull_gate_instance(SV2012Parser::Pull_gate_instanceContext *ctx) = 0;
  virtual void exitPull_gate_instance(SV2012Parser::Pull_gate_instanceContext *ctx) = 0;

  virtual void enterPulldown_strength(SV2012Parser::Pulldown_strengthContext *ctx) = 0;
  virtual void exitPulldown_strength(SV2012Parser::Pulldown_strengthContext *ctx) = 0;

  virtual void enterPullup_strength(SV2012Parser::Pullup_strengthContext *ctx) = 0;
  virtual void exitPullup_strength(SV2012Parser::Pullup_strengthContext *ctx) = 0;

  virtual void enterEnable_terminal(SV2012Parser::Enable_terminalContext *ctx) = 0;
  virtual void exitEnable_terminal(SV2012Parser::Enable_terminalContext *ctx) = 0;

  virtual void enterInout_terminal(SV2012Parser::Inout_terminalContext *ctx) = 0;
  virtual void exitInout_terminal(SV2012Parser::Inout_terminalContext *ctx) = 0;

  virtual void enterInput_terminal(SV2012Parser::Input_terminalContext *ctx) = 0;
  virtual void exitInput_terminal(SV2012Parser::Input_terminalContext *ctx) = 0;

  virtual void enterNcontrol_terminal(SV2012Parser::Ncontrol_terminalContext *ctx) = 0;
  virtual void exitNcontrol_terminal(SV2012Parser::Ncontrol_terminalContext *ctx) = 0;

  virtual void enterOutput_terminal(SV2012Parser::Output_terminalContext *ctx) = 0;
  virtual void exitOutput_terminal(SV2012Parser::Output_terminalContext *ctx) = 0;

  virtual void enterPcontrol_terminal(SV2012Parser::Pcontrol_terminalContext *ctx) = 0;
  virtual void exitPcontrol_terminal(SV2012Parser::Pcontrol_terminalContext *ctx) = 0;

  virtual void enterCmos_switchtype(SV2012Parser::Cmos_switchtypeContext *ctx) = 0;
  virtual void exitCmos_switchtype(SV2012Parser::Cmos_switchtypeContext *ctx) = 0;

  virtual void enterEnable_gatetype(SV2012Parser::Enable_gatetypeContext *ctx) = 0;
  virtual void exitEnable_gatetype(SV2012Parser::Enable_gatetypeContext *ctx) = 0;

  virtual void enterMos_switchtype(SV2012Parser::Mos_switchtypeContext *ctx) = 0;
  virtual void exitMos_switchtype(SV2012Parser::Mos_switchtypeContext *ctx) = 0;

  virtual void enterN_input_gatetype(SV2012Parser::N_input_gatetypeContext *ctx) = 0;
  virtual void exitN_input_gatetype(SV2012Parser::N_input_gatetypeContext *ctx) = 0;

  virtual void enterN_output_gatetype(SV2012Parser::N_output_gatetypeContext *ctx) = 0;
  virtual void exitN_output_gatetype(SV2012Parser::N_output_gatetypeContext *ctx) = 0;

  virtual void enterPass_en_switchtype(SV2012Parser::Pass_en_switchtypeContext *ctx) = 0;
  virtual void exitPass_en_switchtype(SV2012Parser::Pass_en_switchtypeContext *ctx) = 0;

  virtual void enterPass_switchtype(SV2012Parser::Pass_switchtypeContext *ctx) = 0;
  virtual void exitPass_switchtype(SV2012Parser::Pass_switchtypeContext *ctx) = 0;

  virtual void enterModule_instantiation(SV2012Parser::Module_instantiationContext *ctx) = 0;
  virtual void exitModule_instantiation(SV2012Parser::Module_instantiationContext *ctx) = 0;

  virtual void enterParameter_value_assignment(SV2012Parser::Parameter_value_assignmentContext *ctx) = 0;
  virtual void exitParameter_value_assignment(SV2012Parser::Parameter_value_assignmentContext *ctx) = 0;

  virtual void enterList_of_parameter_assignments(SV2012Parser::List_of_parameter_assignmentsContext *ctx) = 0;
  virtual void exitList_of_parameter_assignments(SV2012Parser::List_of_parameter_assignmentsContext *ctx) = 0;

  virtual void enterOrdered_parameter_assignment(SV2012Parser::Ordered_parameter_assignmentContext *ctx) = 0;
  virtual void exitOrdered_parameter_assignment(SV2012Parser::Ordered_parameter_assignmentContext *ctx) = 0;

  virtual void enterNamed_parameter_assignment(SV2012Parser::Named_parameter_assignmentContext *ctx) = 0;
  virtual void exitNamed_parameter_assignment(SV2012Parser::Named_parameter_assignmentContext *ctx) = 0;

  virtual void enterHierarchical_instance(SV2012Parser::Hierarchical_instanceContext *ctx) = 0;
  virtual void exitHierarchical_instance(SV2012Parser::Hierarchical_instanceContext *ctx) = 0;

  virtual void enterName_of_instance(SV2012Parser::Name_of_instanceContext *ctx) = 0;
  virtual void exitName_of_instance(SV2012Parser::Name_of_instanceContext *ctx) = 0;

  virtual void enterList_of_port_connections(SV2012Parser::List_of_port_connectionsContext *ctx) = 0;
  virtual void exitList_of_port_connections(SV2012Parser::List_of_port_connectionsContext *ctx) = 0;

  virtual void enterOrdered_port_connection(SV2012Parser::Ordered_port_connectionContext *ctx) = 0;
  virtual void exitOrdered_port_connection(SV2012Parser::Ordered_port_connectionContext *ctx) = 0;

  virtual void enterNamed_port_connection(SV2012Parser::Named_port_connectionContext *ctx) = 0;
  virtual void exitNamed_port_connection(SV2012Parser::Named_port_connectionContext *ctx) = 0;

  virtual void enterInterface_instantiation(SV2012Parser::Interface_instantiationContext *ctx) = 0;
  virtual void exitInterface_instantiation(SV2012Parser::Interface_instantiationContext *ctx) = 0;

  virtual void enterProgram_instantiation(SV2012Parser::Program_instantiationContext *ctx) = 0;
  virtual void exitProgram_instantiation(SV2012Parser::Program_instantiationContext *ctx) = 0;

  virtual void enterChecker_instantiation(SV2012Parser::Checker_instantiationContext *ctx) = 0;
  virtual void exitChecker_instantiation(SV2012Parser::Checker_instantiationContext *ctx) = 0;

  virtual void enterList_of_checker_port_connections(SV2012Parser::List_of_checker_port_connectionsContext *ctx) = 0;
  virtual void exitList_of_checker_port_connections(SV2012Parser::List_of_checker_port_connectionsContext *ctx) = 0;

  virtual void enterOrdered_checker_port_connection(SV2012Parser::Ordered_checker_port_connectionContext *ctx) = 0;
  virtual void exitOrdered_checker_port_connection(SV2012Parser::Ordered_checker_port_connectionContext *ctx) = 0;

  virtual void enterNamed_checker_port_connection(SV2012Parser::Named_checker_port_connectionContext *ctx) = 0;
  virtual void exitNamed_checker_port_connection(SV2012Parser::Named_checker_port_connectionContext *ctx) = 0;

  virtual void enterGenerate_region(SV2012Parser::Generate_regionContext *ctx) = 0;
  virtual void exitGenerate_region(SV2012Parser::Generate_regionContext *ctx) = 0;

  virtual void enterLoop_generate_construct(SV2012Parser::Loop_generate_constructContext *ctx) = 0;
  virtual void exitLoop_generate_construct(SV2012Parser::Loop_generate_constructContext *ctx) = 0;

  virtual void enterGenvar_initialization(SV2012Parser::Genvar_initializationContext *ctx) = 0;
  virtual void exitGenvar_initialization(SV2012Parser::Genvar_initializationContext *ctx) = 0;

  virtual void enterGenvar_iteration(SV2012Parser::Genvar_iterationContext *ctx) = 0;
  virtual void exitGenvar_iteration(SV2012Parser::Genvar_iterationContext *ctx) = 0;

  virtual void enterConditional_generate_construct(SV2012Parser::Conditional_generate_constructContext *ctx) = 0;
  virtual void exitConditional_generate_construct(SV2012Parser::Conditional_generate_constructContext *ctx) = 0;

  virtual void enterIf_generate_construct(SV2012Parser::If_generate_constructContext *ctx) = 0;
  virtual void exitIf_generate_construct(SV2012Parser::If_generate_constructContext *ctx) = 0;

  virtual void enterCase_generate_construct(SV2012Parser::Case_generate_constructContext *ctx) = 0;
  virtual void exitCase_generate_construct(SV2012Parser::Case_generate_constructContext *ctx) = 0;

  virtual void enterCase_generate_item(SV2012Parser::Case_generate_itemContext *ctx) = 0;
  virtual void exitCase_generate_item(SV2012Parser::Case_generate_itemContext *ctx) = 0;

  virtual void enterGenerate_block(SV2012Parser::Generate_blockContext *ctx) = 0;
  virtual void exitGenerate_block(SV2012Parser::Generate_blockContext *ctx) = 0;

  virtual void enterGenerate_item(SV2012Parser::Generate_itemContext *ctx) = 0;
  virtual void exitGenerate_item(SV2012Parser::Generate_itemContext *ctx) = 0;

  virtual void enterUdp_nonansi_declaration(SV2012Parser::Udp_nonansi_declarationContext *ctx) = 0;
  virtual void exitUdp_nonansi_declaration(SV2012Parser::Udp_nonansi_declarationContext *ctx) = 0;

  virtual void enterUdp_ansi_declaration(SV2012Parser::Udp_ansi_declarationContext *ctx) = 0;
  virtual void exitUdp_ansi_declaration(SV2012Parser::Udp_ansi_declarationContext *ctx) = 0;

  virtual void enterUdp_declaration(SV2012Parser::Udp_declarationContext *ctx) = 0;
  virtual void exitUdp_declaration(SV2012Parser::Udp_declarationContext *ctx) = 0;

  virtual void enterUdp_port_list(SV2012Parser::Udp_port_listContext *ctx) = 0;
  virtual void exitUdp_port_list(SV2012Parser::Udp_port_listContext *ctx) = 0;

  virtual void enterUdp_declaration_port_list(SV2012Parser::Udp_declaration_port_listContext *ctx) = 0;
  virtual void exitUdp_declaration_port_list(SV2012Parser::Udp_declaration_port_listContext *ctx) = 0;

  virtual void enterUdp_port_declaration(SV2012Parser::Udp_port_declarationContext *ctx) = 0;
  virtual void exitUdp_port_declaration(SV2012Parser::Udp_port_declarationContext *ctx) = 0;

  virtual void enterUdp_output_declaration(SV2012Parser::Udp_output_declarationContext *ctx) = 0;
  virtual void exitUdp_output_declaration(SV2012Parser::Udp_output_declarationContext *ctx) = 0;

  virtual void enterUdp_input_declaration(SV2012Parser::Udp_input_declarationContext *ctx) = 0;
  virtual void exitUdp_input_declaration(SV2012Parser::Udp_input_declarationContext *ctx) = 0;

  virtual void enterUdp_reg_declaration(SV2012Parser::Udp_reg_declarationContext *ctx) = 0;
  virtual void exitUdp_reg_declaration(SV2012Parser::Udp_reg_declarationContext *ctx) = 0;

  virtual void enterUdp_body(SV2012Parser::Udp_bodyContext *ctx) = 0;
  virtual void exitUdp_body(SV2012Parser::Udp_bodyContext *ctx) = 0;

  virtual void enterCombinational_body(SV2012Parser::Combinational_bodyContext *ctx) = 0;
  virtual void exitCombinational_body(SV2012Parser::Combinational_bodyContext *ctx) = 0;

  virtual void enterCombinational_entry(SV2012Parser::Combinational_entryContext *ctx) = 0;
  virtual void exitCombinational_entry(SV2012Parser::Combinational_entryContext *ctx) = 0;

  virtual void enterSequential_body(SV2012Parser::Sequential_bodyContext *ctx) = 0;
  virtual void exitSequential_body(SV2012Parser::Sequential_bodyContext *ctx) = 0;

  virtual void enterUdp_initial_statement(SV2012Parser::Udp_initial_statementContext *ctx) = 0;
  virtual void exitUdp_initial_statement(SV2012Parser::Udp_initial_statementContext *ctx) = 0;

  virtual void enterInit_val(SV2012Parser::Init_valContext *ctx) = 0;
  virtual void exitInit_val(SV2012Parser::Init_valContext *ctx) = 0;

  virtual void enterSequential_entry(SV2012Parser::Sequential_entryContext *ctx) = 0;
  virtual void exitSequential_entry(SV2012Parser::Sequential_entryContext *ctx) = 0;

  virtual void enterSeq_input_list(SV2012Parser::Seq_input_listContext *ctx) = 0;
  virtual void exitSeq_input_list(SV2012Parser::Seq_input_listContext *ctx) = 0;

  virtual void enterLevel_input_list(SV2012Parser::Level_input_listContext *ctx) = 0;
  virtual void exitLevel_input_list(SV2012Parser::Level_input_listContext *ctx) = 0;

  virtual void enterEdge_input_list(SV2012Parser::Edge_input_listContext *ctx) = 0;
  virtual void exitEdge_input_list(SV2012Parser::Edge_input_listContext *ctx) = 0;

  virtual void enterEdge_indicator(SV2012Parser::Edge_indicatorContext *ctx) = 0;
  virtual void exitEdge_indicator(SV2012Parser::Edge_indicatorContext *ctx) = 0;

  virtual void enterCurrent_state(SV2012Parser::Current_stateContext *ctx) = 0;
  virtual void exitCurrent_state(SV2012Parser::Current_stateContext *ctx) = 0;

  virtual void enterNext_state(SV2012Parser::Next_stateContext *ctx) = 0;
  virtual void exitNext_state(SV2012Parser::Next_stateContext *ctx) = 0;

  virtual void enterOutput_symbol(SV2012Parser::Output_symbolContext *ctx) = 0;
  virtual void exitOutput_symbol(SV2012Parser::Output_symbolContext *ctx) = 0;

  virtual void enterLevel_symbol(SV2012Parser::Level_symbolContext *ctx) = 0;
  virtual void exitLevel_symbol(SV2012Parser::Level_symbolContext *ctx) = 0;

  virtual void enterEdge_symbol(SV2012Parser::Edge_symbolContext *ctx) = 0;
  virtual void exitEdge_symbol(SV2012Parser::Edge_symbolContext *ctx) = 0;

  virtual void enterUdp_instantiation(SV2012Parser::Udp_instantiationContext *ctx) = 0;
  virtual void exitUdp_instantiation(SV2012Parser::Udp_instantiationContext *ctx) = 0;

  virtual void enterUdp_instance(SV2012Parser::Udp_instanceContext *ctx) = 0;
  virtual void exitUdp_instance(SV2012Parser::Udp_instanceContext *ctx) = 0;

  virtual void enterContinuous_assign(SV2012Parser::Continuous_assignContext *ctx) = 0;
  virtual void exitContinuous_assign(SV2012Parser::Continuous_assignContext *ctx) = 0;

  virtual void enterList_of_net_assignments(SV2012Parser::List_of_net_assignmentsContext *ctx) = 0;
  virtual void exitList_of_net_assignments(SV2012Parser::List_of_net_assignmentsContext *ctx) = 0;

  virtual void enterList_of_variable_assignments(SV2012Parser::List_of_variable_assignmentsContext *ctx) = 0;
  virtual void exitList_of_variable_assignments(SV2012Parser::List_of_variable_assignmentsContext *ctx) = 0;

  virtual void enterNet_alias(SV2012Parser::Net_aliasContext *ctx) = 0;
  virtual void exitNet_alias(SV2012Parser::Net_aliasContext *ctx) = 0;

  virtual void enterNet_assignment(SV2012Parser::Net_assignmentContext *ctx) = 0;
  virtual void exitNet_assignment(SV2012Parser::Net_assignmentContext *ctx) = 0;

  virtual void enterInitial_construct(SV2012Parser::Initial_constructContext *ctx) = 0;
  virtual void exitInitial_construct(SV2012Parser::Initial_constructContext *ctx) = 0;

  virtual void enterAlways_construct(SV2012Parser::Always_constructContext *ctx) = 0;
  virtual void exitAlways_construct(SV2012Parser::Always_constructContext *ctx) = 0;

  virtual void enterAlways_keyword(SV2012Parser::Always_keywordContext *ctx) = 0;
  virtual void exitAlways_keyword(SV2012Parser::Always_keywordContext *ctx) = 0;

  virtual void enterFinal_construct(SV2012Parser::Final_constructContext *ctx) = 0;
  virtual void exitFinal_construct(SV2012Parser::Final_constructContext *ctx) = 0;

  virtual void enterBlocking_assignment(SV2012Parser::Blocking_assignmentContext *ctx) = 0;
  virtual void exitBlocking_assignment(SV2012Parser::Blocking_assignmentContext *ctx) = 0;

  virtual void enterOperator_assignment(SV2012Parser::Operator_assignmentContext *ctx) = 0;
  virtual void exitOperator_assignment(SV2012Parser::Operator_assignmentContext *ctx) = 0;

  virtual void enterAssignment_operator(SV2012Parser::Assignment_operatorContext *ctx) = 0;
  virtual void exitAssignment_operator(SV2012Parser::Assignment_operatorContext *ctx) = 0;

  virtual void enterNonblocking_assignment(SV2012Parser::Nonblocking_assignmentContext *ctx) = 0;
  virtual void exitNonblocking_assignment(SV2012Parser::Nonblocking_assignmentContext *ctx) = 0;

  virtual void enterProcedural_continuous_assignment(SV2012Parser::Procedural_continuous_assignmentContext *ctx) = 0;
  virtual void exitProcedural_continuous_assignment(SV2012Parser::Procedural_continuous_assignmentContext *ctx) = 0;

  virtual void enterVariable_assignment(SV2012Parser::Variable_assignmentContext *ctx) = 0;
  virtual void exitVariable_assignment(SV2012Parser::Variable_assignmentContext *ctx) = 0;

  virtual void enterAction_block(SV2012Parser::Action_blockContext *ctx) = 0;
  virtual void exitAction_block(SV2012Parser::Action_blockContext *ctx) = 0;

  virtual void enterSeq_block(SV2012Parser::Seq_blockContext *ctx) = 0;
  virtual void exitSeq_block(SV2012Parser::Seq_blockContext *ctx) = 0;

  virtual void enterPar_block(SV2012Parser::Par_blockContext *ctx) = 0;
  virtual void exitPar_block(SV2012Parser::Par_blockContext *ctx) = 0;

  virtual void enterJoin_keyword(SV2012Parser::Join_keywordContext *ctx) = 0;
  virtual void exitJoin_keyword(SV2012Parser::Join_keywordContext *ctx) = 0;

  virtual void enterStatement_or_null(SV2012Parser::Statement_or_nullContext *ctx) = 0;
  virtual void exitStatement_or_null(SV2012Parser::Statement_or_nullContext *ctx) = 0;

  virtual void enterStatement(SV2012Parser::StatementContext *ctx) = 0;
  virtual void exitStatement(SV2012Parser::StatementContext *ctx) = 0;

  virtual void enterStatement_item(SV2012Parser::Statement_itemContext *ctx) = 0;
  virtual void exitStatement_item(SV2012Parser::Statement_itemContext *ctx) = 0;

  virtual void enterFunction_statement(SV2012Parser::Function_statementContext *ctx) = 0;
  virtual void exitFunction_statement(SV2012Parser::Function_statementContext *ctx) = 0;

  virtual void enterFunction_statement_or_null(SV2012Parser::Function_statement_or_nullContext *ctx) = 0;
  virtual void exitFunction_statement_or_null(SV2012Parser::Function_statement_or_nullContext *ctx) = 0;

  virtual void enterVariable_identifier_list(SV2012Parser::Variable_identifier_listContext *ctx) = 0;
  virtual void exitVariable_identifier_list(SV2012Parser::Variable_identifier_listContext *ctx) = 0;

  virtual void enterProcedural_timing_control_statement(SV2012Parser::Procedural_timing_control_statementContext *ctx) = 0;
  virtual void exitProcedural_timing_control_statement(SV2012Parser::Procedural_timing_control_statementContext *ctx) = 0;

  virtual void enterDelay_or_event_control(SV2012Parser::Delay_or_event_controlContext *ctx) = 0;
  virtual void exitDelay_or_event_control(SV2012Parser::Delay_or_event_controlContext *ctx) = 0;

  virtual void enterDelay_control(SV2012Parser::Delay_controlContext *ctx) = 0;
  virtual void exitDelay_control(SV2012Parser::Delay_controlContext *ctx) = 0;

  virtual void enterEvent_control(SV2012Parser::Event_controlContext *ctx) = 0;
  virtual void exitEvent_control(SV2012Parser::Event_controlContext *ctx) = 0;

  virtual void enterEvent_expression(SV2012Parser::Event_expressionContext *ctx) = 0;
  virtual void exitEvent_expression(SV2012Parser::Event_expressionContext *ctx) = 0;

  virtual void enterProcedural_timing_control(SV2012Parser::Procedural_timing_controlContext *ctx) = 0;
  virtual void exitProcedural_timing_control(SV2012Parser::Procedural_timing_controlContext *ctx) = 0;

  virtual void enterJump_statement(SV2012Parser::Jump_statementContext *ctx) = 0;
  virtual void exitJump_statement(SV2012Parser::Jump_statementContext *ctx) = 0;

  virtual void enterWait_statement(SV2012Parser::Wait_statementContext *ctx) = 0;
  virtual void exitWait_statement(SV2012Parser::Wait_statementContext *ctx) = 0;

  virtual void enterEvent_trigger(SV2012Parser::Event_triggerContext *ctx) = 0;
  virtual void exitEvent_trigger(SV2012Parser::Event_triggerContext *ctx) = 0;

  virtual void enterDisable_statement(SV2012Parser::Disable_statementContext *ctx) = 0;
  virtual void exitDisable_statement(SV2012Parser::Disable_statementContext *ctx) = 0;

  virtual void enterConditional_statement(SV2012Parser::Conditional_statementContext *ctx) = 0;
  virtual void exitConditional_statement(SV2012Parser::Conditional_statementContext *ctx) = 0;

  virtual void enterUnique_priority(SV2012Parser::Unique_priorityContext *ctx) = 0;
  virtual void exitUnique_priority(SV2012Parser::Unique_priorityContext *ctx) = 0;

  virtual void enterCond_predicate(SV2012Parser::Cond_predicateContext *ctx) = 0;
  virtual void exitCond_predicate(SV2012Parser::Cond_predicateContext *ctx) = 0;

  virtual void enterExpression_or_cond_pattern(SV2012Parser::Expression_or_cond_patternContext *ctx) = 0;
  virtual void exitExpression_or_cond_pattern(SV2012Parser::Expression_or_cond_patternContext *ctx) = 0;

  virtual void enterCond_pattern(SV2012Parser::Cond_patternContext *ctx) = 0;
  virtual void exitCond_pattern(SV2012Parser::Cond_patternContext *ctx) = 0;

  virtual void enterCase_statement(SV2012Parser::Case_statementContext *ctx) = 0;
  virtual void exitCase_statement(SV2012Parser::Case_statementContext *ctx) = 0;

  virtual void enterCase_keyword(SV2012Parser::Case_keywordContext *ctx) = 0;
  virtual void exitCase_keyword(SV2012Parser::Case_keywordContext *ctx) = 0;

  virtual void enterCase_expression(SV2012Parser::Case_expressionContext *ctx) = 0;
  virtual void exitCase_expression(SV2012Parser::Case_expressionContext *ctx) = 0;

  virtual void enterCase_item(SV2012Parser::Case_itemContext *ctx) = 0;
  virtual void exitCase_item(SV2012Parser::Case_itemContext *ctx) = 0;

  virtual void enterCase_pattern_item(SV2012Parser::Case_pattern_itemContext *ctx) = 0;
  virtual void exitCase_pattern_item(SV2012Parser::Case_pattern_itemContext *ctx) = 0;

  virtual void enterCase_inside_item(SV2012Parser::Case_inside_itemContext *ctx) = 0;
  virtual void exitCase_inside_item(SV2012Parser::Case_inside_itemContext *ctx) = 0;

  virtual void enterCase_item_expression(SV2012Parser::Case_item_expressionContext *ctx) = 0;
  virtual void exitCase_item_expression(SV2012Parser::Case_item_expressionContext *ctx) = 0;

  virtual void enterRandcase_statement(SV2012Parser::Randcase_statementContext *ctx) = 0;
  virtual void exitRandcase_statement(SV2012Parser::Randcase_statementContext *ctx) = 0;

  virtual void enterRandcase_item(SV2012Parser::Randcase_itemContext *ctx) = 0;
  virtual void exitRandcase_item(SV2012Parser::Randcase_itemContext *ctx) = 0;

  virtual void enterOpen_range_list(SV2012Parser::Open_range_listContext *ctx) = 0;
  virtual void exitOpen_range_list(SV2012Parser::Open_range_listContext *ctx) = 0;

  virtual void enterOpen_value_range(SV2012Parser::Open_value_rangeContext *ctx) = 0;
  virtual void exitOpen_value_range(SV2012Parser::Open_value_rangeContext *ctx) = 0;

  virtual void enterPattern(SV2012Parser::PatternContext *ctx) = 0;
  virtual void exitPattern(SV2012Parser::PatternContext *ctx) = 0;

  virtual void enterAssignment_pattern(SV2012Parser::Assignment_patternContext *ctx) = 0;
  virtual void exitAssignment_pattern(SV2012Parser::Assignment_patternContext *ctx) = 0;

  virtual void enterStructure_pattern_key(SV2012Parser::Structure_pattern_keyContext *ctx) = 0;
  virtual void exitStructure_pattern_key(SV2012Parser::Structure_pattern_keyContext *ctx) = 0;

  virtual void enterArray_pattern_key(SV2012Parser::Array_pattern_keyContext *ctx) = 0;
  virtual void exitArray_pattern_key(SV2012Parser::Array_pattern_keyContext *ctx) = 0;

  virtual void enterAssignment_pattern_key(SV2012Parser::Assignment_pattern_keyContext *ctx) = 0;
  virtual void exitAssignment_pattern_key(SV2012Parser::Assignment_pattern_keyContext *ctx) = 0;

  virtual void enterAssignment_pattern_expression(SV2012Parser::Assignment_pattern_expressionContext *ctx) = 0;
  virtual void exitAssignment_pattern_expression(SV2012Parser::Assignment_pattern_expressionContext *ctx) = 0;

  virtual void enterAssignment_pattern_expression_type(SV2012Parser::Assignment_pattern_expression_typeContext *ctx) = 0;
  virtual void exitAssignment_pattern_expression_type(SV2012Parser::Assignment_pattern_expression_typeContext *ctx) = 0;

  virtual void enterConstant_assignment_pattern_expression(SV2012Parser::Constant_assignment_pattern_expressionContext *ctx) = 0;
  virtual void exitConstant_assignment_pattern_expression(SV2012Parser::Constant_assignment_pattern_expressionContext *ctx) = 0;

  virtual void enterAssignment_pattern_net_lvalue(SV2012Parser::Assignment_pattern_net_lvalueContext *ctx) = 0;
  virtual void exitAssignment_pattern_net_lvalue(SV2012Parser::Assignment_pattern_net_lvalueContext *ctx) = 0;

  virtual void enterAssignment_pattern_variable_lvalue(SV2012Parser::Assignment_pattern_variable_lvalueContext *ctx) = 0;
  virtual void exitAssignment_pattern_variable_lvalue(SV2012Parser::Assignment_pattern_variable_lvalueContext *ctx) = 0;

  virtual void enterLoop_statement(SV2012Parser::Loop_statementContext *ctx) = 0;
  virtual void exitLoop_statement(SV2012Parser::Loop_statementContext *ctx) = 0;

  virtual void enterFor_initialization(SV2012Parser::For_initializationContext *ctx) = 0;
  virtual void exitFor_initialization(SV2012Parser::For_initializationContext *ctx) = 0;

  virtual void enterFor_variable_declaration(SV2012Parser::For_variable_declarationContext *ctx) = 0;
  virtual void exitFor_variable_declaration(SV2012Parser::For_variable_declarationContext *ctx) = 0;

  virtual void enterFor_step(SV2012Parser::For_stepContext *ctx) = 0;
  virtual void exitFor_step(SV2012Parser::For_stepContext *ctx) = 0;

  virtual void enterFor_step_assignment(SV2012Parser::For_step_assignmentContext *ctx) = 0;
  virtual void exitFor_step_assignment(SV2012Parser::For_step_assignmentContext *ctx) = 0;

  virtual void enterLoop_variables(SV2012Parser::Loop_variablesContext *ctx) = 0;
  virtual void exitLoop_variables(SV2012Parser::Loop_variablesContext *ctx) = 0;

  virtual void enterSubroutine_call_statement(SV2012Parser::Subroutine_call_statementContext *ctx) = 0;
  virtual void exitSubroutine_call_statement(SV2012Parser::Subroutine_call_statementContext *ctx) = 0;

  virtual void enterAssertion_item(SV2012Parser::Assertion_itemContext *ctx) = 0;
  virtual void exitAssertion_item(SV2012Parser::Assertion_itemContext *ctx) = 0;

  virtual void enterDeferred_immediate_assertion_item(SV2012Parser::Deferred_immediate_assertion_itemContext *ctx) = 0;
  virtual void exitDeferred_immediate_assertion_item(SV2012Parser::Deferred_immediate_assertion_itemContext *ctx) = 0;

  virtual void enterProcedural_assertion_statement(SV2012Parser::Procedural_assertion_statementContext *ctx) = 0;
  virtual void exitProcedural_assertion_statement(SV2012Parser::Procedural_assertion_statementContext *ctx) = 0;

  virtual void enterImmediate_assertion_statement(SV2012Parser::Immediate_assertion_statementContext *ctx) = 0;
  virtual void exitImmediate_assertion_statement(SV2012Parser::Immediate_assertion_statementContext *ctx) = 0;

  virtual void enterSimple_immediate_assertion_statement(SV2012Parser::Simple_immediate_assertion_statementContext *ctx) = 0;
  virtual void exitSimple_immediate_assertion_statement(SV2012Parser::Simple_immediate_assertion_statementContext *ctx) = 0;

  virtual void enterSimple_immediate_assert_statement(SV2012Parser::Simple_immediate_assert_statementContext *ctx) = 0;
  virtual void exitSimple_immediate_assert_statement(SV2012Parser::Simple_immediate_assert_statementContext *ctx) = 0;

  virtual void enterSimple_immediate_assume_statement(SV2012Parser::Simple_immediate_assume_statementContext *ctx) = 0;
  virtual void exitSimple_immediate_assume_statement(SV2012Parser::Simple_immediate_assume_statementContext *ctx) = 0;

  virtual void enterSimple_immediate_cover_statement(SV2012Parser::Simple_immediate_cover_statementContext *ctx) = 0;
  virtual void exitSimple_immediate_cover_statement(SV2012Parser::Simple_immediate_cover_statementContext *ctx) = 0;

  virtual void enterDeferred_immediate_assertion_statement(SV2012Parser::Deferred_immediate_assertion_statementContext *ctx) = 0;
  virtual void exitDeferred_immediate_assertion_statement(SV2012Parser::Deferred_immediate_assertion_statementContext *ctx) = 0;

  virtual void enterDeferred_immediate_assert_statement(SV2012Parser::Deferred_immediate_assert_statementContext *ctx) = 0;
  virtual void exitDeferred_immediate_assert_statement(SV2012Parser::Deferred_immediate_assert_statementContext *ctx) = 0;

  virtual void enterDeferred_immediate_assume_statement(SV2012Parser::Deferred_immediate_assume_statementContext *ctx) = 0;
  virtual void exitDeferred_immediate_assume_statement(SV2012Parser::Deferred_immediate_assume_statementContext *ctx) = 0;

  virtual void enterDeferred_immediate_cover_statement(SV2012Parser::Deferred_immediate_cover_statementContext *ctx) = 0;
  virtual void exitDeferred_immediate_cover_statement(SV2012Parser::Deferred_immediate_cover_statementContext *ctx) = 0;

  virtual void enterClocking_declaration(SV2012Parser::Clocking_declarationContext *ctx) = 0;
  virtual void exitClocking_declaration(SV2012Parser::Clocking_declarationContext *ctx) = 0;

  virtual void enterClocking_event(SV2012Parser::Clocking_eventContext *ctx) = 0;
  virtual void exitClocking_event(SV2012Parser::Clocking_eventContext *ctx) = 0;

  virtual void enterClocking_item(SV2012Parser::Clocking_itemContext *ctx) = 0;
  virtual void exitClocking_item(SV2012Parser::Clocking_itemContext *ctx) = 0;

  virtual void enterDefault_skew(SV2012Parser::Default_skewContext *ctx) = 0;
  virtual void exitDefault_skew(SV2012Parser::Default_skewContext *ctx) = 0;

  virtual void enterClocking_direction(SV2012Parser::Clocking_directionContext *ctx) = 0;
  virtual void exitClocking_direction(SV2012Parser::Clocking_directionContext *ctx) = 0;

  virtual void enterList_of_clocking_decl_assign(SV2012Parser::List_of_clocking_decl_assignContext *ctx) = 0;
  virtual void exitList_of_clocking_decl_assign(SV2012Parser::List_of_clocking_decl_assignContext *ctx) = 0;

  virtual void enterClocking_decl_assign(SV2012Parser::Clocking_decl_assignContext *ctx) = 0;
  virtual void exitClocking_decl_assign(SV2012Parser::Clocking_decl_assignContext *ctx) = 0;

  virtual void enterClocking_skew(SV2012Parser::Clocking_skewContext *ctx) = 0;
  virtual void exitClocking_skew(SV2012Parser::Clocking_skewContext *ctx) = 0;

  virtual void enterClocking_drive(SV2012Parser::Clocking_driveContext *ctx) = 0;
  virtual void exitClocking_drive(SV2012Parser::Clocking_driveContext *ctx) = 0;

  virtual void enterCycle_delay(SV2012Parser::Cycle_delayContext *ctx) = 0;
  virtual void exitCycle_delay(SV2012Parser::Cycle_delayContext *ctx) = 0;

  virtual void enterClockvar(SV2012Parser::ClockvarContext *ctx) = 0;
  virtual void exitClockvar(SV2012Parser::ClockvarContext *ctx) = 0;

  virtual void enterClockvar_expression(SV2012Parser::Clockvar_expressionContext *ctx) = 0;
  virtual void exitClockvar_expression(SV2012Parser::Clockvar_expressionContext *ctx) = 0;

  virtual void enterRandsequence_statement(SV2012Parser::Randsequence_statementContext *ctx) = 0;
  virtual void exitRandsequence_statement(SV2012Parser::Randsequence_statementContext *ctx) = 0;

  virtual void enterProduction(SV2012Parser::ProductionContext *ctx) = 0;
  virtual void exitProduction(SV2012Parser::ProductionContext *ctx) = 0;

  virtual void enterRs_rule(SV2012Parser::Rs_ruleContext *ctx) = 0;
  virtual void exitRs_rule(SV2012Parser::Rs_ruleContext *ctx) = 0;

  virtual void enterRs_production_list(SV2012Parser::Rs_production_listContext *ctx) = 0;
  virtual void exitRs_production_list(SV2012Parser::Rs_production_listContext *ctx) = 0;

  virtual void enterWeight_specification(SV2012Parser::Weight_specificationContext *ctx) = 0;
  virtual void exitWeight_specification(SV2012Parser::Weight_specificationContext *ctx) = 0;

  virtual void enterRs_code_block(SV2012Parser::Rs_code_blockContext *ctx) = 0;
  virtual void exitRs_code_block(SV2012Parser::Rs_code_blockContext *ctx) = 0;

  virtual void enterRs_prod(SV2012Parser::Rs_prodContext *ctx) = 0;
  virtual void exitRs_prod(SV2012Parser::Rs_prodContext *ctx) = 0;

  virtual void enterProduction_item(SV2012Parser::Production_itemContext *ctx) = 0;
  virtual void exitProduction_item(SV2012Parser::Production_itemContext *ctx) = 0;

  virtual void enterRs_if_else(SV2012Parser::Rs_if_elseContext *ctx) = 0;
  virtual void exitRs_if_else(SV2012Parser::Rs_if_elseContext *ctx) = 0;

  virtual void enterRs_repeat(SV2012Parser::Rs_repeatContext *ctx) = 0;
  virtual void exitRs_repeat(SV2012Parser::Rs_repeatContext *ctx) = 0;

  virtual void enterRs_case(SV2012Parser::Rs_caseContext *ctx) = 0;
  virtual void exitRs_case(SV2012Parser::Rs_caseContext *ctx) = 0;

  virtual void enterRs_case_item(SV2012Parser::Rs_case_itemContext *ctx) = 0;
  virtual void exitRs_case_item(SV2012Parser::Rs_case_itemContext *ctx) = 0;

  virtual void enterSpecify_block(SV2012Parser::Specify_blockContext *ctx) = 0;
  virtual void exitSpecify_block(SV2012Parser::Specify_blockContext *ctx) = 0;

  virtual void enterSpecify_item(SV2012Parser::Specify_itemContext *ctx) = 0;
  virtual void exitSpecify_item(SV2012Parser::Specify_itemContext *ctx) = 0;

  virtual void enterPulsestyle_declaration(SV2012Parser::Pulsestyle_declarationContext *ctx) = 0;
  virtual void exitPulsestyle_declaration(SV2012Parser::Pulsestyle_declarationContext *ctx) = 0;

  virtual void enterShowcancelled_declaration(SV2012Parser::Showcancelled_declarationContext *ctx) = 0;
  virtual void exitShowcancelled_declaration(SV2012Parser::Showcancelled_declarationContext *ctx) = 0;

  virtual void enterPath_declaration(SV2012Parser::Path_declarationContext *ctx) = 0;
  virtual void exitPath_declaration(SV2012Parser::Path_declarationContext *ctx) = 0;

  virtual void enterSimple_path_declaration(SV2012Parser::Simple_path_declarationContext *ctx) = 0;
  virtual void exitSimple_path_declaration(SV2012Parser::Simple_path_declarationContext *ctx) = 0;

  virtual void enterParallel_path_description(SV2012Parser::Parallel_path_descriptionContext *ctx) = 0;
  virtual void exitParallel_path_description(SV2012Parser::Parallel_path_descriptionContext *ctx) = 0;

  virtual void enterFull_path_description(SV2012Parser::Full_path_descriptionContext *ctx) = 0;
  virtual void exitFull_path_description(SV2012Parser::Full_path_descriptionContext *ctx) = 0;

  virtual void enterList_of_path_inputs(SV2012Parser::List_of_path_inputsContext *ctx) = 0;
  virtual void exitList_of_path_inputs(SV2012Parser::List_of_path_inputsContext *ctx) = 0;

  virtual void enterList_of_path_outputs(SV2012Parser::List_of_path_outputsContext *ctx) = 0;
  virtual void exitList_of_path_outputs(SV2012Parser::List_of_path_outputsContext *ctx) = 0;

  virtual void enterSpecify_input_terminal_descriptor(SV2012Parser::Specify_input_terminal_descriptorContext *ctx) = 0;
  virtual void exitSpecify_input_terminal_descriptor(SV2012Parser::Specify_input_terminal_descriptorContext *ctx) = 0;

  virtual void enterSpecify_output_terminal_descriptor(SV2012Parser::Specify_output_terminal_descriptorContext *ctx) = 0;
  virtual void exitSpecify_output_terminal_descriptor(SV2012Parser::Specify_output_terminal_descriptorContext *ctx) = 0;

  virtual void enterInput_identifier(SV2012Parser::Input_identifierContext *ctx) = 0;
  virtual void exitInput_identifier(SV2012Parser::Input_identifierContext *ctx) = 0;

  virtual void enterOutput_identifier(SV2012Parser::Output_identifierContext *ctx) = 0;
  virtual void exitOutput_identifier(SV2012Parser::Output_identifierContext *ctx) = 0;

  virtual void enterPath_delay_value(SV2012Parser::Path_delay_valueContext *ctx) = 0;
  virtual void exitPath_delay_value(SV2012Parser::Path_delay_valueContext *ctx) = 0;

  virtual void enterList_of_path_delay_expressions(SV2012Parser::List_of_path_delay_expressionsContext *ctx) = 0;
  virtual void exitList_of_path_delay_expressions(SV2012Parser::List_of_path_delay_expressionsContext *ctx) = 0;

  virtual void enterT_path_delay_expression(SV2012Parser::T_path_delay_expressionContext *ctx) = 0;
  virtual void exitT_path_delay_expression(SV2012Parser::T_path_delay_expressionContext *ctx) = 0;

  virtual void enterTrise_path_delay_expression(SV2012Parser::Trise_path_delay_expressionContext *ctx) = 0;
  virtual void exitTrise_path_delay_expression(SV2012Parser::Trise_path_delay_expressionContext *ctx) = 0;

  virtual void enterTfall_path_delay_expression(SV2012Parser::Tfall_path_delay_expressionContext *ctx) = 0;
  virtual void exitTfall_path_delay_expression(SV2012Parser::Tfall_path_delay_expressionContext *ctx) = 0;

  virtual void enterTz_path_delay_expression(SV2012Parser::Tz_path_delay_expressionContext *ctx) = 0;
  virtual void exitTz_path_delay_expression(SV2012Parser::Tz_path_delay_expressionContext *ctx) = 0;

  virtual void enterT01_path_delay_expression(SV2012Parser::T01_path_delay_expressionContext *ctx) = 0;
  virtual void exitT01_path_delay_expression(SV2012Parser::T01_path_delay_expressionContext *ctx) = 0;

  virtual void enterT10_path_delay_expression(SV2012Parser::T10_path_delay_expressionContext *ctx) = 0;
  virtual void exitT10_path_delay_expression(SV2012Parser::T10_path_delay_expressionContext *ctx) = 0;

  virtual void enterT0z_path_delay_expression(SV2012Parser::T0z_path_delay_expressionContext *ctx) = 0;
  virtual void exitT0z_path_delay_expression(SV2012Parser::T0z_path_delay_expressionContext *ctx) = 0;

  virtual void enterTz1_path_delay_expression(SV2012Parser::Tz1_path_delay_expressionContext *ctx) = 0;
  virtual void exitTz1_path_delay_expression(SV2012Parser::Tz1_path_delay_expressionContext *ctx) = 0;

  virtual void enterT1z_path_delay_expression(SV2012Parser::T1z_path_delay_expressionContext *ctx) = 0;
  virtual void exitT1z_path_delay_expression(SV2012Parser::T1z_path_delay_expressionContext *ctx) = 0;

  virtual void enterTz0_path_delay_expression(SV2012Parser::Tz0_path_delay_expressionContext *ctx) = 0;
  virtual void exitTz0_path_delay_expression(SV2012Parser::Tz0_path_delay_expressionContext *ctx) = 0;

  virtual void enterT0x_path_delay_expression(SV2012Parser::T0x_path_delay_expressionContext *ctx) = 0;
  virtual void exitT0x_path_delay_expression(SV2012Parser::T0x_path_delay_expressionContext *ctx) = 0;

  virtual void enterTx1_path_delay_expression(SV2012Parser::Tx1_path_delay_expressionContext *ctx) = 0;
  virtual void exitTx1_path_delay_expression(SV2012Parser::Tx1_path_delay_expressionContext *ctx) = 0;

  virtual void enterT1x_path_delay_expression(SV2012Parser::T1x_path_delay_expressionContext *ctx) = 0;
  virtual void exitT1x_path_delay_expression(SV2012Parser::T1x_path_delay_expressionContext *ctx) = 0;

  virtual void enterTx0_path_delay_expression(SV2012Parser::Tx0_path_delay_expressionContext *ctx) = 0;
  virtual void exitTx0_path_delay_expression(SV2012Parser::Tx0_path_delay_expressionContext *ctx) = 0;

  virtual void enterTxz_path_delay_expression(SV2012Parser::Txz_path_delay_expressionContext *ctx) = 0;
  virtual void exitTxz_path_delay_expression(SV2012Parser::Txz_path_delay_expressionContext *ctx) = 0;

  virtual void enterTzx_path_delay_expression(SV2012Parser::Tzx_path_delay_expressionContext *ctx) = 0;
  virtual void exitTzx_path_delay_expression(SV2012Parser::Tzx_path_delay_expressionContext *ctx) = 0;

  virtual void enterPath_delay_expression(SV2012Parser::Path_delay_expressionContext *ctx) = 0;
  virtual void exitPath_delay_expression(SV2012Parser::Path_delay_expressionContext *ctx) = 0;

  virtual void enterEdge_sensitive_path_declaration(SV2012Parser::Edge_sensitive_path_declarationContext *ctx) = 0;
  virtual void exitEdge_sensitive_path_declaration(SV2012Parser::Edge_sensitive_path_declarationContext *ctx) = 0;

  virtual void enterParallel_edge_sensitive_path_description(SV2012Parser::Parallel_edge_sensitive_path_descriptionContext *ctx) = 0;
  virtual void exitParallel_edge_sensitive_path_description(SV2012Parser::Parallel_edge_sensitive_path_descriptionContext *ctx) = 0;

  virtual void enterFull_edge_sensitive_path_description(SV2012Parser::Full_edge_sensitive_path_descriptionContext *ctx) = 0;
  virtual void exitFull_edge_sensitive_path_description(SV2012Parser::Full_edge_sensitive_path_descriptionContext *ctx) = 0;

  virtual void enterData_source_expression(SV2012Parser::Data_source_expressionContext *ctx) = 0;
  virtual void exitData_source_expression(SV2012Parser::Data_source_expressionContext *ctx) = 0;

  virtual void enterEdge_identifier(SV2012Parser::Edge_identifierContext *ctx) = 0;
  virtual void exitEdge_identifier(SV2012Parser::Edge_identifierContext *ctx) = 0;

  virtual void enterState_dependent_path_declaration(SV2012Parser::State_dependent_path_declarationContext *ctx) = 0;
  virtual void exitState_dependent_path_declaration(SV2012Parser::State_dependent_path_declarationContext *ctx) = 0;

  virtual void enterPolarity_operator(SV2012Parser::Polarity_operatorContext *ctx) = 0;
  virtual void exitPolarity_operator(SV2012Parser::Polarity_operatorContext *ctx) = 0;

  virtual void enterSystem_timing_check(SV2012Parser::System_timing_checkContext *ctx) = 0;
  virtual void exitSystem_timing_check(SV2012Parser::System_timing_checkContext *ctx) = 0;

  virtual void enterSetup_timing_check(SV2012Parser::Setup_timing_checkContext *ctx) = 0;
  virtual void exitSetup_timing_check(SV2012Parser::Setup_timing_checkContext *ctx) = 0;

  virtual void enterHold_timing_check(SV2012Parser::Hold_timing_checkContext *ctx) = 0;
  virtual void exitHold_timing_check(SV2012Parser::Hold_timing_checkContext *ctx) = 0;

  virtual void enterSetuphold_timing_check(SV2012Parser::Setuphold_timing_checkContext *ctx) = 0;
  virtual void exitSetuphold_timing_check(SV2012Parser::Setuphold_timing_checkContext *ctx) = 0;

  virtual void enterRecovery_timing_check(SV2012Parser::Recovery_timing_checkContext *ctx) = 0;
  virtual void exitRecovery_timing_check(SV2012Parser::Recovery_timing_checkContext *ctx) = 0;

  virtual void enterRemoval_timing_check(SV2012Parser::Removal_timing_checkContext *ctx) = 0;
  virtual void exitRemoval_timing_check(SV2012Parser::Removal_timing_checkContext *ctx) = 0;

  virtual void enterRecrem_timing_check(SV2012Parser::Recrem_timing_checkContext *ctx) = 0;
  virtual void exitRecrem_timing_check(SV2012Parser::Recrem_timing_checkContext *ctx) = 0;

  virtual void enterSkew_timing_check(SV2012Parser::Skew_timing_checkContext *ctx) = 0;
  virtual void exitSkew_timing_check(SV2012Parser::Skew_timing_checkContext *ctx) = 0;

  virtual void enterTimeskew_timing_check(SV2012Parser::Timeskew_timing_checkContext *ctx) = 0;
  virtual void exitTimeskew_timing_check(SV2012Parser::Timeskew_timing_checkContext *ctx) = 0;

  virtual void enterFullskew_timing_check(SV2012Parser::Fullskew_timing_checkContext *ctx) = 0;
  virtual void exitFullskew_timing_check(SV2012Parser::Fullskew_timing_checkContext *ctx) = 0;

  virtual void enterPeriod_timing_check(SV2012Parser::Period_timing_checkContext *ctx) = 0;
  virtual void exitPeriod_timing_check(SV2012Parser::Period_timing_checkContext *ctx) = 0;

  virtual void enterWidth_timing_check(SV2012Parser::Width_timing_checkContext *ctx) = 0;
  virtual void exitWidth_timing_check(SV2012Parser::Width_timing_checkContext *ctx) = 0;

  virtual void enterNochange_timing_check(SV2012Parser::Nochange_timing_checkContext *ctx) = 0;
  virtual void exitNochange_timing_check(SV2012Parser::Nochange_timing_checkContext *ctx) = 0;

  virtual void enterTimecheck_condition(SV2012Parser::Timecheck_conditionContext *ctx) = 0;
  virtual void exitTimecheck_condition(SV2012Parser::Timecheck_conditionContext *ctx) = 0;

  virtual void enterControlled_reference_event(SV2012Parser::Controlled_reference_eventContext *ctx) = 0;
  virtual void exitControlled_reference_event(SV2012Parser::Controlled_reference_eventContext *ctx) = 0;

  virtual void enterData_event(SV2012Parser::Data_eventContext *ctx) = 0;
  virtual void exitData_event(SV2012Parser::Data_eventContext *ctx) = 0;

  virtual void enterDelayed_data(SV2012Parser::Delayed_dataContext *ctx) = 0;
  virtual void exitDelayed_data(SV2012Parser::Delayed_dataContext *ctx) = 0;

  virtual void enterDelayed_reference(SV2012Parser::Delayed_referenceContext *ctx) = 0;
  virtual void exitDelayed_reference(SV2012Parser::Delayed_referenceContext *ctx) = 0;

  virtual void enterEnd_edge_offset(SV2012Parser::End_edge_offsetContext *ctx) = 0;
  virtual void exitEnd_edge_offset(SV2012Parser::End_edge_offsetContext *ctx) = 0;

  virtual void enterEvent_based_flag(SV2012Parser::Event_based_flagContext *ctx) = 0;
  virtual void exitEvent_based_flag(SV2012Parser::Event_based_flagContext *ctx) = 0;

  virtual void enterNotifier(SV2012Parser::NotifierContext *ctx) = 0;
  virtual void exitNotifier(SV2012Parser::NotifierContext *ctx) = 0;

  virtual void enterReference_event(SV2012Parser::Reference_eventContext *ctx) = 0;
  virtual void exitReference_event(SV2012Parser::Reference_eventContext *ctx) = 0;

  virtual void enterRemain_active_flag(SV2012Parser::Remain_active_flagContext *ctx) = 0;
  virtual void exitRemain_active_flag(SV2012Parser::Remain_active_flagContext *ctx) = 0;

  virtual void enterTimestamp_condition(SV2012Parser::Timestamp_conditionContext *ctx) = 0;
  virtual void exitTimestamp_condition(SV2012Parser::Timestamp_conditionContext *ctx) = 0;

  virtual void enterStart_edge_offset(SV2012Parser::Start_edge_offsetContext *ctx) = 0;
  virtual void exitStart_edge_offset(SV2012Parser::Start_edge_offsetContext *ctx) = 0;

  virtual void enterThreshold(SV2012Parser::ThresholdContext *ctx) = 0;
  virtual void exitThreshold(SV2012Parser::ThresholdContext *ctx) = 0;

  virtual void enterTiming_check_limit(SV2012Parser::Timing_check_limitContext *ctx) = 0;
  virtual void exitTiming_check_limit(SV2012Parser::Timing_check_limitContext *ctx) = 0;

  virtual void enterTiming_check_event(SV2012Parser::Timing_check_eventContext *ctx) = 0;
  virtual void exitTiming_check_event(SV2012Parser::Timing_check_eventContext *ctx) = 0;

  virtual void enterControlled_timing_check_event(SV2012Parser::Controlled_timing_check_eventContext *ctx) = 0;
  virtual void exitControlled_timing_check_event(SV2012Parser::Controlled_timing_check_eventContext *ctx) = 0;

  virtual void enterTiming_check_event_control(SV2012Parser::Timing_check_event_controlContext *ctx) = 0;
  virtual void exitTiming_check_event_control(SV2012Parser::Timing_check_event_controlContext *ctx) = 0;

  virtual void enterSpecify_terminal_descriptor(SV2012Parser::Specify_terminal_descriptorContext *ctx) = 0;
  virtual void exitSpecify_terminal_descriptor(SV2012Parser::Specify_terminal_descriptorContext *ctx) = 0;

  virtual void enterEdge_control_specifier(SV2012Parser::Edge_control_specifierContext *ctx) = 0;
  virtual void exitEdge_control_specifier(SV2012Parser::Edge_control_specifierContext *ctx) = 0;

  virtual void enterEdge_descriptor(SV2012Parser::Edge_descriptorContext *ctx) = 0;
  virtual void exitEdge_descriptor(SV2012Parser::Edge_descriptorContext *ctx) = 0;

  virtual void enterTiming_check_condition(SV2012Parser::Timing_check_conditionContext *ctx) = 0;
  virtual void exitTiming_check_condition(SV2012Parser::Timing_check_conditionContext *ctx) = 0;

  virtual void enterScalar_timing_check_condition(SV2012Parser::Scalar_timing_check_conditionContext *ctx) = 0;
  virtual void exitScalar_timing_check_condition(SV2012Parser::Scalar_timing_check_conditionContext *ctx) = 0;

  virtual void enterScalar_constant(SV2012Parser::Scalar_constantContext *ctx) = 0;
  virtual void exitScalar_constant(SV2012Parser::Scalar_constantContext *ctx) = 0;

  virtual void enterConcatenation(SV2012Parser::ConcatenationContext *ctx) = 0;
  virtual void exitConcatenation(SV2012Parser::ConcatenationContext *ctx) = 0;

  virtual void enterConstant_concatenation(SV2012Parser::Constant_concatenationContext *ctx) = 0;
  virtual void exitConstant_concatenation(SV2012Parser::Constant_concatenationContext *ctx) = 0;

  virtual void enterConstant_multiple_concatenation(SV2012Parser::Constant_multiple_concatenationContext *ctx) = 0;
  virtual void exitConstant_multiple_concatenation(SV2012Parser::Constant_multiple_concatenationContext *ctx) = 0;

  virtual void enterModule_path_concatenation(SV2012Parser::Module_path_concatenationContext *ctx) = 0;
  virtual void exitModule_path_concatenation(SV2012Parser::Module_path_concatenationContext *ctx) = 0;

  virtual void enterModule_path_multiple_concatenation(SV2012Parser::Module_path_multiple_concatenationContext *ctx) = 0;
  virtual void exitModule_path_multiple_concatenation(SV2012Parser::Module_path_multiple_concatenationContext *ctx) = 0;

  virtual void enterMultiple_concatenation(SV2012Parser::Multiple_concatenationContext *ctx) = 0;
  virtual void exitMultiple_concatenation(SV2012Parser::Multiple_concatenationContext *ctx) = 0;

  virtual void enterStreaming_concatenation(SV2012Parser::Streaming_concatenationContext *ctx) = 0;
  virtual void exitStreaming_concatenation(SV2012Parser::Streaming_concatenationContext *ctx) = 0;

  virtual void enterStream_operator(SV2012Parser::Stream_operatorContext *ctx) = 0;
  virtual void exitStream_operator(SV2012Parser::Stream_operatorContext *ctx) = 0;

  virtual void enterSlice_size(SV2012Parser::Slice_sizeContext *ctx) = 0;
  virtual void exitSlice_size(SV2012Parser::Slice_sizeContext *ctx) = 0;

  virtual void enterStream_concatenation(SV2012Parser::Stream_concatenationContext *ctx) = 0;
  virtual void exitStream_concatenation(SV2012Parser::Stream_concatenationContext *ctx) = 0;

  virtual void enterStream_expression(SV2012Parser::Stream_expressionContext *ctx) = 0;
  virtual void exitStream_expression(SV2012Parser::Stream_expressionContext *ctx) = 0;

  virtual void enterArray_range_expression(SV2012Parser::Array_range_expressionContext *ctx) = 0;
  virtual void exitArray_range_expression(SV2012Parser::Array_range_expressionContext *ctx) = 0;

  virtual void enterEmpty_queue(SV2012Parser::Empty_queueContext *ctx) = 0;
  virtual void exitEmpty_queue(SV2012Parser::Empty_queueContext *ctx) = 0;

  virtual void enterConstant_function_call(SV2012Parser::Constant_function_callContext *ctx) = 0;
  virtual void exitConstant_function_call(SV2012Parser::Constant_function_callContext *ctx) = 0;

  virtual void enterTf_call(SV2012Parser::Tf_callContext *ctx) = 0;
  virtual void exitTf_call(SV2012Parser::Tf_callContext *ctx) = 0;

  virtual void enterSystem_tf_call(SV2012Parser::System_tf_callContext *ctx) = 0;
  virtual void exitSystem_tf_call(SV2012Parser::System_tf_callContext *ctx) = 0;

  virtual void enterFunction_subroutine_call(SV2012Parser::Function_subroutine_callContext *ctx) = 0;
  virtual void exitFunction_subroutine_call(SV2012Parser::Function_subroutine_callContext *ctx) = 0;

  virtual void enterSubroutine_call(SV2012Parser::Subroutine_callContext *ctx) = 0;
  virtual void exitSubroutine_call(SV2012Parser::Subroutine_callContext *ctx) = 0;

  virtual void enterMethod_call(SV2012Parser::Method_callContext *ctx) = 0;
  virtual void exitMethod_call(SV2012Parser::Method_callContext *ctx) = 0;

  virtual void enterMethod_call_root(SV2012Parser::Method_call_rootContext *ctx) = 0;
  virtual void exitMethod_call_root(SV2012Parser::Method_call_rootContext *ctx) = 0;

  virtual void enterPositional_expression_argument(SV2012Parser::Positional_expression_argumentContext *ctx) = 0;
  virtual void exitPositional_expression_argument(SV2012Parser::Positional_expression_argumentContext *ctx) = 0;

  virtual void enterPositional_tagged_expression_argument(SV2012Parser::Positional_tagged_expression_argumentContext *ctx) = 0;
  virtual void exitPositional_tagged_expression_argument(SV2012Parser::Positional_tagged_expression_argumentContext *ctx) = 0;

  virtual void enterList_of_arguments(SV2012Parser::List_of_argumentsContext *ctx) = 0;
  virtual void exitList_of_arguments(SV2012Parser::List_of_argumentsContext *ctx) = 0;

  virtual void enterMethod_call_body(SV2012Parser::Method_call_bodyContext *ctx) = 0;
  virtual void exitMethod_call_body(SV2012Parser::Method_call_bodyContext *ctx) = 0;

  virtual void enterBuilt_in_method_call(SV2012Parser::Built_in_method_callContext *ctx) = 0;
  virtual void exitBuilt_in_method_call(SV2012Parser::Built_in_method_callContext *ctx) = 0;

  virtual void enterArray_manipulation_call(SV2012Parser::Array_manipulation_callContext *ctx) = 0;
  virtual void exitArray_manipulation_call(SV2012Parser::Array_manipulation_callContext *ctx) = 0;

  virtual void enterRandomize_call(SV2012Parser::Randomize_callContext *ctx) = 0;
  virtual void exitRandomize_call(SV2012Parser::Randomize_callContext *ctx) = 0;

  virtual void enterArray_method_name(SV2012Parser::Array_method_nameContext *ctx) = 0;
  virtual void exitArray_method_name(SV2012Parser::Array_method_nameContext *ctx) = 0;

  virtual void enterInc_or_dec_expression(SV2012Parser::Inc_or_dec_expressionContext *ctx) = 0;
  virtual void exitInc_or_dec_expression(SV2012Parser::Inc_or_dec_expressionContext *ctx) = 0;

  virtual void enterConditional_expression(SV2012Parser::Conditional_expressionContext *ctx) = 0;
  virtual void exitConditional_expression(SV2012Parser::Conditional_expressionContext *ctx) = 0;

  virtual void enterConstant_expression(SV2012Parser::Constant_expressionContext *ctx) = 0;
  virtual void exitConstant_expression(SV2012Parser::Constant_expressionContext *ctx) = 0;

  virtual void enterConstant_mintypmax_expression(SV2012Parser::Constant_mintypmax_expressionContext *ctx) = 0;
  virtual void exitConstant_mintypmax_expression(SV2012Parser::Constant_mintypmax_expressionContext *ctx) = 0;

  virtual void enterConstant_param_expression(SV2012Parser::Constant_param_expressionContext *ctx) = 0;
  virtual void exitConstant_param_expression(SV2012Parser::Constant_param_expressionContext *ctx) = 0;

  virtual void enterParam_expression(SV2012Parser::Param_expressionContext *ctx) = 0;
  virtual void exitParam_expression(SV2012Parser::Param_expressionContext *ctx) = 0;

  virtual void enterConstant_range_expression(SV2012Parser::Constant_range_expressionContext *ctx) = 0;
  virtual void exitConstant_range_expression(SV2012Parser::Constant_range_expressionContext *ctx) = 0;

  virtual void enterConstant_part_select_range(SV2012Parser::Constant_part_select_rangeContext *ctx) = 0;
  virtual void exitConstant_part_select_range(SV2012Parser::Constant_part_select_rangeContext *ctx) = 0;

  virtual void enterConstant_range(SV2012Parser::Constant_rangeContext *ctx) = 0;
  virtual void exitConstant_range(SV2012Parser::Constant_rangeContext *ctx) = 0;

  virtual void enterConstant_indexed_range(SV2012Parser::Constant_indexed_rangeContext *ctx) = 0;
  virtual void exitConstant_indexed_range(SV2012Parser::Constant_indexed_rangeContext *ctx) = 0;

  virtual void enterExpression(SV2012Parser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SV2012Parser::ExpressionContext *ctx) = 0;

  virtual void enterTagged_union_expression(SV2012Parser::Tagged_union_expressionContext *ctx) = 0;
  virtual void exitTagged_union_expression(SV2012Parser::Tagged_union_expressionContext *ctx) = 0;

  virtual void enterInside_expression(SV2012Parser::Inside_expressionContext *ctx) = 0;
  virtual void exitInside_expression(SV2012Parser::Inside_expressionContext *ctx) = 0;

  virtual void enterValue_range(SV2012Parser::Value_rangeContext *ctx) = 0;
  virtual void exitValue_range(SV2012Parser::Value_rangeContext *ctx) = 0;

  virtual void enterMintypmax_expression(SV2012Parser::Mintypmax_expressionContext *ctx) = 0;
  virtual void exitMintypmax_expression(SV2012Parser::Mintypmax_expressionContext *ctx) = 0;

  virtual void enterModule_path_conditional_expression(SV2012Parser::Module_path_conditional_expressionContext *ctx) = 0;
  virtual void exitModule_path_conditional_expression(SV2012Parser::Module_path_conditional_expressionContext *ctx) = 0;

  virtual void enterModule_path_expression(SV2012Parser::Module_path_expressionContext *ctx) = 0;
  virtual void exitModule_path_expression(SV2012Parser::Module_path_expressionContext *ctx) = 0;

  virtual void enterModule_path_mintypmax_expression(SV2012Parser::Module_path_mintypmax_expressionContext *ctx) = 0;
  virtual void exitModule_path_mintypmax_expression(SV2012Parser::Module_path_mintypmax_expressionContext *ctx) = 0;

  virtual void enterPart_select_range(SV2012Parser::Part_select_rangeContext *ctx) = 0;
  virtual void exitPart_select_range(SV2012Parser::Part_select_rangeContext *ctx) = 0;

  virtual void enterIndexed_range(SV2012Parser::Indexed_rangeContext *ctx) = 0;
  virtual void exitIndexed_range(SV2012Parser::Indexed_rangeContext *ctx) = 0;

  virtual void enterGenvar_expression(SV2012Parser::Genvar_expressionContext *ctx) = 0;
  virtual void exitGenvar_expression(SV2012Parser::Genvar_expressionContext *ctx) = 0;

  virtual void enterConstant_primary(SV2012Parser::Constant_primaryContext *ctx) = 0;
  virtual void exitConstant_primary(SV2012Parser::Constant_primaryContext *ctx) = 0;

  virtual void enterModule_path_primary(SV2012Parser::Module_path_primaryContext *ctx) = 0;
  virtual void exitModule_path_primary(SV2012Parser::Module_path_primaryContext *ctx) = 0;

  virtual void enterPrimary(SV2012Parser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(SV2012Parser::PrimaryContext *ctx) = 0;

  virtual void enterClass_qualifier(SV2012Parser::Class_qualifierContext *ctx) = 0;
  virtual void exitClass_qualifier(SV2012Parser::Class_qualifierContext *ctx) = 0;

  virtual void enterRange_expression(SV2012Parser::Range_expressionContext *ctx) = 0;
  virtual void exitRange_expression(SV2012Parser::Range_expressionContext *ctx) = 0;

  virtual void enterPrimary_literal(SV2012Parser::Primary_literalContext *ctx) = 0;
  virtual void exitPrimary_literal(SV2012Parser::Primary_literalContext *ctx) = 0;

  virtual void enterTime_literal(SV2012Parser::Time_literalContext *ctx) = 0;
  virtual void exitTime_literal(SV2012Parser::Time_literalContext *ctx) = 0;

  virtual void enterTime_unit(SV2012Parser::Time_unitContext *ctx) = 0;
  virtual void exitTime_unit(SV2012Parser::Time_unitContext *ctx) = 0;

  virtual void enterImplicit_class_handle(SV2012Parser::Implicit_class_handleContext *ctx) = 0;
  virtual void exitImplicit_class_handle(SV2012Parser::Implicit_class_handleContext *ctx) = 0;

  virtual void enterBit_select(SV2012Parser::Bit_selectContext *ctx) = 0;
  virtual void exitBit_select(SV2012Parser::Bit_selectContext *ctx) = 0;

  virtual void enterSelect(SV2012Parser::SelectContext *ctx) = 0;
  virtual void exitSelect(SV2012Parser::SelectContext *ctx) = 0;

  virtual void enterNonrange_select(SV2012Parser::Nonrange_selectContext *ctx) = 0;
  virtual void exitNonrange_select(SV2012Parser::Nonrange_selectContext *ctx) = 0;

  virtual void enterConstant_bit_select(SV2012Parser::Constant_bit_selectContext *ctx) = 0;
  virtual void exitConstant_bit_select(SV2012Parser::Constant_bit_selectContext *ctx) = 0;

  virtual void enterConstant_select(SV2012Parser::Constant_selectContext *ctx) = 0;
  virtual void exitConstant_select(SV2012Parser::Constant_selectContext *ctx) = 0;

  virtual void enterConstant_cast(SV2012Parser::Constant_castContext *ctx) = 0;
  virtual void exitConstant_cast(SV2012Parser::Constant_castContext *ctx) = 0;

  virtual void enterConstant_let_expression(SV2012Parser::Constant_let_expressionContext *ctx) = 0;
  virtual void exitConstant_let_expression(SV2012Parser::Constant_let_expressionContext *ctx) = 0;

  virtual void enterCast(SV2012Parser::CastContext *ctx) = 0;
  virtual void exitCast(SV2012Parser::CastContext *ctx) = 0;

  virtual void enterNet_lvalue(SV2012Parser::Net_lvalueContext *ctx) = 0;
  virtual void exitNet_lvalue(SV2012Parser::Net_lvalueContext *ctx) = 0;

  virtual void enterVariable_lvalue(SV2012Parser::Variable_lvalueContext *ctx) = 0;
  virtual void exitVariable_lvalue(SV2012Parser::Variable_lvalueContext *ctx) = 0;

  virtual void enterNonrange_variable_lvalue(SV2012Parser::Nonrange_variable_lvalueContext *ctx) = 0;
  virtual void exitNonrange_variable_lvalue(SV2012Parser::Nonrange_variable_lvalueContext *ctx) = 0;

  virtual void enterUnary_operator(SV2012Parser::Unary_operatorContext *ctx) = 0;
  virtual void exitUnary_operator(SV2012Parser::Unary_operatorContext *ctx) = 0;

  virtual void enterBinary_operator(SV2012Parser::Binary_operatorContext *ctx) = 0;
  virtual void exitBinary_operator(SV2012Parser::Binary_operatorContext *ctx) = 0;

  virtual void enterInc_or_dec_operator(SV2012Parser::Inc_or_dec_operatorContext *ctx) = 0;
  virtual void exitInc_or_dec_operator(SV2012Parser::Inc_or_dec_operatorContext *ctx) = 0;

  virtual void enterUnary_module_path_operator(SV2012Parser::Unary_module_path_operatorContext *ctx) = 0;
  virtual void exitUnary_module_path_operator(SV2012Parser::Unary_module_path_operatorContext *ctx) = 0;

  virtual void enterBinary_module_path_operator(SV2012Parser::Binary_module_path_operatorContext *ctx) = 0;
  virtual void exitBinary_module_path_operator(SV2012Parser::Binary_module_path_operatorContext *ctx) = 0;

  virtual void enterNumber(SV2012Parser::NumberContext *ctx) = 0;
  virtual void exitNumber(SV2012Parser::NumberContext *ctx) = 0;

  virtual void enterAttribute_instance(SV2012Parser::Attribute_instanceContext *ctx) = 0;
  virtual void exitAttribute_instance(SV2012Parser::Attribute_instanceContext *ctx) = 0;

  virtual void enterAttr_spec(SV2012Parser::Attr_specContext *ctx) = 0;
  virtual void exitAttr_spec(SV2012Parser::Attr_specContext *ctx) = 0;

  virtual void enterAttr_name(SV2012Parser::Attr_nameContext *ctx) = 0;
  virtual void exitAttr_name(SV2012Parser::Attr_nameContext *ctx) = 0;

  virtual void enterArray_identifier(SV2012Parser::Array_identifierContext *ctx) = 0;
  virtual void exitArray_identifier(SV2012Parser::Array_identifierContext *ctx) = 0;

  virtual void enterBlock_identifier(SV2012Parser::Block_identifierContext *ctx) = 0;
  virtual void exitBlock_identifier(SV2012Parser::Block_identifierContext *ctx) = 0;

  virtual void enterBin_identifier(SV2012Parser::Bin_identifierContext *ctx) = 0;
  virtual void exitBin_identifier(SV2012Parser::Bin_identifierContext *ctx) = 0;

  virtual void enterC_identifier(SV2012Parser::C_identifierContext *ctx) = 0;
  virtual void exitC_identifier(SV2012Parser::C_identifierContext *ctx) = 0;

  virtual void enterCell_identifier(SV2012Parser::Cell_identifierContext *ctx) = 0;
  virtual void exitCell_identifier(SV2012Parser::Cell_identifierContext *ctx) = 0;

  virtual void enterChecker_identifier(SV2012Parser::Checker_identifierContext *ctx) = 0;
  virtual void exitChecker_identifier(SV2012Parser::Checker_identifierContext *ctx) = 0;

  virtual void enterClass_identifier(SV2012Parser::Class_identifierContext *ctx) = 0;
  virtual void exitClass_identifier(SV2012Parser::Class_identifierContext *ctx) = 0;

  virtual void enterClass_variable_identifier(SV2012Parser::Class_variable_identifierContext *ctx) = 0;
  virtual void exitClass_variable_identifier(SV2012Parser::Class_variable_identifierContext *ctx) = 0;

  virtual void enterClocking_identifier(SV2012Parser::Clocking_identifierContext *ctx) = 0;
  virtual void exitClocking_identifier(SV2012Parser::Clocking_identifierContext *ctx) = 0;

  virtual void enterConfig_identifier(SV2012Parser::Config_identifierContext *ctx) = 0;
  virtual void exitConfig_identifier(SV2012Parser::Config_identifierContext *ctx) = 0;

  virtual void enterConst_identifier(SV2012Parser::Const_identifierContext *ctx) = 0;
  virtual void exitConst_identifier(SV2012Parser::Const_identifierContext *ctx) = 0;

  virtual void enterConstraint_identifier(SV2012Parser::Constraint_identifierContext *ctx) = 0;
  virtual void exitConstraint_identifier(SV2012Parser::Constraint_identifierContext *ctx) = 0;

  virtual void enterCovergroup_identifier(SV2012Parser::Covergroup_identifierContext *ctx) = 0;
  virtual void exitCovergroup_identifier(SV2012Parser::Covergroup_identifierContext *ctx) = 0;

  virtual void enterCovergroup_variable_identifier(SV2012Parser::Covergroup_variable_identifierContext *ctx) = 0;
  virtual void exitCovergroup_variable_identifier(SV2012Parser::Covergroup_variable_identifierContext *ctx) = 0;

  virtual void enterCover_point_identifier(SV2012Parser::Cover_point_identifierContext *ctx) = 0;
  virtual void exitCover_point_identifier(SV2012Parser::Cover_point_identifierContext *ctx) = 0;

  virtual void enterCross_identifier(SV2012Parser::Cross_identifierContext *ctx) = 0;
  virtual void exitCross_identifier(SV2012Parser::Cross_identifierContext *ctx) = 0;

  virtual void enterDynamic_array_variable_identifier(SV2012Parser::Dynamic_array_variable_identifierContext *ctx) = 0;
  virtual void exitDynamic_array_variable_identifier(SV2012Parser::Dynamic_array_variable_identifierContext *ctx) = 0;

  virtual void enterEnum_identifier(SV2012Parser::Enum_identifierContext *ctx) = 0;
  virtual void exitEnum_identifier(SV2012Parser::Enum_identifierContext *ctx) = 0;

  virtual void enterFormal_identifier(SV2012Parser::Formal_identifierContext *ctx) = 0;
  virtual void exitFormal_identifier(SV2012Parser::Formal_identifierContext *ctx) = 0;

  virtual void enterFormal_port_identifier(SV2012Parser::Formal_port_identifierContext *ctx) = 0;
  virtual void exitFormal_port_identifier(SV2012Parser::Formal_port_identifierContext *ctx) = 0;

  virtual void enterFunction_identifier(SV2012Parser::Function_identifierContext *ctx) = 0;
  virtual void exitFunction_identifier(SV2012Parser::Function_identifierContext *ctx) = 0;

  virtual void enterGenerate_block_identifier(SV2012Parser::Generate_block_identifierContext *ctx) = 0;
  virtual void exitGenerate_block_identifier(SV2012Parser::Generate_block_identifierContext *ctx) = 0;

  virtual void enterGenvar_identifier(SV2012Parser::Genvar_identifierContext *ctx) = 0;
  virtual void exitGenvar_identifier(SV2012Parser::Genvar_identifierContext *ctx) = 0;

  virtual void enterHierarchical_array_identifier(SV2012Parser::Hierarchical_array_identifierContext *ctx) = 0;
  virtual void exitHierarchical_array_identifier(SV2012Parser::Hierarchical_array_identifierContext *ctx) = 0;

  virtual void enterHierarchical_block_identifier(SV2012Parser::Hierarchical_block_identifierContext *ctx) = 0;
  virtual void exitHierarchical_block_identifier(SV2012Parser::Hierarchical_block_identifierContext *ctx) = 0;

  virtual void enterHierarchical_event_identifier(SV2012Parser::Hierarchical_event_identifierContext *ctx) = 0;
  virtual void exitHierarchical_event_identifier(SV2012Parser::Hierarchical_event_identifierContext *ctx) = 0;

  virtual void enterHierarchical_identifier(SV2012Parser::Hierarchical_identifierContext *ctx) = 0;
  virtual void exitHierarchical_identifier(SV2012Parser::Hierarchical_identifierContext *ctx) = 0;

  virtual void enterHierarchical_net_identifier(SV2012Parser::Hierarchical_net_identifierContext *ctx) = 0;
  virtual void exitHierarchical_net_identifier(SV2012Parser::Hierarchical_net_identifierContext *ctx) = 0;

  virtual void enterHierarchical_parameter_identifier(SV2012Parser::Hierarchical_parameter_identifierContext *ctx) = 0;
  virtual void exitHierarchical_parameter_identifier(SV2012Parser::Hierarchical_parameter_identifierContext *ctx) = 0;

  virtual void enterHierarchical_property_identifier(SV2012Parser::Hierarchical_property_identifierContext *ctx) = 0;
  virtual void exitHierarchical_property_identifier(SV2012Parser::Hierarchical_property_identifierContext *ctx) = 0;

  virtual void enterHierarchical_sequence_identifier(SV2012Parser::Hierarchical_sequence_identifierContext *ctx) = 0;
  virtual void exitHierarchical_sequence_identifier(SV2012Parser::Hierarchical_sequence_identifierContext *ctx) = 0;

  virtual void enterHierarchical_task_identifier(SV2012Parser::Hierarchical_task_identifierContext *ctx) = 0;
  virtual void exitHierarchical_task_identifier(SV2012Parser::Hierarchical_task_identifierContext *ctx) = 0;

  virtual void enterHierarchical_tf_identifier(SV2012Parser::Hierarchical_tf_identifierContext *ctx) = 0;
  virtual void exitHierarchical_tf_identifier(SV2012Parser::Hierarchical_tf_identifierContext *ctx) = 0;

  virtual void enterHierarchical_variable_identifier(SV2012Parser::Hierarchical_variable_identifierContext *ctx) = 0;
  virtual void exitHierarchical_variable_identifier(SV2012Parser::Hierarchical_variable_identifierContext *ctx) = 0;

  virtual void enterIdentifier(SV2012Parser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(SV2012Parser::IdentifierContext *ctx) = 0;

  virtual void enterIndex_variable_identifier(SV2012Parser::Index_variable_identifierContext *ctx) = 0;
  virtual void exitIndex_variable_identifier(SV2012Parser::Index_variable_identifierContext *ctx) = 0;

  virtual void enterInterface_identifier(SV2012Parser::Interface_identifierContext *ctx) = 0;
  virtual void exitInterface_identifier(SV2012Parser::Interface_identifierContext *ctx) = 0;

  virtual void enterInterface_instance_identifier(SV2012Parser::Interface_instance_identifierContext *ctx) = 0;
  virtual void exitInterface_instance_identifier(SV2012Parser::Interface_instance_identifierContext *ctx) = 0;

  virtual void enterInout_port_identifier(SV2012Parser::Inout_port_identifierContext *ctx) = 0;
  virtual void exitInout_port_identifier(SV2012Parser::Inout_port_identifierContext *ctx) = 0;

  virtual void enterInput_port_identifier(SV2012Parser::Input_port_identifierContext *ctx) = 0;
  virtual void exitInput_port_identifier(SV2012Parser::Input_port_identifierContext *ctx) = 0;

  virtual void enterInstance_identifier(SV2012Parser::Instance_identifierContext *ctx) = 0;
  virtual void exitInstance_identifier(SV2012Parser::Instance_identifierContext *ctx) = 0;

  virtual void enterLibrary_identifier(SV2012Parser::Library_identifierContext *ctx) = 0;
  virtual void exitLibrary_identifier(SV2012Parser::Library_identifierContext *ctx) = 0;

  virtual void enterMember_identifier(SV2012Parser::Member_identifierContext *ctx) = 0;
  virtual void exitMember_identifier(SV2012Parser::Member_identifierContext *ctx) = 0;

  virtual void enterMethod_identifier(SV2012Parser::Method_identifierContext *ctx) = 0;
  virtual void exitMethod_identifier(SV2012Parser::Method_identifierContext *ctx) = 0;

  virtual void enterModport_identifier(SV2012Parser::Modport_identifierContext *ctx) = 0;
  virtual void exitModport_identifier(SV2012Parser::Modport_identifierContext *ctx) = 0;

  virtual void enterModule_identifier(SV2012Parser::Module_identifierContext *ctx) = 0;
  virtual void exitModule_identifier(SV2012Parser::Module_identifierContext *ctx) = 0;

  virtual void enterNet_identifier(SV2012Parser::Net_identifierContext *ctx) = 0;
  virtual void exitNet_identifier(SV2012Parser::Net_identifierContext *ctx) = 0;

  virtual void enterNet_type_identifier(SV2012Parser::Net_type_identifierContext *ctx) = 0;
  virtual void exitNet_type_identifier(SV2012Parser::Net_type_identifierContext *ctx) = 0;

  virtual void enterOutput_port_identifier(SV2012Parser::Output_port_identifierContext *ctx) = 0;
  virtual void exitOutput_port_identifier(SV2012Parser::Output_port_identifierContext *ctx) = 0;

  virtual void enterPackage_identifier(SV2012Parser::Package_identifierContext *ctx) = 0;
  virtual void exitPackage_identifier(SV2012Parser::Package_identifierContext *ctx) = 0;

  virtual void enterPackage_scope(SV2012Parser::Package_scopeContext *ctx) = 0;
  virtual void exitPackage_scope(SV2012Parser::Package_scopeContext *ctx) = 0;

  virtual void enterParameter_identifier(SV2012Parser::Parameter_identifierContext *ctx) = 0;
  virtual void exitParameter_identifier(SV2012Parser::Parameter_identifierContext *ctx) = 0;

  virtual void enterPort_identifier(SV2012Parser::Port_identifierContext *ctx) = 0;
  virtual void exitPort_identifier(SV2012Parser::Port_identifierContext *ctx) = 0;

  virtual void enterProduction_identifier(SV2012Parser::Production_identifierContext *ctx) = 0;
  virtual void exitProduction_identifier(SV2012Parser::Production_identifierContext *ctx) = 0;

  virtual void enterProgram_identifier(SV2012Parser::Program_identifierContext *ctx) = 0;
  virtual void exitProgram_identifier(SV2012Parser::Program_identifierContext *ctx) = 0;

  virtual void enterProperty_identifier(SV2012Parser::Property_identifierContext *ctx) = 0;
  virtual void exitProperty_identifier(SV2012Parser::Property_identifierContext *ctx) = 0;

  virtual void enterPs_class_identifier(SV2012Parser::Ps_class_identifierContext *ctx) = 0;
  virtual void exitPs_class_identifier(SV2012Parser::Ps_class_identifierContext *ctx) = 0;

  virtual void enterPs_covergroup_identifier(SV2012Parser::Ps_covergroup_identifierContext *ctx) = 0;
  virtual void exitPs_covergroup_identifier(SV2012Parser::Ps_covergroup_identifierContext *ctx) = 0;

  virtual void enterPs_checker_identifier(SV2012Parser::Ps_checker_identifierContext *ctx) = 0;
  virtual void exitPs_checker_identifier(SV2012Parser::Ps_checker_identifierContext *ctx) = 0;

  virtual void enterPs_identifier(SV2012Parser::Ps_identifierContext *ctx) = 0;
  virtual void exitPs_identifier(SV2012Parser::Ps_identifierContext *ctx) = 0;

  virtual void enterPs_or_hierarchical_array_identifier(SV2012Parser::Ps_or_hierarchical_array_identifierContext *ctx) = 0;
  virtual void exitPs_or_hierarchical_array_identifier(SV2012Parser::Ps_or_hierarchical_array_identifierContext *ctx) = 0;

  virtual void enterPs_or_hierarchical_net_identifier(SV2012Parser::Ps_or_hierarchical_net_identifierContext *ctx) = 0;
  virtual void exitPs_or_hierarchical_net_identifier(SV2012Parser::Ps_or_hierarchical_net_identifierContext *ctx) = 0;

  virtual void enterPs_or_hierarchical_property_identifier(SV2012Parser::Ps_or_hierarchical_property_identifierContext *ctx) = 0;
  virtual void exitPs_or_hierarchical_property_identifier(SV2012Parser::Ps_or_hierarchical_property_identifierContext *ctx) = 0;

  virtual void enterPs_or_hierarchical_sequence_identifier(SV2012Parser::Ps_or_hierarchical_sequence_identifierContext *ctx) = 0;
  virtual void exitPs_or_hierarchical_sequence_identifier(SV2012Parser::Ps_or_hierarchical_sequence_identifierContext *ctx) = 0;

  virtual void enterPs_or_hierarchical_tf_identifier(SV2012Parser::Ps_or_hierarchical_tf_identifierContext *ctx) = 0;
  virtual void exitPs_or_hierarchical_tf_identifier(SV2012Parser::Ps_or_hierarchical_tf_identifierContext *ctx) = 0;

  virtual void enterPs_parameter_identifier(SV2012Parser::Ps_parameter_identifierContext *ctx) = 0;
  virtual void exitPs_parameter_identifier(SV2012Parser::Ps_parameter_identifierContext *ctx) = 0;

  virtual void enterPs_type_identifier(SV2012Parser::Ps_type_identifierContext *ctx) = 0;
  virtual void exitPs_type_identifier(SV2012Parser::Ps_type_identifierContext *ctx) = 0;

  virtual void enterSequence_identifier(SV2012Parser::Sequence_identifierContext *ctx) = 0;
  virtual void exitSequence_identifier(SV2012Parser::Sequence_identifierContext *ctx) = 0;

  virtual void enterSignal_identifier(SV2012Parser::Signal_identifierContext *ctx) = 0;
  virtual void exitSignal_identifier(SV2012Parser::Signal_identifierContext *ctx) = 0;

  virtual void enterSpecparam_identifier(SV2012Parser::Specparam_identifierContext *ctx) = 0;
  virtual void exitSpecparam_identifier(SV2012Parser::Specparam_identifierContext *ctx) = 0;

  virtual void enterTask_identifier(SV2012Parser::Task_identifierContext *ctx) = 0;
  virtual void exitTask_identifier(SV2012Parser::Task_identifierContext *ctx) = 0;

  virtual void enterTf_identifier(SV2012Parser::Tf_identifierContext *ctx) = 0;
  virtual void exitTf_identifier(SV2012Parser::Tf_identifierContext *ctx) = 0;

  virtual void enterTerminal_identifier(SV2012Parser::Terminal_identifierContext *ctx) = 0;
  virtual void exitTerminal_identifier(SV2012Parser::Terminal_identifierContext *ctx) = 0;

  virtual void enterTopmodule_identifier(SV2012Parser::Topmodule_identifierContext *ctx) = 0;
  virtual void exitTopmodule_identifier(SV2012Parser::Topmodule_identifierContext *ctx) = 0;

  virtual void enterType_identifier(SV2012Parser::Type_identifierContext *ctx) = 0;
  virtual void exitType_identifier(SV2012Parser::Type_identifierContext *ctx) = 0;

  virtual void enterUdp_identifier(SV2012Parser::Udp_identifierContext *ctx) = 0;
  virtual void exitUdp_identifier(SV2012Parser::Udp_identifierContext *ctx) = 0;

  virtual void enterVariable_identifier(SV2012Parser::Variable_identifierContext *ctx) = 0;
  virtual void exitVariable_identifier(SV2012Parser::Variable_identifierContext *ctx) = 0;


};

}  // namespace Verilog
