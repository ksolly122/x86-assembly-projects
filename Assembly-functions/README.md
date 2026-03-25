# Project 4 - Assembly Function Implementations

## Overview
This project implements several required functions in x86-64 assembly and tests them from a C driver program. The goal is to show how assembly can work directly with C code, function arguments, strings, linked structures, and return values.

## Files
- `project4.s` - Assembly implementations of the required functions.
- `p4test.c` - Test driver that builds sample data and checks each function.

## Implemented Functions
- `print_bugs(void*)` - Walks through a linked list of bug names and prints each one.
- `halves_to_100(double)` - Returns how many times a value can be halved before it drops below 100.
- `return_five_returner()` - Returns the address of a function that returns the integer `5`.
- `space_to_underscore(char*)` - Replaces spaces in a string with underscores in place.

## Concepts Used
- Calling conventions between C and assembly
- Linked list traversal
- String editing in memory
- Function pointers
- Basic arithmetic and loop logic in assembly

## How to Build
Compile and link the C test file with the assembly file:

```bash
gcc -no-pie p4test.c project4.s -o project4
./project4
```

## Notes
This project is a good example of mixing C and assembly in the same program and verifying low-level functions through a higher-level test harness.
