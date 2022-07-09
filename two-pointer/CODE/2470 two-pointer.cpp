#include<iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>

using namespace std;
int N, a, Min, x, y;
vector<int>v;

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	int start = 0, end = N - 1;
	x = v[start], y = v[end];
	Min = abs(v[start] + v[end]);

	while (start < end)
	{
		if (abs(v[start] + v[end]) < Min) {
			Min = abs(v[start] + v[end]);
			x = v[start];
			y = v[end];
		}
		if (abs(v[start]) > abs(v[end])) {
			start++;
		}
		else
			end--;
	}
	cout << x << " " << y;
	return 0;
}