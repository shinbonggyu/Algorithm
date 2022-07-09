#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long N, M, height;

vector <long long> v;
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> height;
		v.push_back(height);
	}

	sort(v.begin(), v.end());

	long long l = 1;
	long long r = v.at(N - 1);
	long long m = (r - l) / 2;
	long long result = 0;
	while (l <= r)
	{
		for (int i = 0; i < N; i++)
		{
			if (v.at(i) > m)
				result += v.at(i) - m;
		}
		if (result >= M)
		{
			l = m + 1;
			m = (r + l) / 2;
		}
		if (result < M)
		{
			r = m - 1;
			m = (r + l) / 2;
		}
		result = 0;
	}

	cout << m;
	return 0;
}