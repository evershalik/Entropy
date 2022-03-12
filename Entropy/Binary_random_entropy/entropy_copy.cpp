#include <bits/stdc++.h>
#include <fstream>

using namespace std;

double shannonEntropy(double frequency, double size)
{
    double sEntropy = -((frequency / size) * log2(frequency / size));
    return sEntropy;
}

double tsallisEntropy(double freq, double size, double q)
{
    double prob = pow((freq / size), q);
    double tEntropy = ((1 - prob) / (q - 1));
    return tEntropy;
}

void frequency(vector<string> arr)
{
    int n = arr.size();
    map<string, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    ofstream write;
    write.open("output.csv");
    write << "\n\n------------SHANNON ENTROPY---------------\n\n";
    for (const auto &elm : freq)
    {
        // cout << "freq of " << elm.first << " is : " << elm.second << endl;
        write << "Shannon entropy of " << elm.first << " is : " << shannonEntropy(elm.second, n) << endl;
    }
    write << "\n\n------------------------------------------\n\n";
    write << "\n\n------------TSALLIS ENTROPY---------------\n\n";
    for (const auto &elm : freq)
    {

        int q = 2;
        while (q < 5)
        {
            // cout << "freq of " << elm.first << " is : " << elm.second << endl;
            write << "Tsallis entropy of " << elm.first << " for q = " << q << " is : " << tsallisEntropy(elm.second, n, q) << endl;
            q++;
        }
        write << endl;
    }
}

int main()
{
    ifstream read;
    read.open("test.csv");

    string s1;
    vector<string> arr;
    while (read.good())
    {
        getline(read, s1);
        arr.push_back(s1);
    }
    read.close();

    frequency(arr);

    return 0;
}