#include "Fraction.h"
#include <iostream>
using namespace std;
Fraction::Fraction()
{
    num = 0;
    den = 1;
}

Fraction::~Fraction()
{
    //dtor
    //dtor
}

Fraction::Fraction(int x , int y)
{
        num = x;
        den = y;
}
Fraction Fraction::operator+(Fraction f)
{
    num = num*f.den + f.num*den;
    den = den * f.den;
    return *this;
}
Fraction Fraction::operator-(Fraction f)
{
    num = num*f.den - f.num*den;
    den = den * f.den;
    return *this;
}
Fraction Fraction::operator*(Fraction f)
{
    num = num*f.num;
    den = den*f.den;
    return *this;
}
Fraction Fraction::operator/(Fraction f)
{
    num = num*f.den;
    den = den*f.num;
    return *this;
}
bool Fraction::operator > (Fraction f)
{
    if((double)num/den > (double)f.num/f.den)
        return true ;
    else
        return false;
}
bool Fraction::operator < (Fraction f)
{
    if((double)num/den < (double)f.num/f.den)
        return true;
    else
        return false;
}
bool Fraction::operator >= (Fraction f)
{
    if((double)num/den >= (double)f.num/f.den)
        return true ;
    else
        return false;
}
bool Fraction::operator <= (Fraction f)
{
    if((double)num/den <= (double)f.num/f.den)
        return true;
    else
        return false;
}
bool Fraction::operator == (Fraction f)
{
    if((double)num/den == (double)f.num/f.den)
        return true;
    else
        return false;
}
int Fraction::help_for_reduce(int num , int den)
{
    if(den == 0)
        return num;
    else
        help_for_reduce(den , num % den);
}
void Fraction::reduce()
{
    int f = help_for_reduce(num , den);
    num /= f;
    den /= f;
}
istream & operator >> (istream & in , Fraction & f)
{
    cout << "enter Numerator : ";
    in >> f.num;
    cout << "enter Denominator : ";
    in >> f.den;
    return in;
}
ostream & operator << (ostream & out , Fraction  f)
{
    if (f.den==0)
        out << "you can't divide by 0" << endl;
    else if (f.num==0)
        out << 0 << endl;
    else if (f.den==f.num)
        out << 1 << endl;
    else
        out << f.num <<'/'<< f.den;
    return out;
}
