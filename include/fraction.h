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
        Fraction operator+(Fraction& other) const;
        void reduce();
        string toString() const;
};

Fraction operator+(const Fraction& f1, const Fraction& f2);
#endif