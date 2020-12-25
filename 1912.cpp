#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
using namespace std;
int main()
{
	short n = 0, max = 0;
	cin >> n;
	short* store = new short[n];
	short** M = new short* [n];
	for (int i = 0; i < n; i++)cin >> store[i];
	max=store[0];
	for (int i = 0; i < n; i++)
	{
		short x = n - i;
		M[i] = new short[x];
		M[i][0] = store[i];
		max = MAX(max, store[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
		{
			M[i][j] = M[i][j - 1] + store[i + j];
			max = MAX(max, M[i][j]);
		}
	printf("%d", max);
	return 0;
}
