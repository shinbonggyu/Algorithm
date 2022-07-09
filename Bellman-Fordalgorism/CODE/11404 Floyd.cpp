#include<iostream>
#include <vector>
#include <algorithm>
#include<queue>
#define MAX 10000001

using namespace std;
int N, M, a, b, c;
int DP[102][102] = { 0, };

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= 101; i++)
	{
		for (int j = 1; j <= 101; j++) {
			if (i == j)
				DP[i][j] = 0;
			else DP[i][j] = MAX;
		}
	}

	for(int i=0;i<M;i++){
		int a, b, c;
		cin >> a >> b >> c;
		DP[a][b] = min(DP[a][b], c);
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
				DP[j][k] = min(DP[j][k], DP[j][i] + DP[i][k]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (DP[i][j] == MAX)
				cout << "0 ";
			else cout << DP[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}