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
  if (!ctx->module_identifier().empty()) {
    auto identifier = tokens->getText(ctx->module_identifier()[0]);
    // auto module_i = modmap.find(identifier);
        // set current module name

  } else {
    throw std::runtime_error("InternalError(listener has no module identifier)");
  }
}

void NetlistListener::exitModule_declaration(
    SV2012Parser::Module_declarationContext *ctx)
{
}



void NetlistListener::enterModule_instantiation(
    SV2012Parser::Module_instantiationContext *ctx)
{
}

void NetlistListener::exitModule_instantiation(
    SV2012Parser::Module_instantiationContext *ctx)
{
}

void NetlistListener::enterGate_instantiation(
    SV2012Parser::Gate_instantiationContext *ctx)
{
}

void NetlistListener::exitGate_instantiation(
    SV2012Parser::Gate_instantiationContext *ctx)
{
}