#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include<cstdlib>

#define MAX 501
using namespace std;
int K, T;
int DP[MAX][MAX], psum [MAX];
int dfs(int s, int e)
{
	if (s == e)
		return 0;
	if (DP[s][e] != -1)
		return DP[s][e];
	DP[s][e] = 1e9;
	if (s > K)
		return DP[s][e];
	for (int i = s; i < e; i++)
	{
		DP[s][e] = min(DP[s][e], dfs(s, i) + dfs(i + 1, e) + psum[e] - psum[s - 1]);
	}
	return DP[s][e];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		memset(psum, 0, sizeof(psum));
		memset(DP, -1, sizeof(DP));
		cin >> K;
		for (int j = 1; j <= K; j++)
		{
			cin >> psum[j];
			psum[j] += psum[j - 1];
		}
		cout << dfs(1, K) << '\n';
	}
	return 0;
}