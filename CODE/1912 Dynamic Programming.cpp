#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 100001

using namespace std;

int N;
int dp[MAX];
int Arr[MAX];
int maxx;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}

	dp[0] = Arr[0];
	maxx = Arr[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = max(Arr[i] + dp[i - 1], Arr[i]);
		maxx = max(dp[i], maxx);
	}
	cout <<maxx;
}