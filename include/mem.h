#ifndef MEM_H
#define MEM_H

#include <stdlib.h>
#include <inttypes.h>

#ifndef HEAP_SIZE
#define HEAP_SIZE 1024
#endif

#define FREE 0
#define OCCUPIED 1

void* mem_malloc(uint16_t size);

void mem_free(void* addr);

#endif

