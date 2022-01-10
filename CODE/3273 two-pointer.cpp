#include<iostream>
#include <vector>
#include <algorithm>
#include<queue>
#define MAX 100001

using namespace std;
int N, a, x, result = 0;
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
	cin >> x;
	int start = 0, end = N - 1;
	while (start < end)
	{
		if (v[start] + v[end] < x)
			start++;
		else if (v[start] + v[end] == x) {
			result++;
			end--;
		}
		else
			end--;
	}
	cout << result;
	return 0;
}