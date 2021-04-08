#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int n_ = n;
	for (int i = 2; i <= n; i++)
		while (n_ % i == 0)
		{
			n_ = n_ / i;
			printf("%d\n", i);
		}
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))