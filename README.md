# Lispy stuff

Simple lisp-ish language compiler written in C++.

Right now it doesn't compile much - it's just a parser.
The end goal is to emit bytecode. The bytecode format is not decided yet.

## Build

All you need is:

- CMake
- A modern C++ compiler
- The [Catch2](https://github.com/catchorg/Catch2) library v3 or higher installed on your system

Once you have these, you can build with:

```bash
cd build
cmake ..
make
```

This will build two executables, `main` and `test`. `test` runs all tests
on the compiler itself.

## Development

I use clangd as the language server. If you want your include files to be handled
correctly, you'll need to generate `compile_commands.json` yourself. You can
do this using cmake:

```bash
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
cp compile_commands.json ../
```

After this, clangd should not give you errors on every included header.

### Toolchain

C++ can be somewhat error-prone, so in order to reduce the possibility of
certain bugs, cmake toolchain options are provided that build the project
with the undefined behaviour sanitizer and the address sanitizer.

You can build a sanitized version like this:

```
cd build
cmake .. --toolchain ../toolchain/sanitize.cmake
make
```

Catch2 testing framework is used to maintain code correctness.


## Progress

Woodpecker CI/CD system is integrated.
Currently using Catch2 for unit testing.

- Lexing - complete, more token types may be added as necessary
- Parsing - the main steps are done, but things may change as time progresses
- Optimizations - 
- Emitting Bytecode - the goal.

