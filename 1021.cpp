#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0, m = 0, result = 0;
	queue<int >value;
	cin >> n >> m;
	for (int i = 0; i < n; i++)value.push(i + 1);
	int* store = new int[m];
	for (int i = 0; i < m; i++)
	{
		int a = 0;
		cin >> a;
		store[i] = a;
	}

	for (int i = 0; i < m; i++)
	{
		int count = 0, max = value.size();
		while (!(value.front() == store[i]))
		{
			value.push(value.front());
			value.pop();
			count++;
		}
		value.pop();
		max -= count;
		if (max > count)result += count;
		else result += max;
	}
	printf("%d", result);
	return 0;
}