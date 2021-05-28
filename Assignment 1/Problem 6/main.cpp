/*
Team members:
    - saeed mohamed Ahmed Gooda    ===> 20180119
    - Ali Mohamed Fathy            ===> 20180167
    - Youssef Bahgt Fekry          ===> 20180339
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StudentName{
private:
    string Name;
public:
    StudentName(string n){
        int spaces = 0;                 // number of spaces
        Name = n;
        int len = Name.length();        // name length
        int j;                          // variable to know index of first space
        for(int i = 0 ; i < len ; i++){
            if(Name[i] == ' '){
                ++spaces;
                j = i;                  // set index of first space at variable j
            }
        }
        if(spaces == 0){
            Name += " ";
            string k = Name;
            Name += k;
            Name += k;
        }
        else if(spaces == 1){
            Name += " ";
            for(int i = 0 ; i < len-j-1 ; i++){
                Name += Name[j+1+i];
            }
        }
    }
    void print()
    {
        vector <string> names;
        string n = "";                            // variable use to divide the string by these spaces
        for(int i = 0; i < Name.length(); i++)
        {
            if (Name[i]==' ')
            {
                names.push_back(n);
                n = "";
            }
            else if(i == Name.length()-1)
            {
                n += Name[i];
                names.push_back(n);
            }
            else
                n += Name[i];
        }
        int u = 1;
        for(int i = 0; i < names.size() ; i++)
        {
            cout << u << ") " << names[i] << endl;
            ++u;
        }
    }
    bool replace(int i,int j)
    {
        vector <string> names;
        string n = "";                            // variable use to divide the string by these spaces
        for(int i = 0; i < Name.length(); i++)
        {
            if (Name[i]==' ')
            {
                names.push_back(n);
                n = "";
            }
            else if(i == Name.length()-1)
            {
                n += Name[i];
                names.push_back(n);
            }
            else
                n += Name[i];
        }
        if(i > names.size() || j > names.size())
        {
            return false;
        }
        else
        {
            string temp = names[j-1];                      // temp to replace the two names at vector
            names[j-1] = names[i-1];
            names[i-1] = temp;
            string take_name;
            for(int i = 0 ; i < names.size() ; i++)
            {
                take_name += names[i] + " ";                      // take all name from vector and then put it at variable Name
            }
            Name = take_name;
            return true;
        }
    }
};

int main()
{
    StudentName st("saeed");
    st.print();
    st.replace(1 , 3);
    cout << "After replace" << endl;
    st.print();
    cout << endl;

    StudentName s("saeed mohamed");
    s.print();
    s.replace(1 , 2);
    cout << "After replace" << endl;
    s.print();
    cout << endl;

    StudentName stu("saeed mohamed ahmed");
    stu.print();
    stu.replace(1 , 3);
    cout << "After replace" << endl;
    stu.print();
    return 0;
}
