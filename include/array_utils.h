#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

int ascending(int a, int b);
int descending(int a, int b);

void bubble_sort(int arr[], int n, int (*compare)(int, int));

void for_each(int arr[], int n, void (*task)(int));
#endif