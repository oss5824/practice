#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
int** M;
int** store;
int n;
using namespace std;
int recursive(int i, int j)
{
	if (M[i][j] != -1 || i == 0 || j == 0)return M[i][j];
	M[i][j] = MAX(recursive(i - 1, j - 1), recursive(i - 1, j)) + store[i][j];
	return M[i][j];
}
int main()
{
	cin >> n;
	int max = 0;
	store = new int* [n];
	M = new int* [n];
	for (int i = 0, c = i + 1; i < n; i++)
	{
		store[i] = new int[n];
		M[i] = new int[n];
		memset(M[i], -1, sizeof(int) * n);
		memset(store[i], -1, sizeof(int) * n);
	}
	for (int i = 0; i < n; i++)for (int j = 0; j < i + 1; j++)cin >> store[i][j];
	M[0][0] = store[0][0];
	for (int i = 1; i < n; i++)M[i][0] = M[i - 1][0] + store[i][0];
	for (int i = 0; i < n; i++)
	{
		int max_ = recursive(n - 1, i);
		max = MAX(max, max_);
	}
	printf("%d", max);
	return 0;
}
