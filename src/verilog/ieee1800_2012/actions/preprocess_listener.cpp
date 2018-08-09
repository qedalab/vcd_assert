#include "verilog/ieee1800_2012/actions/preprocess_listener.hpp"

using namespace Verilog;

PreprocessListener::PreprocessListener(std::shared_ptr<SV2012Parser> parser,
                                       std::shared_ptr<DesignReader> reader,
                                       std::string file_path) :
    parser_(parser),
    reader_(reader),
    file_path_(file_path)
{
}


void PreprocessListener::enterModule_declaration(
    SV2012Parser::Module_declarationContext *ctx)
{
  auto tokens = parser_->getTokenStream();
  if (!ctx->module_identifier().empty()) {
    // auto identifier = ctx->module_identifier(0);

    auto identifier = tokens->getText(ctx->module_identifier(0));
    reader_->module(identifier,file_path_);
  } else {
    throw std::runtime_error("InternalError(listener has no module identifier)");
  }
}

void PreprocessListener::enterInclude_statement(
    SV2012Parser::Include_statementContext *ctx)
{
  auto tokens = parser_->getTokenStream();
  // if (ctx->File_path_spec() != null) {
  //   // auto current_module_identifier;
  //   // auto file_path_spec = ctx->File_path_spec();
  //   // auto include_path = file_path_spec.get_token().get_symbol().to_string();
  //                                   //tokens->getText(file_path_spec.getcontent());
  //   // reader_->include(current_module_identifier, include_path);
  // } else {
  //   throw std::runtime_error("InternalError(listener has no module identifier)")
  // }
}

void PreprocessListener::enterPp_timescale_declaration(
    SV2012Parser::Pp_timescale_declarationContext *ctx)
{
  auto tokens = parser_->getTokenStream();
  if (!ctx->time_literal().empty()) {
    if (ctx->time_literal().size() == 1) {
      // set timescale
    } else if (ctx->time_literal().size() == 2) {
      // set timescale and time precision
    }
  }
}

void PreprocessListener::enterSource_text(SV2012Parser::Source_textContext *ctx)
{
  // current_file_ =
  // time_scale =
}

void PreprocessListener::exitSource_text(
    SV2012Parser::Module_declarationContext *ctx)
{
  // needed?
}


/* preprocessor from gburdell sv2012 'parser' */

//     private static final Pattern stSpacePatt = Pattern.compile("([ \t]+)(?=[^
//     \t])");
//     //reuse non-capturing whitespace w/ block-comment
//     static final String stNCWS = "(?:[ \t]|/\\*.*?\\*/)+";
//     private static final Pattern stAfterTicInclude = Pattern.compile("(?:[
//     \t]|/\\*.*?\\*/|//[^\n]*)*");
//     //reuse time unit
//     private static final String stTU = "(10?0?\\s*[munpf]s)";
//     private static final Pattern stUndef
//             = Pattern.compile("(`undef(?=\\W))(" + stNCWS +
//             "([a-zA-Z_]\\w*)(?=\\W))?");
//     private static final Pattern stTimescale
//             = Pattern.compile("(`timescale(?=\\W))(" + stNCWS + stTU + "[
//             \t]*/[ \t]*" + stTU + "(?=\\W))?");
//     private static final Pattern stDefaultNetType
//             = Pattern.compile("(`default_nettype(?=\\W))(" + stNCWS +
//             "([a-z]\\w+)(?=\\W))?");
//     private static final Pattern stNetType
//             =
//             Pattern.compile("u?wire|tri[01]?|w(and|or)|tri(and|or|reg)|none");
//     private static final Pattern stTicInclude
//             = Pattern.compile("(`include(?=\\W))(" + stNCWS
//                     + "(\\\"([^\\\"]+)(\\\"))|(<[^>]+(>)))?");
//     // `line 1
//     "/media/sf_karlp_Documents/altera/proj1/s1_core/hdl/s1_top.flat.v" 0
//     private static final Pattern stTicLine
//             = Pattern.compile("(`line(?=\\W))(" + stNCWS + "\\d+" + stNCWS
// + "(\\\"([^\\\"]+)(\\\"))" + stNCWS + "\\d" + "(?=\\W))?");