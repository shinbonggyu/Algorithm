#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long N, K, line;
vector<long long>v;

int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> line;
		v.push_back(line);
	}
	sort(v.begin(), v.end());
	long long l = 1;
	long long r = v.at(K - 1);
	long long m = (r + l) / 2;
	long long rope = 0;
	while (l <= r)
	{
		for (int i = 0; i < K; i++)
		{
			rope += v.at(i) / m;
		}
		if (rope >= N) {
			l = m + 1;
			m = (r + l) / 2;
		}
		else if (rope < N)
		{
			r = m - 1;
			m = (r + l) / 2;
		}
		rope = 0;
	}
	cout << m;
	return 0;
}