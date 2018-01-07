# Lithe
A minimal C++ engine that handles asset loading/management, state transition/management and a basic, yet efficient ECS implementation.

## Prerequisites
You will need the following programs installed in order to compile & run the project:
> Note: These are the programs _I_ used so it's possible you may be able to proceed on different versions.
- CMake >= 2.8
- GCC >= 7.2.1

## Compilation
In order to compile the project, perform the following steps:
- Create a directory called build and `cd` into it.
- Run the command `cmake ..` to create the Makefile.
- Then, run `make` whenever you wish to recompile the program.
- To launch the produced executable, run `./lithe` after compilation.