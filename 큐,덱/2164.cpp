#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0;
	queue<int>value;
	cin >> n;
	for (int i = 1; i <= n; i++)value.push(i);
	
	while (value.size() != 1)
	{
		value.pop();
		if (value.size() == 1)break;
		int store = value.front();
		value.pop();
		value.push(store);
	}
	printf("%d", value.front());
	return 0;
}
//	cin.tie(NULL);
//ios::sync_with_stdio(false);
