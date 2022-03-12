#include <bits/stdc++.h>
#include<fstream>

using namespace std;

int main()
{
    ifstream read;
    read.open("test.csv");

    int csv_size = -1;
    while (read.good())
    {
        string s1;
        read>>s1;
        csv_size++;
    }

    read.close();

    // cout<<"size of csv file is : "<<csv_size<<endl;


    read.open("test.csv");
    string s=""; //main string

    while (read.good())
    {
        string s2;
        s2.clear();
        read>>s2;
        s += s2;
    }
    // cout<<"sting s is : "<<s<<endl;
    read.close();

    int n=s.size();
    cout<<"size of string is : "<<n<<endl;
   
    /*
    int one=0,zero=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1')
        one++;
        else if(s[i]=='0') zero++;
    }
    */

    // cout<<"no of ones are : "<<one<<endl;
    // cout<<"no of zeros are : "<<zero<<endl;

    int win_size= n-99;
    // cout<<"Enter size of window : "; cin>>win_size;
    int count=0;
    
    for (int i = 0; i < n; i++)
    {
        if((win_size + i) <= n) // it give no of windows
        count++;
    }

    cout<<"no of windows formed are  : "<<count<<endl;

    // cout<<s<<endl;
    // int coun1=0;
    double arr[count]={0};
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
                
                double entropy = ( -((temp_count / win_size) * log2f(temp_count / win_size)));
                // cout<<"entropy "<<i+1<<": "<< entropy <<endl;
                arr[i]=entropy;
                
                
                
            }

            

        }
        
    }
    // cout<<"\n--------------\n";
    // for (int i = 0; i < count; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }

    ofstream wrt;
    wrt.open("output.csv");
    for (int i = 0; i < count; i++)
    {
        wrt <<"Entropy "<<i+1<<": "<< arr[i] <<endl;
    }
    
    
    

    


    

    return 0;

}