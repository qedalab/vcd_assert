RSFQ Verilog cells
==================

RSFQ cells are statefull devices. Simulating them with timing assertions with
open-source tools was the main motivation for this tool. This sections
describes their verilog representation.

Verilog is inherently a voltage level logic verification language. RSFQ are
distinct pulses which doesn't precicely match the voltage-level semantics that
is available. The best way we found to describe them was using the edge
representation (The same that is seen as die output from a SDF-to-DC
converter). Both a posedge and negedge represents a pulse. The alternative to
use a voltage pulse by adding a `1` time unit delay before dropping back to
zero puts unnecesary strain on the simulator which immediately requires twice
the amount of events as well as twice the amount of output data. The pulse
representation adds no benefit over the edge representation so the edge
representation is prefereble because of simulation effeciency.

The integration tests include quite a few examples, but we are going to go
through the `basic_and` as an example which covers everything.

First the time scale and module definition

.. code-block:: verilog

  `timescale 1ps/100fs
  module basic_and (a, b, clk, out);

  // Starting definitions ...
  // Specify block ...
  // Initial block ...
  // State machine ...

  endmodule

Define the inputs

.. code-block:: verilog

  input a, b, clk;

Define the outputs and the registers that drive them

.. code-block:: verilog

  output out;
  reg out;

What is allowed in timing check conditions are quite limiting. The don't allow
integer comparisons and we require the timing assertions be stateful so we
introduce an intermediate wire that does the integer comparisons.

.. code-block:: verilog

  wire internal_state_0,
       internal_state_1,
       internal_state_2,
       internal_state_3;

  assign internal_state_0 = state === 0;
  assign internal_state_1 = state === 1;
  assign internal_state_2 = state === 2;
  assign internal_state_3 = state === 3;

Next is the specify block wherin all the delays and timing assertions are
specified.

.. code-block:: verilog

  specify

    // Spec params ...
    // Delays ...
    // Timing assertions ...

  endspecify

The `specparams` are there used to define variables that hold timing
information. We follow a strict naming convention to make out lives easier.

Critical timing violations start with `ct` , followed by which state they are
for, followed on which input starts the timing check and finally which input no
pulses should arrive.

Delays start with `delay`, followed by which state they trigger in, followed by
the input triggering the output and finally the output on which they produce a
pulse.

.. code-block:: verilog

  // Output delays
  specparam delay_state3_clk_out = 5.5;

  // Critical timing spec params
  specparam ct_state0_clk_a = 2.5;
  specparam ct_state0_clk_b = 2.5;
  specparam ct_state1_a_b = 1;
  specparam ct_state1_a_clk = 7.0;
  specparam ct_state1_clk_b = 2.5;
  specparam ct_state2_b_a = 1;
  specparam ct_state2_b_clk = 7.0;
  specparam ct_state2_clk_a = 2.5;
  specparam ct_state3_clk_a = 0.5;
  specparam ct_state3_clk_b = 0.5;

Delays are specified conditionally based on the state

.. code-block:: verilog

  if (internal_state_3) (clk => out) = delay_state3_clk_out;

Critical Timing are specified with `$hold` assertions. They are used with the
following. The first condition:

.. code-block:: verilog

  $hold( posedge clk &&& internal_state_0, a, ct_state0_clk_a);
  $hold( negedge clk &&& internal_state_0, a, ct_state0_clk_a);

Both the posedge and negedge is required for compatibility with older verilog
standards. They represent the sfq pulse arriving on that input (`clk` in the
example). Since assertions are statefull we need to also include the state of
the cell in which in assertion is made. The verilog standard requires a `&&&`
to seperate the timing event and the timing condition. We again use the
internal state wire due to the limiting syntac of Verilog/SystemVerilog. The
next param is the line on which no outputs should come (`a` in this case). The
final parameter is how long after the initial trigger no outputs should come.

The rest of the and's assertions are as follows

.. code-block:: verilog

  $hold( posedge clk &&& internal_state_0, b, ct_state0_clk_b);
  $hold( negedge clk &&& internal_state_0, b, ct_state0_clk_b);

  $hold( posedge a &&& internal_state_1, b, ct_state1_a_b);
  $hold( negedge a &&& internal_state_1, b, ct_state1_a_b);

  $hold( posedge a &&& internal_state_1, clk, ct_state1_a_clk);
  $hold( negedge a &&& internal_state_1, clk, ct_state1_a_clk);

  $hold( posedge clk &&& internal_state_1, b, ct_state1_clk_b);
  $hold( negedge clk &&& internal_state_1, b, ct_state1_clk_b);

  $hold( posedge b &&& internal_state_2, a, ct_state2_b_a);
  $hold( negedge b &&& internal_state_2, a, ct_state2_b_a);

  $hold( posedge b &&& internal_state_2, clk, ct_state2_b_clk);
  $hold( negedge b &&& internal_state_2, clk, ct_state2_b_clk);

  $hold( posedge clk &&& internal_state_2, a, ct_state2_clk_a);
  $hold( negedge clk &&& internal_state_2, a, ct_state2_clk_a);

  $hold( posedge clk &&& internal_state_3, a, ct_state3_clk_a);
  $hold( negedge clk &&& internal_state_3, a, ct_state3_clk_a);

  $hold( posedge clk &&& internal_state_3, b, ct_state3_clk_b);
  $hold( negedge clk &&& internal_state_3, b, ct_state3_clk_b);

The rsfq cells aren't driven in the same way that voltage level logic is so we
explicitly give it an initial state after the specify block. We also have to
set the output pins to somethings. It doesn't matter if it's `1` or `0`. It is
just something that always triggers an edge on `output = !output`.

.. code-blocK:: verilog

  initial begin
      state = 0;
      out = 0;
  end

Finally the state machine which triggers on an edge and then uses a case to get
to the correct state. To not trigger pulses on the initial set we start from
time step 2 (an `arbitrary` number which does not include the initial time). To
put the device in an invalid state we simple set the state and outputs to
`1'bX`.  In this case it happes after either `a` or `b` arrive in the fragile
state 3.

.. code-block:: verilog

  always @(posedge a or negedge a)
  begin if ($time>2)
      case (state)
          0: begin
              state = 1;
          end
          2: begin
              state = 3;
          end
          3: begin
              // Input leads to invalid state
              state = 1'bX;
              out = 1'bX;
          end
      endcase
  end

  always @(posedge b or negedge b)
  begin if ($time>2)
      case (state)
          0: begin
              state = 2;
          end
          1: begin
              state = 3;
          end
          3: begin
              // Input leads to invalid state
              state = 1'bX;
              out = 1'bX;
          end
      endcase
  end

  always @(posedge clk or negedge clk)
  begin if ($time>2)
      case (state)
          3: begin
              out = !out;
              state = 0;
          end
      endcase
  end
