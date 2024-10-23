#ifndef SMART_POINTER_H
#define SMART_POINTER_H
#include "fraction.h"

class FractionSmartPointer {
    private:
        Fraction* ptr;
        int ref_count;

    public:
        FractionSmartPointer(Fraction* ptr);

        FractionSmartPointer(const FractionSmartPointer& other);

        ~FractionSmartPointer();

        FractionSmartPointer& operator=(const FractionSmartPointer& other);

        Fraction& operator*() const;

        Fraction& operator->() const;
};

#endif