# MiniLibC
A short and simple implementation of C standard library in x86-64 assembly.

## Build
```
make
```

## Tests
```
make tests_run
```

## Usage
```
LD_PRELOAD=$PWD/libasm.so [your_command]
```
Of course, you have to replace `[your_command]` by the command of your choice.
