#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
int N, M, V;
bool arr[1001][1001];
bool visit[1001];
stack<int> s;
queue<int> q;

void DFS() {
	s.push(V);
	while (!s.empty())
	{
		int cur = s.top();
		if (visit[cur])
			return;
		cout << cur << " ";
		visit[cur] = true;
		s.pop();
		for (int i = N; i > 0; --i)
		{
			if (arr[cur][i] == true && visit[i] != true)
				s.push(i);
		}
	}
}

void BFS() {
	q.push(V);
	while (!q.empty()) {
		int cur = q.front();
		if (visit[cur] == false) cout << cur << " ";
		visit[cur] = true;
		q.pop();
		for (int i = 1; i <= N; ++i) {
			if (arr[cur][i] != false && visit[i] == false)
				q.push(i);
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	memset(arr, false, sizeof(arr));
	memset(visit, false, sizeof(visit));
	int x, y;
	for (int i = 0; i < M; ++i)
	{
		cin >> x >> y;
		arr[x][y] = true;
		arr[y][x] = true;
	}
	DFS();
	memset(visit, false, sizeof(visit));
	cout << endl;
	BFS();
}