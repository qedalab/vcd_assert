
#ifndef LIBVERILOG_ANTLR_RUNTIME_WRAPPER_HPP
#define LIBVERILOG_ANTLR_RUNTIME_WRAPPER_HPP

#ifdef __GNUC__
// Avoid tons of warnings with root code
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
#include <antlr4-runtime.h>
#pragma GCC diagnostic pop
#else
#include <antlr4-runtime.h>
#endif

// using namespace sv = SystemVerilog;
#endif // LIBVERILOG_ANTLR_RUNTIME_WRAPPER_HPP
