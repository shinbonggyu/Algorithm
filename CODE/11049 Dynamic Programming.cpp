#include<iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include<cstdlib>

#define MAX 501
using namespace std;
int N, r, c;
int DP[MAX][MAX], arr[MAX][2];
int dfs(int s, int e)
{
	if (s == e)
		return 0;
	if (DP[s][e] != -1)
		return DP[s][e];
	DP[s][e] = 1e9;
	if (s + 1 == e)
		return DP[s][e] = arr[s][0] * arr[s][1] * arr[e][1];
	for (int i = s; i < e; i++)
	{
		DP[s][e] = min(DP[s][e], dfs(s, i) + dfs(i + 1, e) + arr[s][0] * arr[i][1] * arr[e][1]);
	}
	return DP[s][e];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(DP, -1, sizeof(DP));

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	cout << dfs(0, N-1);
	return 0;
}