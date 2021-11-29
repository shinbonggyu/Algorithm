#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<cmath>
#include<string>

long long int divide = 1000000007;
using namespace std;
long long int N, K, A = 1, B = 1;

long long int pow(long long int a, long long int b)
{
	a %= divide;
	if (b == 0)
		return 1;
	else if (b == 1)
		return a;
	else if (b % 2 == 0)
	{
		return pow(a, b / 2) * pow(a, b / 2) % divide;
	}
	else return a * pow(a, b - 1) % divide;
}

int main()
{
	cin >> N >> K;
	for (long long i = 1; i <= N; i++)
	{
		A = (A * i) % divide;
	}
	for (long long i = 1; i <= K; i++)
	{
		B = (B * i) % divide;
	}
	for (long long i = 1; i <= (N - K); i++)
	{
		B = (B * i) % divide;
	}
	
	B = pow(B, divide - 2);
	
	cout <<( A * B) % divide ;
	return 0;
}