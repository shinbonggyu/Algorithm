#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int A, N, cnt = 0;
vector <int> v;
int main()
{
	cin >> N;
	v.push_back(-99999);
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (A > v.back())
		{
			v.push_back(A);
			cnt++;
		}

		else
		{
			auto it = lower_bound(v.begin(), v.end(), A);
			*it = A;
		}
	}
	
	cout << cnt;
	return 0;
}