#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000001
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int* count = new int[n];
	unsigned long long* store = new unsigned long long[101];
	for (int i = 0; i < n; i++)cin >> count[i];
	store[1] = 1, store[2] = 1, store[3] = 1;
	for (int i = 4; i <= 100; i++)
	{
		store[i] = store[i - 2] + store[i - 3];
	}
	for (int k = 0; k < n; k++)printf("%llu\n", store[count[k]]);
	return 0;
}
