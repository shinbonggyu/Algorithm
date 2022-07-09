#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 101
using namespace std;

int N, M, cnt;
int x, y;
int Map[MAX][MAX];
int visited[MAX];

void BFS(int start)
{
	visited[start] = 1;
	queue<int> q;

	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i <= M; i++)
		{
			if (!visited[i] && Map[cur][i] != 0)
			{
				visited[i] = 1;
				q.push(i);
				cnt++;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		Map[x][y] = 1;
	}

	BFS(1);
	cout << cnt << endl;
	return 0;
}

