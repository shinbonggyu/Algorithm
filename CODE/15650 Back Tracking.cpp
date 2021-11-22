#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 9
using namespace std;

int N, M, num;
int MAP[MAX];
bool checked[MAX];

void back(int cnt, int value)
{
	for (int i = cnt; i <= 8; ++i)
	{
		if (checked[i] ==true)
			return;
	}

	MAP[value] = cnt;

	if (value == M)
	{
		num = 0;
		for (int i = 1; i <= M; ++i)
		{
			cout << MAP[i] << " ";
		}
		cout << "\n";
	}

	checked[cnt] = true;

	for (int i = 1; i <= N; ++i)
	{
		back(i, value + 1);
	}
	checked[cnt] = false;
}

int main()
{
	cin >> N >> M;
	
	back(0, 0);

	return 0;
}