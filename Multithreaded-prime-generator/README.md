# Project 5 - Multithreaded Prime Generator

## Overview
This project is a C program that uses POSIX threads to search for prime numbers in parallel. It stores discovered prime values in a shared array and uses a mutex to protect updates while multiple threads are running.

## File
- `prime_generator.c` - Main source file for the threaded prime number generator.

## What It Does
- Accepts the number of threads as a command-line argument
- Splits work across threads
- Checks whether values are prime
- Stores primes in a shared global array
- Prints selected prime values after all threads finish

## Concepts Used
- C programming
- POSIX threads (`pthread`)
- Mutex locking for shared data
- Prime number checking
- Parallel work distribution

## How to Build
Compile with pthread support:

```bash
gcc prime_generator.c -o prime_generator -pthread
./prime_generator 4
```

The example above runs the program with 4 threads.

## Notes
This project focuses on threading and synchronization. It is a class project and can be used as an example of basic parallel programming in C.
