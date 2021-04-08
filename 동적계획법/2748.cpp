#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int n = 0, count = 0;
	cin >> n;
	count = n + 1;
	unsigned long long* store = new unsigned long long[count];
	store[0] = 0;
	store[1] = 1;
	for (int i = 2; i <= n; i++)store[i] = store[i - 1] + store[i - 2];
	printf("%llu", store[n]);
	return 0;
}
