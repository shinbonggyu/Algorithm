#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 10001

using namespace std;

int N;
int dp[MAX];
int Arr[MAX];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	dp[0] = Arr[0];
	dp[1] = Arr[0] + Arr[1];
	dp[2] = max(dp[1], Arr[2] + max(Arr[0], Arr[1]));

	for (int i = 3; i < N; i++)
	{
		dp[i] = max(dp[i - 1], Arr[i] + max(dp[i - 2], Arr[i - 1] + dp[i - 3]));
	}

	cout << dp[N - 1];
}