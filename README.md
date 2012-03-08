Mappings
--------
Four C++ abstract base classes are provided for the purpose of subclassing.
The four types cover autonomous/non-autonomous exogenous/endogenous systems.
This is a pure header library.

Build System
------------
CMake is required to build the example and install the header file (though you
could do this manually pretty easily).  To configure the build, do

  $ mkdir build
  $ cd build

Then, you can either do:

  $ cmake ../

which will select default install paths and won't enable the documentation.
Or, you can do

  $ cmake-gui ../

which will give you a friendly GUI to configure build and installation options.
Once that is done, you can build the example with

  $ make

and install with

  $ make install

Depending on your selected install prefix (/usr/local by default), you made
need root priviledges.

Documentation
-------------
If you enabled the documentation in the CMake configuration (cmake
-DBUILD_DOC=1 ../), you can build the documentation if you have doxygen
installed, simply type

   $ make doc
