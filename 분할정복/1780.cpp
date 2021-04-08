#include <iostream>
using namespace std;
int** store;
int n;
int m = 0, z = 0, p = 0;
int possible(int x, int y, int size)
{
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			if (store[x][y] != store[i][j])return 0;
	if (store[x][y] == -1)return 1;
	else if (store[x][y] == 0)return 2;
	else if (store[x][y] == 1)return 3;
}
void recursive(int x, int y, int size)
{
	int res = possible(x, y, size);
	if (res)
	{
		if (res == 1)m++;
		else if (res == 2)z++;
		else if (res == 3)p++;
	}
	else
	{
		int step = size / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				recursive(x + i * step, y + j * step, step);
	}
}
int main()
{
	cin >> n;
	store = new int* [n];
	for (int i = 0; i < n; i++)store[i] = new int[n];
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> store[i][j];
	recursive(0, 0, n);
	printf("%d\n%d\n%d", m, z, p);
	return 0;
}