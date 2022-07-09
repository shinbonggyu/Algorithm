#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<string>

#define MAX 100001

using namespace std;

string str, snum="";
bool minus1;
int val;

int main()
{
	cin >> str;

	for (int i = 0; i < str.length()+1; i++)
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
		{
			val += (minus1 ? stoi(snum) * (-1) : stoi(snum));
			snum = "";
			if (str[i] == '-') minus1 = true;
		}
		else
			snum += str[i];
	}
	cout << val;
}