#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 25
using namespace std;

int N, tmp, cnt;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int map[MAX][MAX];
int visited[MAX][MAX];
vector<int> Answer;

void DFS(int x, int y)
{
	map[x][y] = 0;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
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
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = s[j] - '0';
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
				cnt++;
			}
		}
	}

	sort(Answer.begin(), Answer.end());
	cout << cnt << endl;
	
	for (int i = 0; i < Answer.size(); i++)
	{
		cout << Answer[i] << endl;
	}
	
	return 0;
}
