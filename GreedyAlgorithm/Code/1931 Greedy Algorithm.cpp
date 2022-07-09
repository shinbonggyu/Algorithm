#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 100001

using namespace std;

int N, x, y, key, result = 1;
vector <pair<int, int>> v;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	
	sort(v.begin(), v.end());

	key = v[0].second;

	for (int i = 1; i < N; i++)
	{
		if (key <= v[i].first)
		{
			result++;
			key = v[i].second;
		}
	}

	cout << result << endl;
}