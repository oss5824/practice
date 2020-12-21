#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
using namespace std;
int main()
{
	int n = 0, max = 0, min = 1000001, count = 0;
	cin >> n;
	int* store = new int[n];
	for (int i = 0; i < n; i++)cin >> store[i];
	for (int i = 0; i < n; count++, i++)
	{
		max = MAX(max, store[i]);
		min = MIN(min, store[i]);
	}
	printf("%d", max * min);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))