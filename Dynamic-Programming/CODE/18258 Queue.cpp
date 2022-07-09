#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include<cstdlib>

using namespace std;
int N;
queue <int> q;
string str;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (str == "pop")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if (str == "size")
		{
			cout << q.size() << '\n';
		}
		else if (str == "empty")
		{
			if (q.empty())
			{
				cout << 1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
		else if (str == "front")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			else
				cout << q.front() << '\n';
		}
		else if (str == "back")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			else
				cout << q.back() << '\n';
		}
	}
}