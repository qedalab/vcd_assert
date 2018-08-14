
The arguments start with the vcd file.

This is the vcd file that gets parsed by vcd_assert.

.. code-block:: bash

  vcd_file FILE REQUIRED      VCD file

Next is the verilog files

.. code-block:: bash

  verilog_files FILE ...      Verilog source file(s)

If the SDF files are specified with instance names instead of with `*` then
the verilog files can be omitted.
