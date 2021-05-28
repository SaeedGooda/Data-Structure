#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include<iostream>
using namespace std;

class BigDecimalInt
{
    public:
        BigDecimalInt(string decStr);
        BigDecimalInt operator+ (BigDecimalInt anotherDec);
        int size();
        string add(string a,string b);
        string subtract(string a,string b);
        void operator= (BigDecimalInt anotherDec);
        friend ostream& operator << (ostream& out, BigDecimalInt &b);
        virtual ~BigDecimalInt();
    protected:

    private:
        string value;
        bool sign;                 // true for (-) and false for (+)
        int Size;
};

#endif // BIGDECIMALINT_H

