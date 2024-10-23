#include "include/stack.h"
#include "include/fraction.h"
#include "include/smart_pointer.h"
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
    // Fraction f1(51, 21);
    // Fraction f2(92, 59);

    // Fraction f3 = f1 + f2;

    // cout << f3 << endl;
    Fraction* f1 = new Fraction(1,2);
    FractionSmartPointer* sp1 = new FractionSmartPointer(f1);

    Fraction& f2 = sp1->operator*();
    delete &f2;
    cout << "Fraction should still be here" << endl;
}