#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int* store = new int[n];
	for (int i = 0; i < n; i++)cin >> store[i];
	for (int i = 0; i < n; i++)
	{
		int zero[41] = { 0, };
		int one[41] = { 0, };
		zero[0] = 1, zero[1] = 0;
		one[0] = 0, one[1] = 1;
		for (int j = 2; j <= store[i]; j++)
		{
			zero[j] = zero[j - 1] + zero[j - 2];
			one[j] = one[j - 1] + one[j - 2];
		}
		printf("%d %d\n", zero[store[i]], one[store[i]]);
	}
	return 0;
}
