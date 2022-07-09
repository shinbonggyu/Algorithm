#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

int N;
vector <int> result;

int main()
{
	cin >> N;
	vector <int> result (100001);
	for (int i = 2; i <= N; i++)
	{
		result.at(i) = result.at(i - 1) + 1;
		if (i % 2 == 0)
		{
			result[i] = min(result[i], result[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			result[i] = min(result[i], result[i / 3] + 1);
		}
	}

	cout << result[N];
	return 0;
}