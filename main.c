#include <stdio.h>
#include <inttypes.h>
#include "include/mem.h"

int sum(int a, int b) {
    return a + b;
}

int main(int argc, char** argv) {    
    int64_t i = 0;
    int8_t* pointer;

    int64_t* pointers[1000];

    do {
        pointer = (int8_t*) mem_malloc(sizeof(int8_t));
        if(pointer != NULL) {
            *pointer = 1;
            pointers[i] = pointer;
        }

        i++;
    } while(pointer != NULL);

    for (int y = 0; y < i -1; y++) {
        mem_free(pointers[y]);
    }

    return 0;
}