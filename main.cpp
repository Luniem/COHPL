#include <stdio.h>
#include "include/stack.h"

void baz(Stack& s) {
    s.isEmpty();
    s.push(10);
}

void foo(const Stack& s) {
    printf("foo\n");
    s.isEmpty();
}

int main() {
    Stack s(10);
    printf("Hello, World!\n");
}