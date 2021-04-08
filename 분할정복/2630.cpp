#include <iostream>
using namespace std;
int** arr;
int bnum = 0;
int wnum = 0;
bool blue(int x1, int y1, int x2, int y2, int color)
{
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
		if (arr[i][j] != color)return false;
	return true;
}
bool white(int x1, int y1, int x2, int y2, int color)
{
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			if (arr[i][j] != color)return false;
	return true;
}
void recursive(int x1, int y1, int x2, int y2)
{
	if (blue(x1, y1, x2, y2, 1))bnum++;
	else if (white(x1, y1, x2, y2, 0))wnum++;
	else
	{
		int mid_x = (x1 + x2) / 2;
		int mid_y = (y1 + y2) / 2;
		recursive(x1, y1, mid_x, mid_y);
		recursive(mid_x, y1, x2, mid_y);
		recursive(x1, mid_y, mid_x, y2);
		recursive(mid_x, mid_y, x2, y2);
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)cin >> arr[i][j];
	}
	recursive(0, 0, n, n);
	printf("%d\n", wnum);
	printf("%d", bnum);
	return 0;
}