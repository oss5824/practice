#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, k = 0;
	queue<int>value;
	queue<int>result;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)value.push(i);
	printf("<");
	while (!(value.empty()))
	{
		for (int i = 1; i < k; i++)
		{
			int top = value.front();
			value.pop();
			value.push(top);
		}
		int top = value.front();
		value.pop();
		printf("%d", top);
		if (!(value.empty()))printf(", ");
	}
	printf(">");
	return 0;
}
//	cin.tie(NULL);
//ios::sync_with_stdio(false);
