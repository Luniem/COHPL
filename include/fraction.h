#ifndef FRACTION_H
#define FRACTION_H
#include <string>
using namespace std;

class Fraction {
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);

    private:
        int _numerator;
        int _denominator;
    
    public:
        Fraction(int numerator, int denominator);
        Fraction(float value);

        void reduce();

        operator double() const;

        Fraction operator+(Fraction& other) const;
        Fraction& operator++();
        Fraction operator++(int);
        string toString() const;
};

Fraction operator+(const Fraction& f1, const Fraction& f2);
ostream& operator<<(ostream& os, const Fraction& f);
#endif