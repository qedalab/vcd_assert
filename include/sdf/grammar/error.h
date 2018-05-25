// template <typename Rule>
// struct error_control : normal<Rule> {
//   static const std::string error_message;

//   template <typename Input, typename... States>
//   static void raise(const Input &in, States &&... /*unused*/) {
//     throw parse_error(error_message, in);
//   }
// };

// template <>
// const std::string error_control<comment_cont>::error_message =
//     "unterminated comment"; // NOLINT

// template <>
// const std::string error_control<quoted_string_cont>::error_message =
//     "unterminated string (missing '\"')"; // NOLINT
// template <>
// const std::string error_control<prose_val_cont>::error_message =
//     "unterminated prose description (missing '>')"; // NOLINT

// template <>
// const std::string error_control<hex_val::value>::error_message =
//     "expected hexadecimal value"; // NOLINT
// template <>
// const std::string error_control<dec_val::value>::error_message =
//     "expected decimal value"; // NOLINT
// template <>
// const std::string error_control<bin_val::value>::error_message =
//     "expected binary value"; // NOLINT
// template <>
// const std::string error_control<num_val_choice>::error_message =
//     "expected base specifier (one of 'bBdDxX')"; // NOLINT

// template <>
// const std::string error_control<option_close>::error_message =
//     "unterminated option (missing ']')"; // NOLINT
// template <>
// const std::string error_control<group_close>::error_message =
//     "unterminated group (missing ')')"; // NOLINT

// template <>
// const std::string error_control<repetition>::error_message =
//     "expected element"; // NOLINT
// template <>
// const std::string error_control<concatenation>::error_message =
//     "expected element"; // NOLINT
// template <>
// const std::string error_control<alternation>::error_message =
//     "expected element"; // NOLINT

// template <>
// const std::string error_control<defined_as>::error_message =
//     "expected '=' or '=/'"; // NOLINT
// template <>
// const std::string error_control<c_nl>::error_message =
//     "unterminated rule"; // NOLINT
// template <>
// const std::string error_control<rule>::error_message =
//     "expected rule"; // NOLINT