#ifndef LIBVCD_EVENTS_HEADER_HPP
#define LIBVCD_EVENTS_HEADER_HPP

#include <tao/pegtl/nothing.hpp>

#include "vcd/grammar/commands.hpp"
#include "vcd/events/scope.hpp"
#include "vcd/events/var.hpp"
#include "vcd/events/time_scale.hpp"
#include "vcd/types/header_reader.hpp"

#include <iostream>

namespace VCD {

template<class Rule>
struct HeaderAction : tao::pegtl::nothing<Rule> {};

template<>
struct HeaderAction<Grammar::scope_command> {
  using state = ScopeEvent;

  template<class Rule>
  using action = ScopeAction<Rule>;

  static void apply0(HeaderReader&) {};
};

template<>
struct HeaderAction<Grammar::var_command> {
  using state = VarEvent;

  template<class Rule>
  using action = VarAction<Rule>;

  static void apply0(HeaderReader&) {}
};

template<>
struct HeaderAction<Grammar::upscope_command> {
  static void apply0(HeaderReader &reader) {
    reader.upscope();
  }
};

template<>
struct HeaderAction<Grammar::version_command> {
  template<class Input>
  static void apply(const Input& input, HeaderReader &reader) {
    reader.version(input.string());
  }
};

template<>
struct HeaderAction<Grammar::date_command> {
  template<class Input>
  static void apply(const Input& input, HeaderReader &reader) {
    // TODO handle with grammar rather than trimming
    reader.date(input.string());
  }
};

template<>
struct HeaderAction<Grammar::timescale_command> {
  using state = TimeScaleEvent;

  template<class Rule> using action = TimeScaleAction<Rule>;

  static void apply0(HeaderReader&) {}

};

template<>
struct HeaderAction<HeaderReader> {
  static void success(HeaderReader &reader, ScopeEvent event) {
    reader.scope(event.type, std::string(event.identifier));
  }

  static void success(HeaderReader &reader, VarEvent event) {
    reader.var(event.type, event.size, std::string(event.id_code), std::string(event.reference));
  }

  static void success(HeaderReader &reader, TimeScaleEvent event) {
    reader.timescale(event.number, event.unit);
  }
};

} // namespace VCD

#endif // LIBVCD_EVENTS_HEADER_HPP
