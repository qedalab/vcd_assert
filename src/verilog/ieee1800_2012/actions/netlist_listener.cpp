#include "verilog/ieee1800_2012/actions/netlist_listener.hpp"

using namespace Verilog;

// namespace ac = antlrcpp;
// using sp = SV2012Parser;

NetlistListener::NetlistListener(std::shared_ptr<SV2012Parser> parser,
                                 std::shared_ptr<DesignReader> reader) :
    parser_(parser),
    reader_(reader)
{
}

void NetlistListener::enterModule_declaration(
    SV2012Parser::Module_declarationContext *ctx)
{
  auto tokens = parser_->getTokenStream();
  if (ctx->module_identifier(0)) {
    reader_->next_module();
  } else {
    throw std::runtime_error(
        "InternalError(listener has no module identifier)");
  }
}

void NetlistListener::exitModule_declaration(
    SV2012Parser::Module_declarationContext *ctx)
{
}

void NetlistListener::enterModule_instantiation(
    SV2012Parser::Module_instantiationContext *ctx)
{
  auto tokens = parser_->getTokenStream();
  if (ctx->module_identifier() && !ctx->hierarchical_instance().empty()) {
    
    //TODO should handle MULTI instantiation? 0 -> n; not just 0.
    auto module_ident = tokens->getText(ctx->module_identifier());
    auto inst_ident = tokens->getText(ctx->hierarchical_instance(0)
                                          ->name_of_instance()
                                          ->instance_identifier());

    reader_->instance(NetType::module, "dummy", inst_ident, module_ident);
  } else {
    throw std::runtime_error(
        "InternalError(listener has no module identifier)");
  }
}

void NetlistListener::exitModule_instantiation(
    SV2012Parser::Module_instantiationContext *ctx)
{
}

void NetlistListener::enterGate_instantiation(
    SV2012Parser::Gate_instantiationContext *ctx)
{

  // HOW DOES VCD ASSERT HANDLE PRIMITIVES?
    
  // auto tokens = parser_->getTokenStream();
  // if (ctx->module_identifier() && !ctx->hierarchical_instance().empty()) {
    
  //   //TODO should handle MULTI instantiation? 0 -> n; not just 0.
  //   auto module_ident = tokens->getText(ctx->module_identifier());
  //   auto inst_ident = tokens->getText(ctx->hierarchical_instance(0)
  //                                         ->name_of_instance()
  //                                         ->instance_identifier());

  //   reader_->instance(NetType::module, "dummy", inst_ident, module_ident);
  // } else {
  //   throw std::runtime_error(
  //       "InternalError(listener has no module identifier)");
  // }
}

void NetlistListener::exitGate_instantiation(
    SV2012Parser::Gate_instantiationContext *ctx)
{
}