#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 26

using namespace std;

int N;
string S;
int map[MAX][MAX];
int visit[MAX][MAX];
vector <int> Answer;

int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

void dfs(int x, int y)
{
	map[x][y] = 0;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (ny<0 || ny>N || nx < 0 || nx < 0)
		{
			continue;
		}

		if (map[nx][ny] == 1 && !visited[nx][ny])
		{
			tmp++;
			DFS(nx, ny);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> S;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = S[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				tmp = 1;
				DFS(i, j);
				Answer.push_back(tmp);
			}
		}
	}
	sort(Answer.begin(), Answer.end());
	

	for (int i = 0; i < Answer.size(); i++)
	{
		cout << Answer[i] << endl;
	}

	return 0;
}