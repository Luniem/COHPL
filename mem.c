#include "include/mem.h"

typedef struct
{
    uint8_t flag;
    uint8_t rfu;
    uint16_t len;
} mem_header_t;

static uint8_t gHeap[HEAP_SIZE] = {FREE, 0x0, HIGH_BYTE(HEAP_SIZE), LOW_BYTE(HEAP_SIZE)};

// header
void *mem_malloc(uint16_t size)
{
    // search for free memory -> start at the beginning
    uint8_t *ptr = gHeap;

    // loop over until we find free space or reach the end of the heap
    while (ptr < gHeap + HEAP_SIZE)
    {
        mem_header_t *mem_header = (mem_header_t *)ptr;

        if (!mem_header->flag && mem_header->len >= size)
        {
            // save remaining length before overwritting the header
            uint16_t remaining_length = mem_header->len - size;

            // found! allocate memory
            mem_header->flag = OCCUPIED;
            mem_header->len = size;

            // check if there is enough space to create a new free block
            // if not we either should have another block that should have a free block defined or we reached end of heap
            if (remaining_length > sizeof(mem_header_t))
            {
                mem_header_t *new_header = (mem_header_t *)(ptr + sizeof(mem_header_t) + size);
                new_header->flag = FREE;
                new_header->rfu = 0;
                new_header->len = remaining_length - sizeof(mem_header_t);
            }

            // void pointer to the data-segment of the allocated mem-block
            return (void *)(ptr + sizeof(mem_header_t));
        }

        // replace pointer to the next mem-block after the current one
        ptr += sizeof(mem_header_t) + mem_header->len;
    }

    // we found no fitting block => perhaps exception? Out of memory?
    return NULL;
}

void mem_free(void *addr)
{
    // get the header of the block
    mem_header_t *mem_header = (mem_header_t *)((uint8_t *)addr - sizeof(mem_header_t));

    // free the block
    mem_header->flag = FREE;
}