#include "include/smart_pointer.h"


//constructor
FractionSmartPointer::FractionSmartPointer(Fraction* ptr) {
    // when constructing, set ptr to the given pointer and ref_count to 1
    this->ptr = ptr;
    ref_count = 1;
}

//copy constructor
FractionSmartPointer::FractionSmartPointer(const FractionSmartPointer& other) {
    // when copying, we set the same pointer and coppy the ref_count
    ptr = other.ptr;
    ref_count = other.ref_count;
    ++ref_count;
}

//destructor
FractionSmartPointer::~FractionSmartPointer() {
    ref_count--;
    if (ref_count == 0) {
        delete ptr;
    }
}

//assignment operator
FractionSmartPointer& FractionSmartPointer::operator=(const FractionSmartPointer& other) {
    if (ptr == other.ptr) {
        return *this;
    }

    // set the ref_count down for own reference
    ref_count--;

    // when it was the last reference -> free memory for ptr and ref_count
    if (ref_count == 0) {
        delete ptr;
    }

    // set the new values
    ptr = other.ptr;
    ref_count = other.ref_count;
    ref_count++;

    return *this;
}

//dereference operator
Fraction& FractionSmartPointer::operator*() const {
    return *ptr;
}

Fraction& FractionSmartPointer::operator->() const {
    return *ptr;
}