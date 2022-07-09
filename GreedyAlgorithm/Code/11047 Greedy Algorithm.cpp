#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 100001

using namespace std;

int N, K, A, Count = 0;
vector <int> Money;

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		Money.push_back(A);
	}

	for (int i = 0; i < N; i++)
	{
		if (K / Money.at(N - i - 1) != 0)
		{
			Count += K / Money.at(N - i - 1);
			K = K % Money.at(N - i - 1);
		}
	}

	cout << Count;
}