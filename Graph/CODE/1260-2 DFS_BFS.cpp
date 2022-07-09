#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1001
using namespace std;


int N, M, V;
vector<int> E[1001];
bool visit[MAX];
void DFS(int V)
{
	visit[V] = true;

	cout << V << " ";

	for (int i = 0; i < E[V].size(); i++)
	{
		int next = E[V][i];
		if (!visit[next])
			DFS(next);
	}
}

void BFS(int V)
{
	queue<int> q;
	q.push(V);
	visit[V] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < E[cur].size(); i++)
		{
			int next = E[cur][i];
			if (!visit[next])
			{
				visit[next] = true;
				q.push(next);
			}
		}
	}
}
int main()
{
	int x, y;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(E[i].begin(), E[i].end());
	}
	DFS(V);

	cout << endl;
	memset(visit, false, sizeof(visit));

	BFS(V);
	return 0;
}