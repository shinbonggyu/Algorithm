#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 1000001
using namespace std;

int N, cnt = 0;
int dp[MAX];

int main()
{
	cin >> N;
	dp[0] = 1;
	dp[1] = 2;


	for (int i = 2; i < N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N-1];
}