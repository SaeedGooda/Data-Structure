/*
Team members:
    - saeed mohamed Ahmed Gooda    ===> 20180119
    - Ali Mohamed Fathy            ===> 20180167
    - Youssef Bahgt Fekry          ===> 20180339
*/

#include <iostream>

using namespace std;
int power(int a , int n){               //a power n = a * a power (n-1)
    if(n == 0){
        return 1;
    }
    else{
        return a*power(a , n-1);
    }
}

int Power(int a , int n){            //a power n = a power (n/2) * a power(n/2)        n is even
    if(n == 0)                       //a power n = a * a power (n/2) * a power(n/2)    n is odd
        return 1;
    if(n%2 != 0)                      // odd
        return a*Power(a,n/2)*Power(a,n/2);
    else                              // even
        return Power(a,n/2)*power(a,n/2);
}
int main()
{
    // testing first function
    cout << "For first function: " << endl;
    cout << "\tpower(10,3) =  " << power(10,3) << endl;
    cout << "\tpower(3,5)  =  " << power(3,5) << endl;
    cout << "\tpower(4,3)  =  " << power(4,3) << endl << endl;

    // test second function
    cout << "For second function: " << endl;
    cout << "\tpower(2,10) =  " << power(2,10) << endl;
    cout << "\tpower(6,3)  =  " << power(6,3) << endl;
    cout << "\tpower(2,5)  =  " << power(2,5) << endl;
    return 0;
}
