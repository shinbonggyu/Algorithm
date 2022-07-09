#include<iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>
#define MAX 1000001
using namespace std;
int N;
int dp[MAX] = { 0, };
int save[MAX];
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cout.tie(NULL);
	cin >> N;
	dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		save[i] = i - 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
		{
			dp[i] = dp[i / 2] + 1;
			save[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			save[i] = i / 3;
		}
	}
	cout << dp[N] << endl;
	int result = N;
	while (1)
	{
		cout << result << ' ';
		if (result == 1)break;
		result = save[result];
	}
	
	return 0;
}