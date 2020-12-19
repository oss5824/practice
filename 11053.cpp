#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MAX3(a,b,c) ((((a)>(b))&&((a)>(c)))? (a) : (((b)>(c))?(b) : (c)))
using namespace std;
int* M;
int* store;
int main()
{
	int n = 0, max = 0;
	cin >> n;
	store = new int[n];
	M = new int [n];
	memset(M, 0, sizeof(int) * n);
	for (int i = 0; i < n; i++)cin >> store[i];
	for (int i = 0; i < n; i++)
	{
		M[i] = 1;
		for (int j = 0; j < i; j++)if (store[i] > store[j])M[i] = MAX(M[i], M[j] + 1);
		max = MAX(max, M[i]);
	}
	printf("%d", max);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))