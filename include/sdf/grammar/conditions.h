#ifndef LIBSDF_GRAMMAR_CONDITIONS_H
#define LIBSDF_GRAMMAR_CONDITIONS_H

#include "base.h"
#include "constants.h"
#include "operators.h"
#include "timing.h"


namespace SDF {
namespace Grammar {
// clang-format off

// farward
struct simple_expression;
struct concat_expression;
struct timing_check_condition;
struct scalar_node;

// extern
struct scalar_port;
struct scalar_net;
struct port;


struct conditional_port_expr : sor<
  simple_expression,
  op_sep_seq<
    one<'('>, opt<unary_operator>, conditional_port_expr, one<')'>
  >,
  seq< conditional_port_expr, binary_operator, conditional_port_expr >
>{};

struct simple_expression : sor<
  op_sep_seq<
    one<'('>, opt<unary_operator>, simple_expression, one<')'>
  >,
  op_sep_seq<
    opt<unary_operator>,
    port
  >,
  op_sep_seq<
    opt<unary_operator>, 
    scalar_constant
  >,
  op_sep_seq< 
    simple_expression,
    one< '?'>,
    simple_expression,
    one< ':'>,
    simple_expression
  >,
  star< 
    op_sep_seq< 
      simple_expression,
      star< 
        simple_expression,
        opt< concat_expression >
      >
    >
  >
>{};

struct concat_expression : op_sep_seq<
  one< ',' >,
  simple_expression
>{};

struct timing_check_condition : sor<
  seq< inversion_operator, sps, scalar_node >,
  seq< scalar_node, equality_operator, scalar_constant >,
  scalar_node
>{};
struct scalar_node : sor<
  scalar_port,
  scalar_net
>{};

// clang-format on
} // namespace Grammar
} // namespace SDF

#endif // LIBSDF_GRAMMAR_CONDITIONS_H
