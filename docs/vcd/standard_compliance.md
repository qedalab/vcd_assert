# LibVCD standard compliance

The VCD grammar we used is as specified by the 2017 SystemVerilog standard.
The main purpose of the library is to parse IVerilog VCD generated dumps and is
the only simulator whose format we'll adapt our parser for while trying to maintain
standard correctness.

#### Grammar problems of VCD

 * Poorly defined what counts as whitespace and where it is allowed. Implementation chose
   the following characters as whitespace: `' '`, `'\n'`, `'\r'`, `'\t'`, `'\v'`, `'\f'`.
   We also tried to allow and require whitespace where we thought reasonable.
 * Used `binary_value` instead of `binary_number` in `binary_value_change` since there
   is clearly not a double `b` in any examples or output of simulators.
 
 #### Things we are uncertain about:
 * Whether or not a variable must fall within a scope. Implementation chose to not allow.
 * Whether or not more than one root scope is allowed. Implementation chose to not allow.
 
These are not strictly disallowed by VCD, but adding those restriction seem sensible to us.
   
#### IVerilog quirks

 * In IVerilog generate blocks creates scopes whose identifier contain `[` and `]`
   which is not allowed by the standard. For compatibility we used `reference` as
   the scope's `identifier`.