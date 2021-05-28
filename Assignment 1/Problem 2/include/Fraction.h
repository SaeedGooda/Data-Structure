#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;
class Fraction
{
    public:
        Fraction();
        Fraction(int x , int y);
        Fraction operator+(Fraction f);
        Fraction operator-(Fraction f);
        Fraction operator*(Fraction f);
        Fraction operator/(Fraction f);
        bool operator > (Fraction f);
        bool operator < (Fraction f);
        bool operator >= (Fraction f);
        bool operator <= (Fraction f);
        bool operator == (Fraction f);
        int help_for_reduce(int num , int den);
        void reduce();
        friend istream & operator >> (istream & in , Fraction & f);
        friend ostream & operator << (ostream & out , Fraction  f);
        virtual ~Fraction();

    protected:

    private:
        int num , den;       // num for Numerator and den for denominator

};

#endif // FRACTION_H
