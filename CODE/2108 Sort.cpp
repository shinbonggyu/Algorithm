#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>

#define MAX 500001

using namespace std;

int N;
int x, Avg = 0, cnt = 0, max_num = 0, maxval = -9999;
int Arr[8001] = { 0, };
vector <int> v;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
		Avg += x;
		Arr[x + 4000] += 1;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 8001; i++)
	{
		if (Arr[i] == 0)
			continue;
		if (Arr[i] > max_num)
		{
			max_num = Arr[i];
			maxval = i - 4000;
		}
	}

	if (N != 1)
	{
		for (int i = 0; i < 8001; i++)
		{
			if (Arr[i] != max_num)
				continue;
			if (Arr[i] == max_num)
			{
				cnt++;
				if (cnt == 2)
				{
					maxval = i - 4000;
					break;
				}
			}
		}
	}
	cout << round(Avg / (float)N) << endl;
	cout << v[N / 2] << endl;
	cout << maxval << endl;
	cout << v.back() - v.front() << endl;

	return 0;
}