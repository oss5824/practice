#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, m = 0, store = 0, n_store = 0, k_store = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		store = (i % 5 == 0) ? store + 1 : store;
		store = (i % 25 == 0) ? store + 1 : store;
		store = (i % 125 == 0) ? store + 1 : store;

		n_store = (i % 5 == 0 && i <= m) ? n_store + 1 : n_store;
		n_store = (i % 25 == 0 && i <= m) ? n_store + 1 : n_store;
		n_store = (i % 125 == 0 && i <= m) ? n_store + 1 : n_store;

		k_store = (i % 5 == 0 && i <= n - m) ? k_store + 1 : k_store;
		k_store = (i % 25 == 0 && i <= n - m) ? k_store + 1 : k_store;
		k_store = (i % 125 == 0 && i <= n - m) ? k_store + 1 : k_store;
	}
	printf("%d", store - n_store - k_store);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))