#include<iostream>
#include <vector>
#include <algorithm>
#include<queue>
#define INF 10000000
#define MAX 501
using namespace std;
int N, M, A, B, C;
bool flag = false;
vector<int> dist;
vector<vector<pair<int, int>>> map;


int main()
{
	cin >> N >> M;
	map.resize(N + 1);
	dist.resize(N + 1, INF);
	dist[1] = 0;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		map[A].push_back(make_pair(B, C));
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < (int)map[j].size(); k++)
			{
				int next = map[j][k].first;
				int next_d = map[j][k].second;

				if (dist[j] != INF && dist[next] > dist[j] + next_d)
				{
					dist[next] = dist[j] + next_d;
					if (i == N)
						flag = true;
				}
			}
		}
	}

	if (flag)
		cout << -1;
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}
	return 0;
}