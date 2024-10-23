#include "include/fraction.h"
#include "include/utils.h"

Fraction::Fraction(int numerator = 0, int denominator = 1)
{
    _numerator = numerator;
    _denominator = denominator;
    reduce();
}

Fraction::Fraction(float value)
{
    _numerator = value * 100;
    _denominator = 100;
}

void Fraction::reduce()
{
    int deno = gcd(_numerator, _denominator);
    _numerator /= deno;
    _denominator /= deno;
}

Fraction Fraction::operator+(Fraction &other) const
{
    int new_denominator = lcm(_denominator, other._denominator);
    int new_numerator = _numerator * (new_denominator / _denominator) + other._numerator * (new_denominator / other._denominator);
    return Fraction(new_numerator, new_denominator);
}

string Fraction::toString() const
{
    return "[" + to_string(_numerator) + "/" + to_string(_denominator) + "]";
}

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    int new_denominator = lcm(f1._denominator, f2._denominator);
    int new_numerator = f1._numerator * (new_denominator / f1._denominator) + f2._numerator * (new_denominator / f2._denominator);
    return Fraction(new_numerator, new_denominator);
}

Fraction::operator double() const
{
    return (double)_numerator / _denominator;
}

Fraction Fraction::operator++()
{
    _numerator += _denominator;
    return *this;
}

ostream &operator<<(ostream &os, const Fraction &f)
{
    os << f.toString();
    return os;
}