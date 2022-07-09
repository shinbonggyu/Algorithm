#include<iostream>
#include<queue>
#include<stdio.h>

#define MAX 101
using namespace std;

int N, result = 0, sum = 0, tmp = 0;

int main()
{
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		tmp = i;
		sum = i;
		while (tmp != 0)
		{
			sum += tmp % 10;
			tmp = tmp / 10;
		}

		if (sum == N)
		{
			result = i;
			break;
		}
	}
	cout << result << endl;
	return 0;
}

