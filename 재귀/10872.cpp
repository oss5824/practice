#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	unsigned int* arr = new unsigned int[n + 1];
	arr[0] = 1;
	for (int i = 1; i <= n; i++)arr[i] = i * arr[i - 1];
	printf("%u\n", arr[n]);
	return 0;
}


