#include "include/stack.h"
#include "include/fraction.h"
#include <stdio.h>
#include <iostream>

void baz(Stack& s) {
    s.isEmpty();
    s.push(10);
}

void foo(const Stack& s) {
    printf("foo\n");
    s.isEmpty();
}

int main() {
    // Stack s(10);
    // printf("Hello, World!\n");
    // foo(s);
    // baz(s);
    Fraction f1(51, 21);
    Fraction f2(92, 59);

    Fraction f3 = f1 + f2;

    Fraction f4 = Fraction(2, 4);
    cout << f3 << endl;

    cout << f4 << endl;
    ++f4;
    f4++;
    cout << f4 << endl;
}