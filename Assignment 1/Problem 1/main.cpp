#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <string.h>
#include <BigDecimalInt.h>

using namespace std;

int main()
{
    BigDecimalInt num1("-123");
    BigDecimalInt num2("111");
    BigDecimalInt num3 = num2 + num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << num3 << endl;
    return 0;
}
