#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define MIN3(a,b,c) ((((a)<(b))&&((a)<(c)))? (a) : (((b)<(c))?(b) : (c)))
using namespace std;
int* M;
int recursive(int i)
{
	if (M[i] != -1 || i == 1)return M[i];
	if (i % 6 == 0)M[i] = 1 + MIN3(recursive(i / 3), recursive(i / 2), recursive(i - 1));
	else if (i % 2 == 0)M[i] = 1 + MIN(recursive(i / 2), recursive(i - 1));
	else if (i % 3 == 0)M[i] = 1 + MIN(recursive(i / 3), recursive(i - 1));
	else M[i] = 1 + recursive(i - 1);
	return M[i];
}
int main()
{
	int n = 0, count = 0;
	cin >> n;
	count = n + 1;
	M = new int[count];
	memset(M, -1, sizeof(int) * count);
	M[0] = 0, M[1] = 0;
	recursive(n);
	printf("%d", M[n]);
	return 0;
}
