# Project 3 - Assembly Exercises

## Overview
This project is a collection of small C programs that use inline x86-64 assembly to solve specific low-level programming tasks. Each file focuses on a different concept such as register manipulation, arithmetic, function calls, memory handling, loop control, and pointers.

## Files
- `one.c` - Sets three variables to target values using inline assembly.
- `two.c` - Returns the square of an input value using assembly instructions.
- `three.c` - Uses an assembly loop to create a long-running timed section.
- `four.c` - Changes program state with assembly so the success condition is reached early.
- `five.c` - Demonstrates early program exit or control flow disruption with assembly.
- `six.c` - Works with integer limits and value handling at the register level.
- `seven.c` - Stores character data inside an integer and treats that memory as a string.
- `eight.c` - Calls a function with the correct parameter using inline assembly.
- `nine.c` - Updates a global counter during a loop using assembly.
- `ten.c` - Stores and compares the address of `main` using function pointers.

## Concepts Used
- Inline assembly in C
- Registers and memory operands
- Function calls and stack behavior
- Control flow and looping
- Pointers and raw memory access

## How to Run
Compile any file individually with GCC, for example:

```bash
gcc one.c -o one
./one
```

Repeat the same pattern for any of the other exercise files.

## Notes
These programs were built as assembly practice exercises, so each file is intentionally small and focused on one concept.
