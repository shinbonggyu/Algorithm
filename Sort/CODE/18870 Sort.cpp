#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#define MAX 1000001

using namespace std;

int N;
int x;
vector <int> v;
vector <int> result;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	result = v;
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	for (int i = 0; i < N; i++)
	{
		cout << lower_bound(result.begin(), result.end(), v[i]) - result.begin() << " ";
	}
	return 0;
}