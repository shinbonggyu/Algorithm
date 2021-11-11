#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include<memory.h>
using namespace std;

int N, M, cnt;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int Arr[101][101];
int Brr[101][101];

void bfs(int x, int y) {
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	Brr[x][y] += Arr[x][y];

	// 큐에 내용물이 있는 동안, 탐색하면서 방문
	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;

			// 방문하지 않았으면, 방문
			if (Arr[nx][ny] == 1 && Brr[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				Brr[nx][ny] = Brr[tx][ty] + Arr[nx][ny];	// 이전까지 거리 합 + 지금 거리
			}
		}


	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	// 맵 생성
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			Arr[i][j] = s[j - 1] - '0';
		}
	}

	// 탐색 시작
	bfs(1, 1);

	cout << Brr[N][M];
}
