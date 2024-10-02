#include <stdio.h>
#include <inttypes.h>
#include "include/mem.h"
#include "include/array_utils.h"

void printValue(int i) {
        printf("%d ", i); 
}

// mem_alloc program 
void test_mem_alloc() {
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

    pointer = (int8_t*)mem_malloc(sizeof(int16_t));
    
    //TODO: fix this, free'd memory should check next header for available merge
    if(pointer == NULL) {
        printf("Failed to allocate memory\n\n");
    } else {
        printf("Everything worked!");
    }
}

// array_utils test
void test_array_utils() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted: ");
    for_each(arr, n, printValue);

    bubble_sort(arr, n, ascending);
    printf("\n\nSorted ascending: ");
    for_each(arr, n, printValue);                                                                                                                     

    bubble_sort(arr, n, descending);
    printf("\n\nSorted descending: ");
    for_each(arr, n, printValue);
}

int main(int argc, char** argv) {    
    test_mem_alloc();
    test_array_utils();
 

    return 0;
}