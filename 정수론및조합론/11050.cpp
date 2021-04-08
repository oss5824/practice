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
	int* store = new int[n + 1];
	store[0] = 1;
	for (int i = 1; i <= n; i++)store[i] = store[i - 1] * i;
	printf("%u", store[n] / (store[k] * store[n - k]));
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))