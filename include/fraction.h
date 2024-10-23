#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <iostream>
using namespace std;

class Fraction
{
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);

private:
    int _numerator;
    int _denominator;

public:
    Fraction(int numerator, int denominator);
    Fraction(float value);

    void reduce();

    operator double() const;

    Fraction operator+(Fraction &other) const;
    string toString() const;

    Fraction operator++();
};

Fraction operator+(const Fraction &f1, const Fraction &f2);
ostream &operator<<(ostream &os, const Fraction &f);
#endif