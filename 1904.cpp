#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1000001
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int* store = new int[SIZE];
	store[1] = 1, store[2] = 2;
	for (int i = 3; i <= n; i++)store[i] = store[i - 1] % 15746 + store[i - 2] % 15746;
	printf("%llu", store[n] % 15746);
	return 0;
}
