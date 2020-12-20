#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int* store;
int main()
{
	int n = 0, max = 0, count = 0;
	cin >> n >> max;
	int* store = new int[n];
	for (int i = 0; i < n; i++)cin >> store[i];
	for (int i = n - 1; i >= 0; i--)
	{
		while(store[i] <= max)
		{
			max -= store[i];
			count++;
		}
	}
	printf("%d", count);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))