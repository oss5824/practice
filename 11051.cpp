#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, k = 0;
	cin >> n >> k;
	if (n == k || k == 0)
	{
		printf("1");
		return 0;
	}
	unsigned long long** store = new unsigned long long* [n + 1];
	for (int i = 0; i <= n; i++)store[i] = new unsigned long long[i + 1];
	for (int i = 0; i < n; i++)
	{
		store[i][0] = 1, store[i][i] = 1;
		for (int j = 0; j < i; j++)store[i + 1][j + 1] = store[i][j]%10007 + store[i][j + 1]%10007;
	}
	printf("%llu", store[n][k] % 10007);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))