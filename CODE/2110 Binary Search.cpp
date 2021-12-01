#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, C;
long long x;
vector <long long> v;
int main()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int left = 1, right = v[N - 1];
	int mid = (left + right) / 2;

	int result = 0;

	while (left <= right)
	{
		
		int cnt = 1;
		int pos = v[0];

		for (int i = 1; i < N; i++)
		{
			if (v[i] - pos >= mid)
			{
				cnt++;
				pos = v[i];
			}
		}

		if (cnt >= C)
		{
			result = mid;
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
	}

	cout << result;
	return 0;
}