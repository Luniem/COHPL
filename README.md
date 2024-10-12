# COHPL :space_invader:

This repository is used for all exercises in the course “Concepts of Higher Programming Languages”.
The project contains a user-defined debug configuration, which automatically builds the executable and attaches a debugger.

## Exercises

- Minimalistic memory-management implementation

### Minimalistic memory-management implementation :dizzy:

Created a own small implementation of the C-functionality to allocate memory on the heap.

Main part of the impl. is a library that provides following functions:

- void\* mem_malloc(uint16_t size); | Allocates {size} bytes on the 'heap'
- void mem_free(void\* addr); | Free the memory of the given address

## Use CMake to build executables

This project features a CMake-File that builds executables for all exercises contained.
