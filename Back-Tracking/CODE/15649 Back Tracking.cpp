#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 9
using namespace std;

int N, M;
int list[MAX];
bool checked[MAX] = { 0, };

void back(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << list[i] << " ";
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; i++)
	{
		if (!checked[i])
		{
			checked[i] = true;
			list[cnt] = i;
			back(cnt + 1);
			checked[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;
	
	back(0);

	return 0;
}