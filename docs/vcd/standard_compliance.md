# LibVCD standard compliance

The VCD grammar we used is as specified by the 2017 SystemVerilog standard.
The main purpose of the library is to parse IVerilog VCD generated dumps and is
the only simulator whose format we'll adapt our parser for while trying to
maintain standard correctness.

#### Grammar problems of VCD

 * Poorly defined what counts as whitespace and where it is allowed.
   Implementation chose the following characters as whitespace: `' '`, `'\n'`,
   `'\r'`, `'\t'`, `'\v'`, `'\f'`.  We also tried to allow and require
   whitespace where we thought reasonable.
 * Used `binary_value` instead of `binary_number` in `binary_value_change`
   since there is clearly not a double `b` in any examples or output of
   simulators.
 * The wording says that the `real` number should be dumped with `%.16g`, but
   the grammar specifies `real_number` which doesn't allow numbers like '2'
   which can be exactly represented by '2' and subsequently output by `printf`
   as such. Implementation allows numbers without decimal points or exponent.
 
 #### Things we are uncertain about:
 * Whether or not a variable must fall within a scope. Implementation chose to
   not allow.
 * Whether or not more than one root scope is allowed. Implementation chose to
   not allow.
 * Multiple references are allowed to point to the same identifier code, but
   the references doesn't necesarily have the same variable type. Things like
   `reg` and `wire` can have the same identifier code, but `real` and `wire`
   make things difficult since `real`'s are specified with `real_value_change`
   and `wire`'s aren't. The standard doesn't appear to offer any guidance in
   this case. Implementation chose to allow everything to alias eachother
   except `real`'s. References sharing the same identifier code always has to
   have the same type.
 
These are not strictly disallowed by VCD, but adding those restriction seem
sensible to us.
   
#### IVerilog quirks

 * In IVerilog generate blocks creates scopes whose identifier contain `[` and
   `]` which is not allowed by the standard. For compatibility we used
   `reference` as the scope's `identifier`.
