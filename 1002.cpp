#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int* x1 = new int[n];
	int* y1 = new int[n];
	int* r1 = new int[n];
	int* x2 = new int[n];
	int* y2 = new int[n];
	int* r2 = new int[n];
	for (int i = 0; i < n; i++)cin >> x1[i] >> y1[i] >> r1[i] >> x2[i] >> y2[i] >> r2[i];
	for (int i = 0; i < n; i++)
	{
		int distance = (int)pow(x2[i] - x1[i], 2) + pow(y2[i] - y1[i], 2);
		int r = (int)pow(r1[i] + r2[i], 2);
		if (x1[i] == x2[i] && y1[i] == y2[i])
		{
			if (r1[i] == r2[i])printf("%d\n", -1);
			else printf("%d\n", 0);
		}
		else if (distance == (int)pow(r1[i] - r2[i], 2))printf("1\n");
		else if (distance < (int)pow(r1[i] - r2[i], 2))printf("0\n");
		else if (distance == r)printf("1\n");
		else if (distance > r)printf("0\n");
		else if (distance < r)printf("2\n");
	}


	return 0;
}


