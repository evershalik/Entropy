#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cout<<"Enter your binary string : "; cin>>s;
    int n=s.size();
    int one=0,zero=0;
   
    /*
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1')
        one++;
        else if(s[i]=='0') zero++;
    }
    */

    // cout<<"no of ones are : "<<one<<endl;
    // cout<<"no of zeros are : "<<zero<<endl;

    int win_size=2;
    cout<<"Enter size of window : "; cin>>win_size;
    int count=0;
    
    for (int i = 0; i < n; i++)
    {
        if((win_size + i) <= n) // it give no of windows
        count++;
    }

    cout<<"no of windows formed are  : "<<count<<endl;

    // cout<<s<<endl;
    // int coun1=0;

    for (int i = 0; i < count; i++)
    {
        int k=0;
        double temp_count=0;
        string s1=s.substr(i);
        // cout<<" new string s1 is : "<<s1<<endl;

        for (int  j = 0; j < win_size; j++)
        {
            
            s1=s1.substr(k,win_size);
            k=1;
            // cout<<s1<<endl;
            if(s1[0]=='1')
            temp_count++;
            // cout<<"size of temp_count is : "<<temp_count<<endl;
            
      
            if(j==(win_size-1))
            {
                 // cout<<"s1 is empty "<<endl;
                double entropy = ( -((temp_count / n) * log2f(temp_count / n)));
                cout<<"entropy "<<i<<": "<< entropy <<endl;
            }

            

        }
        
    }
    

    return 0;

}