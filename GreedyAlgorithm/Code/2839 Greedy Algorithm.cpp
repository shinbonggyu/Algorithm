#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

int MAP[1000][1000];
int M, N, result = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue <pair<int, int>> q;

void BFS()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < M && ny < N && MAP[nx][ny] == 0)
			{
				MAP[nx][ny] = MAP[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	BFS();

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] == 0)
			{
				cout << "-1" << endl;
				return 0;
			}
			if (result < MAP[i][j])
				result = MAP[i][j];
		}
	}
	cout << result - 1;
	return 0;
}