#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0, min = 0;
	cin >> n;
	int* store = new int[n];
	int* M = new int[n];
	for (int i = 0; i < n; i++)cin >> store[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (store[j-1] > store[j])
			{
				int tmp = store[j-1];
				store[j - 1] = store[j];
				store[j] = tmp;
			}
		}
	}
	M[0] = store[0];
	for (int i = 1; i < n; i++)M[i] = M[i - 1] + store[i];
	for (int i = 0; i < n; i++)min += M[i];
	printf("%d", min);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))