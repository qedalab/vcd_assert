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
  Parse::Util::debug_puts("DEBUG: CommandListener: Enter Module");

  // Parse::Util::debug_puts("DEBUG: Module identifier ({})",
                            // tokens->getText(identifier));
  reader_->next_module();
  
  // Parse::Util::debug_puts("DEBUG: Match ({})",
                          //  tokens->getText(ctx->module_nonansi_header()));

}

void CommandListener::exitSystem_tf_call(
    SV2012Parser::System_tf_callContext *ctx)
{

  // Parse::Util::debug_print
  auto tokens = parser_->getTokenStream();
  Parse::Util::debug_puts("DEBUG: CommandListener: Found system task/function");
  Parse::Util::debug_puts("DEBUG: CommandListener: Match ({})",
                          tokens->getText(ctx));

  if ((ctx->System_tf_identifier()) && (ctx->list_of_arguments())) {

    Parse::Util::debug_puts(
        "DEBUG: CommandListener: identifier ({})",
        ctx->System_tf_identifier()->getSymbol()->getText());
    Parse::Util::debug_puts("DEBUG: CommandListener: args ({})",
                            tokens->getText(ctx->list_of_arguments()));
    SV2012Parser::List_of_argumentsContext *args_ctx = ctx->list_of_arguments();
    Command command{};

    auto str = ctx->System_tf_identifier()->getSymbol()->getText();

    if (str == "$sdf_annotate") {
      Parse::Util::debug_puts(
          "DEBUG: CommandListener: detected $sdf_annotate system task");
      auto sdf_file_ctx = args_ctx->expression();

      if (!sdf_file_ctx) {
        throw std::runtime_error("$sdf_annotate argument list empty.");
      }
      // std::cout << "-- detected hierarchical identifier" << std::endl;

      auto ctxv = args_ctx->positional_expression_argument();

      std::string sdf_file = tokens->getText(sdf_file_ctx);
      std::optional<std::string> name_of_instance{};
      std::optional<std::string> config_file{};
      std::optional<std::string> log_file{};
      std::optional<std::string> mtm_spec{};
      std::optional<std::string> scale_factors{};
      std::optional<std::string> scale_type{};

      if (!ctxv.empty()) {
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
      }
      Parse::Util::debug_puts(
          "DEBUG: CommandListener: build SDFAnnotateCommand");
      SDFAnnotateCommand sdf_annotate_command{
          sdf_file, name_of_instance, config_file, log_file,
          mtm_spec, scale_factors,    scale_type};

      command = sdf_annotate_command;
      reader_->command(command, "dummy");
      Parse::Util::debug_puts("DEBUG: CommandListener: store command");
    } else {
      // do nothing
    }

  } else {
    // do nothing
    Parse::Util::debug_puts("context invalid");

    // throw std::runtime_error(
    //     "InternalError(system task identifier null)");
  }
}