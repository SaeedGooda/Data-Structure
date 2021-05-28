#include "BigDecimalInt.h"
#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <string.h>

using namespace std;

BigDecimalInt::~BigDecimalInt()
{
    //dtor
}
BigDecimalInt::BigDecimalInt(string decStr)
{
    if(decStr[0] == '-')                              // sign (-)
    {
        sign = true;                                  // we will store the sign then erase it and store the number in the value
        decStr.erase(0,1);
        value = decStr;
    }
    else if(decStr[0] == '+')                         // sign (+)
    {
        sign = false;                                 // we will store the sign then erase it and store the number in the value
        decStr.erase(0,1);
        value = decStr;
    }
    else                                        // sign (+)
    {
        sign = false;                                 // we will store the number in the value
        value = decStr;
    }
    if(decStr.size()==0)
    {
        value = "0";
        sign = false;
    }
    Size = value.length();
}
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec)
{
    int MAX;
    BigDecimalInt result("");
    if(Size > anotherDec.Size)
    {
        MAX = Size;
        int n_zeros = Size - anotherDec.Size;                   // number of zeros added to the small string to equal the big string
        string a(n_zeros , '0');                                // string that contain the zeros
        anotherDec.value = a + anotherDec.value;                // add the zeros to the small string
    }
    else if(anotherDec.Size > Size)
    {
        MAX = anotherDec.Size;
        int n_zeros = anotherDec.Size - Size;                   // number of zeros added to the small string to equal the big string
        string a(n_zeros , '0');                                // string that contain the zeros
        value = a + value;                                      // add the zeros to the small string
    }
    if (sign==true && anotherDec.sign==true)                    // sign of two numbers (-)
    {
        result.sign = true;
        result.value = add(value,anotherDec.value);          // we will add the two number and make the sign (-)
    }
    else if (sign == true && Size > anotherDec.Size)            // sign of first (-) , second (+) and first size > second size
    {
        result.sign = true;
        result.value = subtract(value,anotherDec.value);     // we will subtract first - second and make sign (-)
    }
    else if (sign == true && Size < anotherDec.Size)            // sign of first (-) , second(+) and first size < second size
    {
        result.sign =false ;
        result.value = subtract(anotherDec.value,value);     // we will subtract second - first and make sign (+)
    }
    else if(anotherDec.sign==true && Size > anotherDec.Size)    // sign of second (-) , first (+) and first size > second size
    {
        result.sign = false;
        result.value =subtract(value,anotherDec.value);      // we will subtract first - second and make sign (+)
    }
    else if(anotherDec.sign==true && Size < anotherDec.Size)    // sign of second (-) , first (+) and first size < second size
    {
        result.sign=true;
        result.value=subtract(anotherDec.value,value);       // we will subtract second - first and make sign (-)
    }
    else if (anotherDec.sign==true && Size ==anotherDec.Size)   // sign of second (-) , first (+) , first size = second size .
    {
        if (value>anotherDec.value)                             //  first value > second value
        {
            result.sign=false;                                  // we will subtract first - second and sign (+)
            result.value=subtract(value,anotherDec.value);
        }
        else                                                    // first value <= second value
        {
            result.sign=true ;
            result.value=subtract(anotherDec.value,value);   // we will subtract second - first and sign (-)
        }
    }
    else                                                        // sign of first and second (+)
    {
        result.sign=false;
        result.value = add(value,anotherDec.value);          // we will add first + second and sign (+)
    }
    result.Size = result.value.size();
    Size = value.size();
    anotherDec.Size = anotherDec.value.size();
    return result;
}

int BigDecimalInt::size()
{
    return Size;
}
string BigDecimalInt::add(string x,string y)
{
    int carry = 0, answer = 0;
    string sum;
    int MAX = x.length();
    for (int i = MAX-1 ; i >=0 ; i--)
    {
        answer = ((x[i] - '0') + (y[i] - '0') + (carry));         // we will add the two number at the same index plus the carry and store it at answer
        if (answer > 9)
        {
            sum += ((answer % 10) + '0');                         // example: 13%10: sum += 3 , carry = 1
            answer /= 10;
            carry = answer;
        }
        else
        {
            carry = 0;
            sum += (answer + '0');
        }
    }
    reverse(sum.begin(),sum.end());                               // we will reverse the sum because we start from right (end)
    if (carry != 0)
        sum = ("1") + sum;
    return sum;
}
string BigDecimalInt::subtract(string x,string y)
{
    int answer = 0 ;
    string sum;
    int MAX = x.length();
    for (int i = MAX-1; i>=0; i--)                                 // we will subtract two numbers of the same index
    {
        if (x[i] < y[i])                                           // if second number > first number , we will borrow and subtract one from the next number
        {
            x[i] += 10;
            x[i-1]--;
        }
        sum+='0' + (x[i] - '0') - (y[i] - '0');
    }

    if (sum.size()>1)
    {
        reverse(sum.begin(),sum.end());                            // we will reverse the sum because we start from right(end)
    }
    return sum;
}
void BigDecimalInt::operator = (BigDecimalInt anotherDec)
{
    value = anotherDec.value;
    Size = anotherDec.Size;
    sign = anotherDec.sign;
}


ostream& operator << (ostream&out,BigDecimalInt &b)
{
    if (b.sign)
    {
        out << "-" << b.value << endl;
    }
    else
    {
        out << b.value << endl;
    }
    return out;
}
