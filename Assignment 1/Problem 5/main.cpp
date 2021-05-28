/*
Team members:
    - saeed mohamed Ahmed Gooda    ===> 20180119
    - Ali Mohamed Fathy            ===> 20180167
    - Youssef Bahgt Fekry          ===> 20180339
*/
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;
vector <string> x;
//set <string> y;
void RecPermute(string soFar, string rest)
{
    int h = 0;
    if (rest == ""){
        //x.insert(soFar);
        for(int i = 0 ; i < x.size() ; i++)
        {
            if(soFar != x[i])
            {
                ++h;
            }
        }
        if(h == x.size())
        {
            x.push_back(soFar);
        }
    }
    else{
        for (int i = 0; i < rest.length(); i++){
            string next = soFar + rest[i];
            string remaining = rest.substr(0,i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
    }
}
void ListPermutations(string s) {
    RecPermute("", s);
    for(vector <string>::iterator it = x.begin() ; it != x.end() ; it++){    // by set we will replace vector with set
        cout << *it << endl;
    }
}
int main()
{
    //RecPermute("saeed" , "saad");
    ListPermutations("saad");
    return 0;
}

