#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, store = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		store = (i % 5 == 0) ? store + 1 : store;
		store = (i % 25 == 0) ? store + 1 : store;
		store = (i % 125 == 0) ? store + 1 : store;
	}
	printf("%d", store);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))