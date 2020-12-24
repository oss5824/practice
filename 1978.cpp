#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, result = 0;
	cin >> n;
	int* store = new int[n];
	for (int i = 0; i < n; i++)cin >> store[i];
	for (int i = 0; i < n; i++)
	{
		int val = store[i], flag = 0;
		for (int j = 2; j < val; j++)
		{
			if (val % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0 && val != 1)result++;
	}
	printf("%d", result);
	return 0;
}

