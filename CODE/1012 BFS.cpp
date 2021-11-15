#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#define MAX 51

using namespace std;
int T, M, N, K;
int x, y;

int Map[MAX][MAX];
int visited[MAX][MAX];

const int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
queue <pair<int, int>> q;
void BFS(int x, int y)
{
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int nx = a + dx[i];
				int ny = b + dy[i];

				if (nx<0 || nx>M || ny<0 || ny >N)
				{
					continue;
				}

				if (Map[nx][ny] && !visited[nx][ny])
				{
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		memset(Map, false, sizeof(Map));
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> x >> y;
			Map[x][y] = 1;
		}

		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (Map[j][k] == 1 && !visited[j][k])
				{
					cnt++;
					BFS(j, k);
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}