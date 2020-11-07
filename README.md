# About mantis
Mantis is a dynamically typed, interpreted programming language inteded to provide multi-precision numerical types as standard types.
The original idea was to make multi-precision arithmetic accessible like built-in types in any programming language. Thus, multi-precision integers, rationals and floats are built-in types in mantis. Besides providing high-level access to multi-precision arithmetics, mantis is too a study in creating a simple and comprehensible scripting language that follows the aesthetics of C-syntax. It provides value-semantics. Those are optimized with parallelization (time) and referencing (space).

![Image of a mantis](https://upload.wikimedia.org/wikipedia/commons/thumb/6/66/Miomantis_paykullii_Luc_Viatour.jpg/347px-Miomantis_paykullii_Luc_Viatour.jpg? "Egyptian Praying Mantis from I, Luc Viatour, CC BY-SA 3.0, https://commons.wikimedia.org/w/index.php?curid=5855103")

# Example
Implementation of the Lucas-Lehmer-Test:
>\> lltest(x) = { var = 4; m = 2\*\*x-1; for i=2; i<x; i=i+1; {var = (var\*\*2 - 2) % m; } return var; }\
>\> lltest(19);\
>0\
>\> lltest(21);\
>840107

# Tutorial
Check out the [tutorial](https://github.com/Markus-Zacharuk/mantis/wiki/Tutorial) in the wiki.

# Installation
Download the [executable](https://github.com/Markus-Zacharuk/mantis/releases/download/v0.1.0-alpha/mantis) (x86-64 linux) and make it executable (`right-click -> permissions -> run as a program`), then open a terminal where the file is and run the programm with `\.mantis`. Install these dependencies if you haven't got them yet: `gmp`, `mpfr`, `lpthread`. On Debian install `libgmp-dev` for `gmp` (`sudo apt-get install libgmp-dev`) and download [this executable](https://github.com/Markus-Zacharuk/mantis/releases/download/v0.1.0-alpha/mantis_static_libstdc++) (or else you might encounter a linker-problem with libstdc++).

The simplest way to build it yourself is:
* Install the dependencies:
  * [GMP](https://gmplib.org/), [MPFR](https://www.mpfr.org/), [MPFR C++](http://www.holoborodko.com/pavel/mpfr/), [boost](https://www.boost.org/)
* Download the project's zip file or clone the project.
* Open a terminal in the projects root folder where you find the file 'makefile'
  * Optionally edit the makefile (e.g. choose your own compiler).
* Type `make` for optimized (-O3) or `make unoptimized` for normal, faster (-O1) compilation.

Now that you have the executable:
* Run the executable by typing `./mantis`

# Acknowledgements
This project is using the following great projects:
* [GMP](https://gmplib.org/) for multi-precision integers and rationals,
* [MPFR](https://www.mpfr.org/) for multi-precision floating-point types,
* [MPFR C++](http://www.holoborodko.com/pavel/mpfr/) to provide c++-style use of [MPFR](https://www.mpfr.org/),
* [boost](https://www.boost.org/) for [recursive variants](https://www.boost.org/doc/libs/1_74_0/doc/html/variant.html) (json-like data-types) and [safe numerics](https://www.boost.org/doc/libs/1_74_0/libs/safe_numerics/doc/html/index.html) (for integer operations (*int64_t*)),
* [flex](https://github.com/westes/flex) for tokenizing (lexical analysis),
* [bison](https://www.gnu.org/software/bison/) for parsing (semantic analysis, parse-tree creation),
* [clang](https://clang.llvm.org/) for compiling,
* [gcc](https://gcc.gnu.org/) for compiling,
* [DOT](http://www.graphviz.org/doc/info/lang.html) for representation and debugging parsing as graphs,
* [xdot](https://github.com/jrfonseca/xdot.py) for viewing these graphs.
