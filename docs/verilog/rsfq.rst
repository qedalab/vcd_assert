RSFQ Verilog cells
==================

RSFQ cells are stateful devices. Simulating these with timing assertions with
open-source tools was the main motivation for the develpment of this tool.
This section describes RSFQ Verilog representation.

Verilog and SystemVerilog is inherently a voltage level logic verification language. SFQ circuits
such as RSFQ and ERSFQ use distinct, quantized pulses which do not precicely
match the voltage-level semantics that are available. We therefore describe
SFQ pulses using the edge representation. The net effect is that simulation
outputs resemble the output from a SFQ-to-DC converter.
Both posedge and negedge represent a pulse. The alternative to
use a voltage pulse by adding a ``1`` time unit delay before reverting to
zero puts unnecesary strain on the simulator which immediately requires twice
the number of events as well as twice the output data. The pulse
representation adds no benefit over the edge representation so that the edge
representation is prefereble because of simulation effeciency.

The integration tests include quite a few examples, but we are going to go
through the ``basic_and`` as an example which covers everything.

The first part of the file is the timescale and the module definition. The
module takes a parameter that specifies when the cell start reacting on input.
The default parameter is specified as a macro to allow the parameter to be
set from the commandline as well if neccesary. This is neccesary too prevent
the cell switching states and trigger timing violations from the initial setup.

.. code-block:: verilog

  `ifndef begin_time
  `define begin_time 8
  `endif

  `timescale 1ps/100fs
  
  module basic_and
    #(
      parameter begin_time = `begin_time
    ) (
      input a,
      input b,
      input clk,
      output out
    );

  // Starting definitions ...
  // Specify block ...
  // Initial block ...
  // State machine ...

  endmodule

Define internal output variables. This is to work around a limitation ``cver`` where it doesn't
correctly handle delays if the output is a register.

.. code-block:: verilog

  reg internal_out;
  assign out = internal_out;

Next the internal state variables are defined. What is allowed in timing check
conditions are quite limiting. Integer comparisons are not allowed, and we require
the timing assertions to be stateful so that we introduce an intermediate wire that
handles the integer comparisons. The case equality operator, ``===``, is used so that we
can have ``X`` as an invalid state.

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

The ``specparams`` are used to define variables that hold timing
information. We follow a strict naming convention to simplify toolchain integration.

Critical timing violations start with `ct` , followed by which state these are
for. Next is the name of the input that initiates the timing check, and finally 
the name of the input on which no pulses should arrive.

A delay parameter starts with ``delay``, followed by the state that triggers it,
then followed by the input triggering the output and finally the output on which
a pulse is produced.

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

Critical timings are specified with `$hold` assertions. These are used with the
following. The first condition:

.. code-block:: verilog

  $hold( posedge clk &&& internal_state_0, a, ct_state0_clk_a);
  $hold( negedge clk &&& internal_state_0, a, ct_state0_clk_a);

Both the posedge and negedge are required for compatibility with older Verilog
standards. These events represent an SFQ pulse arriving on that input (``clk`` in
the example). Since assertions are stateful we need to include the state of
the cell in which an assertion is made. The Verilog standard requires a ``&&&``
to seperate the timing event and the timing condition. We again use the
internal state wire due to the limiting syntax of Verilog/SystemVerilog. The
next parameter is the input on which no pulses should arrive (`a` in this case).
The final parameter is the duration after the initial trigger no input SFQ
pulses are allowed.

The rest of the AND's assertions are as follows

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

RSFQ cells are not driven in the same way that voltage level logic is, so 
that we explicitly give it an initial state after the specify block. 
We also have to set the output pins to some start value; either ``1``
or ``0``. The value is irrelevant; it toggles on an event to
``output = !output``.

.. code-block:: verilog

  initial begin
      state = 1'bX;
      internal_out = 0;
      #begin_time state = 0;
  end

Lastly, the state machine is defined that triggers on an edge event.
We use case statements to get to the correct state. So as to avoid event
triggers on the initial set, we start from an arbitrary time step (such as 2)
that does not include the initial time. To put the device in an invalid or
error state, the state and outputs are set to `1'bX`. In the example below,
this occurs after either `a` or `b` arrive in state 3.

.. code-block:: verilog

  always @(posedge a or negedge a)
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

  always @(posedge b or negedge b)
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

  always @(posedge clk or negedge clk)
  case (state)
      3: begin
          out = !out;
          state = 0;
      end
  endcase
