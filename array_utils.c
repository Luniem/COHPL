#include "include/array_utils.h"

int ascending(int a, int b) {
    return a - b;
}

int descending(int a, int b) {
    return b - a;
}

void bubble_sort(int arr[], int n, int (*compare)(int, int)) {
    for (int i = 0; i < n-1; i++) {
        for (int y = 0; y < n-i-1; y++) {

            if(compare(arr[y], arr[y+1]) > 0) {
                int temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
}

void for_each(int arr[], int n, void (*task)(int)) {
    //for ;
    for (int i = 0; i < n; i++) {
        task(arr[i]);
    }
}