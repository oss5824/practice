#pragma warning(disable:4996)
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
using namespace std;
int main()
{
	int n = 0, min = 0;
	cin >> n;
	int rgb[3][1001];
	int start_r[1001] = { 0, };
	int start_g[1001] = { 0, };
	int start_b[1001] = { 0, };
	for (int i = 0; i < n; i++)for (int j = 0; j < 3; j++)cin >> rgb[j][i];
	start_r[0] = rgb[0][0];
	start_g[0] = rgb[1][0];
	start_b[0] = rgb[2][0];
	for (int i = 1; i < n; i++)
	{
		start_r[i] = MIN(start_g[i - 1], start_b[i - 1]) + rgb[0][i];
		start_g[i] = MIN(start_r[i - 1], start_b[i - 1]) + rgb[1][i];
		start_b[i] = MIN(start_r[i - 1], start_g[i - 1]) + rgb[2][i];
	}
	min = MIN(start_r[n - 1], start_g[n - 1]);
	min = MIN(min, start_b[n - 1]);
	printf("%d", min);
	return 0;
}
