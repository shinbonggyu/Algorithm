#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>

#define MAX 51
using namespace std;

int N, x, y;
vector <pair <int, int >> v;
int result[MAX];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		result[i] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));

	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j].first > v[i].first && v[j].second > v[i].second)
				result[i] ++;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout<< result[i]<<" ";
	}
	return 0;
}

