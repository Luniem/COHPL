#ifndef MEM_H
#define MEM_H

#include <stdlib.h>
#include <inttypes.h>

#ifndef HEAP_SIZE
#define HEAP_SIZE 1024
#endif

#define HIGH_BYTE(x) ((uint8_t)((x) >> 8))
#define LOW_BYTE(x) ((uint8_t)((x) & 0xFF))

#define FREE 0
#define OCCUPIED 1

void *mem_malloc(uint16_t size);

void mem_free(void *addr);

#endif
