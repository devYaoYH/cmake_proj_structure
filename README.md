# CMake C project structure

Hierarchical modular project structure for C project based on [samwise-flight-software](https://github.com/stanford-ssi/samwise-flight-software).

Testing is much easier after this refactoring.

Common struct declarations are in `src/common` and the following makes clear the dependencies between modules:

```
[module --> dependencies]

scheduler --> states/init

states/init --> tasks/print

main.c --> scheduler
       --> slate.h
```

Testing is possible per-module:

```
tasks/print/test --> tasks/print
```
