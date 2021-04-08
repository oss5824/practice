#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* store = new int[n];
	int* M = new int[n];
	for (int i = 0; i < n; i++)cin >> store[i];
	M[0] = store[0], M[1] = store[0] + store[1];
	M[2] = MAX(store[0], store[1]) + store[2];
	for (int i = 3; i < n; i++)M[i] = MAX(M[i - 2], M[i - 3] + store[i - 1]) + store[i];
	printf("%d", M[n - 1]);
	return 0;
}
