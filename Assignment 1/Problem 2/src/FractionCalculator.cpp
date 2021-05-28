#include "FractionCalculator.h"
#include <iostream>
#include <Fraction.h>
using namespace std;

FractionCalculator::FractionCalculator()
{
    //ctor
}

FractionCalculator::~FractionCalculator()
{
    //dtor
}
void FractionCalculator::calculator()
{
    cout << "\t\t************************************************" << endl;
    cout << "\t\t\tWelcome to our fraction calculator: " << endl;
    cout << "\t\t************************************************" << endl;
    cout << "Please enter the first fraction" << endl;
    Fraction f1;
    cin >> f1;
    cout << "Please enter the second fraction" << endl;
    while(true)
    {
        Fraction f2;
        cin >> f2;
        cout << "Please choose from the following" << endl;
        cout << "\t1-Adding" << endl;
        cout << "\t2-subtracting" << endl;
        cout << "\t3-multiplication" << endl;
        cout << "\t4-dividing" << endl;
        cout << "\t5-exit" << endl;
        int choose;
        cin >> choose;
        if(choose == 1)
        {
            cout << "The sum : " << f1+f2 << endl;
        }
        else if(choose == 2)
        {
        cout << "The subtraction: " << f1-f2 << endl;
        }
        else if(choose == 3)
        {
            cout << "The multiplication: " << f1*f2 << endl;
        }
        else if(choose == 4)
        {
            cout << "The division: " << f1/f2 << endl;
        }
        else if(choose == 5)
        {
            cout << "\t\tThank you for using my application" << endl;
        }
    }
}
