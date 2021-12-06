#include<iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include<cstdlib>

#define MAX 2001
using namespace std;
int M, N, S, E;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int arr[MAX];
int DP[MAX][MAX];
int result(int S, int E)
{
	if (S >= E)
		return 1;
	if (DP[S][E] != -1)
		return DP[S][E];
	if (arr[S] != arr[E])
		return DP[S][E] = 0;

	return result(S + 1, E - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	memset(DP, -1, sizeof(DP));

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;
		cout << result(S, E) << '\n';
	}


	return 0;
}