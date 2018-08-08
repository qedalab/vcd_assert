#include "verilog/ieee1800_2012/actions/command_listener.hpp"

using namespace Verilog;
namespace rsv = ranges::view;

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
  if (ctx->module_identifier(0)) {
    // auto identifier = ctx->module_identifier(0);
    reader_->next_module();
  } else {
    throw std::runtime_error(
        "InternalError(listener has no module identifier)");
  }
}

void CommandListener::enterSystem_tf_call(
    SV2012Parser::System_tf_callContext *ctx)
{
  auto tokens = parser_->getTokenStream();
  if ((ctx->System_tf_identifier()) && (ctx->list_of_arguments())) {

    SV2012Parser::List_of_argumentsContext *args_ctx = ctx->list_of_arguments();
    Command command{};

    auto str = ctx->System_tf_identifier()->getSymbol()->getText();

    if (str == "sdf_annotate") {

      auto sdf_file_ctx =
          args_ctx->expression()->primary()->hierarchical_identifier();

      if (!sdf_file_ctx) {
        throw std::runtime_error("InternalError");
      }

      auto ctxv = args_ctx->positional_expression_argument();

      std::string sdf_file = tokens->getText(sdf_file_ctx);
      std::optional<std::string> name_of_instance{};
      std::optional<std::string> config_file{};
      std::optional<std::string> log_file{};
      std::optional<std::string> mtm_spec{};
      std::optional<std::string> scale_factors{};
      std::optional<std::string> scale_type{};

      for (auto &&[i, op_ctx] : rsv::zip(rsv::indices, ctxv)) {
        switch (i) {
        case 0:
          if (op_ctx->expression()) {
            name_of_instance = tokens->getText(op_ctx->expression());
          }
          break;
        case 1:
          if (op_ctx->expression()) {
            config_file = tokens->getText(op_ctx->expression());
          }
          break;
        case 2:
          if (op_ctx->expression()) {
            log_file = tokens->getText(op_ctx->expression());
          }
          break;
        case 3:
          if (op_ctx->expression()) {
            mtm_spec = tokens->getText(op_ctx->expression());
          }
          break;
        case 4:
          if (op_ctx->expression()) {
            scale_factors = tokens->getText(op_ctx->expression());
          }
          break;
        case 5:
          if (op_ctx->expression()) {
            scale_type = tokens->getText(op_ctx->expression());
          }
          break;

        default:
          break;
        }
      }

      SDFAnnotateCommand sdf_annotate_command{
          //clang-format off
          tokens->getText(sdf_file_ctx),
          name_of_instance,
          config_file,
          log_file,
          mtm_spec,
          scale_factors,
          scale_type
          //clang-format on
      };
     
      command = sdf_annotate_command;
      reader_->command(command, "dummy");
    }else{
      //do nothing
    }

  } else {
    throw std::runtime_error(
        "InternalError(system task identifier null)");
  }
}