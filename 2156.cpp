#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MAX3(a,b,c) ((((a)>(b))&&((a)>(c)))? (a) : (((b)>(c))?(b) : (c)))
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	unsigned long long* M = new unsigned long long[n];
	int* store = new int[n];
	for (int i = 0; i < n; i++)cin >> store[i];
	M[0] = store[0], M[1] = store[0] + store[1];
	M[2] = MAX3(store[0] + store[1], store[0] + store[2], store[1] + store[2]);
	for (int i = 3; i < n; i++)
		M[i] = MAX3(M[i - 3] + store[i - 1] + store[i], 
			M[i - 2] + store[i], M[i - 1]);
	printf("%llu", M[n - 1]);
	return 0;
}
//#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))