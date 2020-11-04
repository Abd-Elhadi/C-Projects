#ifndef FRACTION_H
#define FRACTION_H
#include <bits/stdc++.h>
using namespace std;


class Fraction{
public:
    Fraction();
    Fraction (int _nominator, int _denominator);
    Fraction addition(Fraction &another);
    Fraction subraction(Fraction &another);
    Fraction division(Fraction &another);
    Fraction multiplication(Fraction &another);
    int fractionReducer(int fnumber, int snumber);

    bool operator > (Fraction& another);
    bool operator < (Fraction& another);
    bool operator >= (Fraction& another);
    bool operator <= (Fraction& another);
    bool operator == (Fraction& another);

    friend istream& operator >>(istream& input, Fraction& another);
    friend ostream& operator <<(ostream& output, const Fraction& another);

private:
    int nominator, denominator;
};
#endif // FRACTION_H
