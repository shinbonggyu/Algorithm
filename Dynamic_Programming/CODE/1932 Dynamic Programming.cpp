#include<iostream>
#include<queue>
#include<stdio.h>

#define MAX 502
using namespace std;

int N;
int MAP[MAX][MAX];
int DP[MAX][MAX];

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> MAP[i][j];
		}
	}

	DP[1][1] = MAP[1][1];

	for (int i = 2; i <= N; i++)
	{
		DP[i][1] = DP[i - 1][1] + MAP[i][1];
		for (int j = 2; j < i; j++)
		{
			DP[i][j] = max(DP[i - 1][j] + MAP[i][j], DP[i - 1][j - 1] + MAP[i][j]);
		}
		DP[i][i] = DP[i - 1][i - 1] + MAP[i][i];
	}

	int result = DP[N][1];
	for (int i = 2; i <= N; i++)
	{
		result = max(result, DP[N][i]);
	}

	cout << result;
	return 0;
}

