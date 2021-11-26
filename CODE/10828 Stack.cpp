#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<stack>
#define MAX 10001

using namespace std;

int N;
string str;
stack<int> s;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push")
		{
			int x;
			cin >> x;
			s.push(x);
		}
		else if (str == "top")
		{
			if (s.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << s.top() << endl;
		}
		else if (str == "pop")
		{
			if (s.empty())
			{
				cout << -1 << endl;
				continue;
			}
			cout << s.top() << endl;
			s.pop();
		}
		else if (str == "size")
			cout << s.size() << endl;
		else if (str == "empty")
		{
			if (s.empty())
			{
				cout << 1 << endl;
				continue;
			}
			cout << 0 << endl;
		}		
	}
}