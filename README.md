# Lispy stuff

Simple lisp-ish language compiler written in C++.

Right now it doesn't compile much - it's just a parser.
The goal is to emit bytecode. The bytecode format is not decided yet.

## Build

I use cmake for the build system. I prefer to build out-of-tree,
here's how to build if you've never used cmake:

```bash
cd build
cmake ..
make
```

## Development

I use clangd as the language server. Appropriate `compile_commands.json`
(required for clangd, otherwise it can not find include files) is provided.
If you'd like to generate them yourself, just use cmake:

```bash
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
cp compile_commands.json ../
```


