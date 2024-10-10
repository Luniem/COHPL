#include "include/stack.h"

Stack::Stack(int size) {
    _pValues = new int[size];
    _size = size;
}

Stack::~Stack() {
    delete[] _pValues;
}

Stack::Stack(const Stack& other) {
    _pValues = new int[other._size];
    _size = other._size;
    for (int i =0; i < _size; i++) {
        _pValues[i] = other._pValues[i];
    }
}

void Stack::push(int value) {
    return;
}

bool Stack::isEmpty() const {
    return true;
}

Stack* Stack::operator=(const Stack& other)  {
    if(this == &other) {
        return this;
    }

    delete[] _pValues;
    _pValues = new int[other._size];
    _size = other._size;
    for (int i =0; i < _size; i++) {
        _pValues[i] = other._pValues[i];
    }

    return this;
}