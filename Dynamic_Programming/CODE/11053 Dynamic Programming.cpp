#include<iostream>
#include<queue>
#include<stdio.h>

#define MAX 1001
using namespace std;

int N;
int A[MAX], DP[MAX];

int main()
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		DP[i] = 1;
	}
	

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (A[j] < A[i] && DP[j] >= DP[i])
			{
				DP[i] = DP[j] + 1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (max < DP[i])
			max = DP[i];
	}
	cout << max << endl;
	return 0;
}