#include<iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include<cstdlib>

#define MAX 501
using namespace std;
int M, N;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int arr[MAX][MAX];
int DP[MAX][MAX];

int dfs(int x, int y)
{
	if (DP[x][y] != -1)
	{
		return DP[x][y];
	}
	else if (x == M - 1 && y == N - 1)
		return 1;

	else {
		DP[x][y] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;

			if (arr[nx][ny] < arr[x][y])
			{
				DP[x][y] += dfs(nx, ny);
			}
		}

		return DP[x][y];
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	memset(DP, -1,sizeof(DP));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << dfs(0, 0);
	return 0;
}