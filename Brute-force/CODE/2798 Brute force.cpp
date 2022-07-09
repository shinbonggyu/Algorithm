#include<iostream>
#include<queue>
#include<stdio.h>

#define MAX 101
using namespace std;

int N, M, Num, result = 0;
vector <int> card;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> Num;
		if (Num < M)
			card.push_back(Num);
	}

	for (int i = 0; i < card.size()-2; i++)
	{
		for (int j = i+1; j < card.size()-1; j++)
		{
			for (int k = j + 1; k < card.size(); k++)
			{
				int max = card.at(i) + card.at(j) + card.at(k);
				if (max <= M && max > result)
					result = max;
			}
		}
	}

	cout << result;

	return 0;
}

