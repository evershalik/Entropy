// occurence 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s ;//= "1001100110011111";
    getline(cin,s,';');
    cin.ignore();
	string ch ;//= "111"; 
    getline(cin,ch,';');
    cin.ignore();
	int freq = 0;

	for (int i = 0; i < s.size(); i++)
	{
		int j;
		for (j = 0; j < ch.size(); j++)
		{
			if (s[i+j] != ch[j])
			{
				break;
			}
		}

			if (j == ch.size())
			{
				freq++;
			}
		
	}

	cout << freq;


	return 0;
}
