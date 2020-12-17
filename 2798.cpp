#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int n = 0, m = 0, max = 0;
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int result = arr[i] + arr[j] + arr[k];
				if ((max == 0 || result > max) && result <= m)max = result;
			}
		}
	}
	printf("%d", max);
	return 0;
}
