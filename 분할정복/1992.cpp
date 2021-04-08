#include <iostream>
using namespace std;
char** arr;
bool blue(int x1, int y1, int x2, int y2, char color)
{
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			if (arr[i][j] != color)return false;
	return true;
}
bool white(int x1, int y1, int x2, int y2, char color)
{
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			if (arr[i][j] != color)return false;
	return true;
}
void recursive(int x1, int y1, int x2, int y2)
{
	if (blue(x1, y1, x2, y2, '1'))printf("1");
	else if (white(x1, y1, x2, y2, '0'))printf("0");
	else
	{
		printf("(");
		int mid_x = (x1 + x2) / 2;
		int mid_y = (y1 + y2) / 2;
		recursive(x1, y1, mid_x, mid_y);
		recursive(x1, mid_y, mid_x, y2);
		recursive(mid_x, y1, x2, mid_y);
		recursive(mid_x, mid_y, x2, y2);
		printf(")");
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	arr = new char* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new char[n];
		cin >> arr[i];
	}
	recursive(0, 0, n, n);
	return 0;
}