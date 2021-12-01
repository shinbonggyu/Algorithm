#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 6
using namespace std;
int N, M, A, B;

vector <int> v;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		v.push_back(A);
	}
	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> B;

		int result = upper_bound(v.begin(), v.end(), B) - lower_bound(v.begin(), v.end(), B);
		cout << result << " ";
	}
	return 0;
}