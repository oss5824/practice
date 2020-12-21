#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
using namespace std;
int main()
{
	int n = 0, count = 0;
	unsigned int max = 0;
	unsigned int arr[100000] = { 0, };
	cin >> n;
	unsigned int* store = new unsigned int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> store[i];
		max = MAX(max, store[i]);
	}
	for (int i = 2; i <= max; i++)
	{
		int x = store[0] % i, j = 1;
		while ((x == store[j] % i) && (j < n))j++;
	}
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))