#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{

    ifstream read;
    read.open("test.csv");

    int csv_size = -1;
    while (read.good())
    {
        string s1;
        read >> s1;
        csv_size++;
    }

    read.close();

    read.open("test.csv");
    string s = ""; // main string

    while (read.good())
    {
        string s2;
        s2.clear();
        read >> s2;
        s += s2;
    }
    read.close();

    int n = s.size();
    cout << "size of string is : " << n << endl;

    int win_size = n - 99;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if ((win_size + i) <= n)
            count++; // it give no of windows
    }

    cout << "no of windows formed are  : " << count << endl;

    // cout<<s<<endl;
    // int coun1=0;
    double arr[count] = {0}; // for storing

    int q = 2;

    while (q <= 4)
    {
        for (int i = 0; i < count; i++)
        {
            int k = 0;
            double count_zero = 0;
            double count_one = 0;
            string s1 = s.substr(i);

            for (int j = 0; j < win_size; j++)
            {

                s1 = s1.substr(k, win_size);
                k = 1;

                if (s1[0] == '1')
                    count_one++;

                if (s1[0] == '0')
                    count_zero++;

                if (j == (win_size - 1))
                {

                    double prob0 = 0;
                    double prob1 = 0;
                    double prob = 0;
                    double tsallis = 0;

                    prob0 = pow(count_zero / win_size, q);
                    prob1 = pow(count_one / win_size, q);
                    prob += prob0 + prob1;

                    tsallis = ((1 - prob) / (q - 1));

                    arr[i] = tsallis;
                }
            }
        }
        ofstream wrt;
        wrt.open("output.csv", ios::app);
        wrt << endl
            << endl
            << "For q= " << q << endl
            << endl;
        for (int i = 0; i < count; i++)
        {
            wrt << "Entropy " << i + 1 << ": " << arr[i] << endl;
        }

        q++;
    }

    return 0;
}