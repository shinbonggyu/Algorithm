#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>

#define MAX 100001
using namespace std;

int N;
int x, y;
vector <pair <int, int>> v;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}

