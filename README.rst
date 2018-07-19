==========
VCD Assert
==========

.. image:: https://travis-ci.org/pleroux0/docker-ubuntu-clang6-devel.svg?branch=master
    :target: https://travis-ci.org/pleroux0/docker-ubuntu-clang6-devel

.. image:: https://codecov.io/gh/pleroux0/vcd_assert/branch/master/graph/badge.svg
  :target: https://codecov.io/gh/pleroux0/vcd_assert<Paste>

An external program that checks for timing violations outside of the simulator,
by looking at the VCD output.

Building
========

Binary dependencies
-------------------
* Building requires conan_ (optional, but recommended)
* Building requirse cmake_
* Building requires an up to date c++ compiler (one of the below):

  * `g++`_ version 7 or newer
  * `clang++`_ version 6 with libc++ version or newer

Setup the environment for building in CentOS
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

These steps are also what is followed to setup the CentOS system in Travis for
automated testing

Installing repositories

.. code-block:: bash

   sudo yum -y update
   sudo yum -y epel-release centos-release-scl

If you are using conan_ for managing library dependencies (recommended):

.. code-block:: bash

  sudo yum -y python-pip
  pip install conan --user

Install compiler and build tools:

.. code-block:: bash

  sudo yum -y install devtoolset-7 git wget

Install an updated version of cmake:

.. code-block:: bash

  wget "https://cmake.org/files/v3.12/cmake-3.12.0-rc3-Linux-x86_64.sh"
  sudo bash cmake-3.12.0-rc3-Linux-x86_64.sh --prefix=/usr/local --skip-license

Use compiler:

.. code-block:: bash

  scl enable devtoolset-7

This opens up a new bash console with the devtoolset compiler set as default. You
need to continue in this shell for all the following build steps.

Library dependencies
--------------------

VCD Assert depends on the following libraries.

 * PEGTL_ (2.6.0) - Parse Expression Grammar Template Library
 * Range-V3_ (0.3.6) - Experimental range library for C++11/14/17
 * fmt_ (5.0 or newer) - A modern formatting library
 * Catch2_ (master branch) - A modern, C++-native, header-only, test framework for unit-tests
 * CLI11_ (1.5.6 or newer)- Command line parser for C++11

The recommended way of handling library dependencies is through conan_, but the
correct versions can also be installed manually in a place where cmake_ can
find it.

Building
--------
Fetch source

.. code-block:: bash

  git clone https://github.com/pleroux0/vcd_assert.git
  cd vcd_assert

Make and change to build directory

.. code-block:: bash

  mkdir build
  cd build

Insall dependencies
~~~~~~~~~~~~~~~~~~~
Use conan to fetch and setup dependencies (recommended)

.. code-block:: bash

  conan remote add pleroux0 "https://api.bintray.com/conan/pleroux0/pleroux0"
  conan install .. -s build_type=Release

You might have to specify the compiler and version in the install step if
conan's defaults are not correct

.. code-block:: bash

  conan install .. -s build_type=Release -s compiler.version=7 -s compiler=gcc

Or manually install them where cmake can find them

Compiling
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

With conan (recommended):

.. code-block:: bash

  conan build ..

With conan dependencies only:

.. code-block:: bash

  cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_paths.cmake -DBUILD_TESTS=ON -DBUILD_TYPE=Release
  cmake --build .

Without conan:

.. code-block:: bash

  cmake .. -DBUILD_TESTS=ON -DBUILD_TYPE=Release
  cmake --build .

The resulting `vcd_assert` binary will be in `bin/vcd_assert` in the build directory

Running tests
~~~~~~~~~~~~~
Still inside the build directory

.. code-block:: bash

  ctest
  ctest -R memcheck

Build FAQ:
~~~~~~~~~~
 * To compile with clang you need to using libc++ version 6 or newer
 * Compiling with clang and trying to use libstdc++ triggers `a bug in clang <https://bugs.llvm.org/show_bug.cgi?id=31852>`_

.. _cmake: https://cmake.org/
.. _g++: https://gcc.gnu.org/
.. _clang++: https://clang.llvm.org/
.. _conan: https://conan.io/
.. _PEGTL: https://github.com/taocpp/PEGTL
.. _Range-V3: https://github.com/ericniebler/range-v3
.. _fmt: https://github.com/fmtlib/fmt
.. _Catch2: https://github.com/catchorg/Catch2
.. _CLI11: https://github.com/CLIUtils/CLI11
