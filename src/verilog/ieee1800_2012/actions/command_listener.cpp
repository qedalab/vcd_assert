#include "verilog/ieee1800_2012/actions/command_listener.hpp"

using namespace Verilog;

// namespace ac = antlrcpp;
// using sp = SV2012Parser;

CommandListener::CommandListener(std::shared_ptr<SV2012Parser> parser,
                                 std::shared_ptr<DesignReader> reader) :
    parser_(parser),
    reader_(reader)
{
}

void CommandListener::enterModule_declaration(
    SV2012Parser::Module_declarationContext *ctx)
{
  auto tokens = parser_->getTokenStream();
  if (!ctx->module_identifier(0)) {
    auto identifier =  ctx->module_identifier(0);
    // reader_->set_current_module(identifier);
  } else {
    throw std::runtime_error("InternalError(listener has no module identifier)");
  }
}

void CommandListener::enterSystem_tf_call(
    SV2012Parser::System_tf_callContext *ctx)
{
  auto tokens = parser_->getTokenStream();
  if ((ctx->System_tf_identifier()) &&
      (!ctx->list_of_arguments())) {
    
    // SV2012Parser::List_of_argumentsContext = ctx->list_of_arguments();

    // Verilog::Command command{};

    // switch

    // reader_->comand(command);
  } else {
    throw std::runtime_error("InternalError(listener has no module identifier)");
  }
}
