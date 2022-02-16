
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s= "1010";
    int n=s.size();
    int one=0,zero=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1')
        one++;
        else if(s[i]=='0') zero++;
    }

    cout<<"no of ones are : "<<one<<endl;
    cout<<"no of zeros are : "<<zero<<endl;

    int win_size=2;
    int count;
    
    for (int i = 0; i < n; i++)
    {
        if((win_size + i) < n)// it give no of windows
        count++;
    }

    cout<<"no of windows formed are  : "<<count<<endl;

    cout<<s<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < win_size; j++)
        {
            
        }
        
    }
    

    return 0;

}