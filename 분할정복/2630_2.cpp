#include<iostream>
using namespace std;
int arr[129][129], w, b;
int color(int x, int y, int sz)
{
	for (int i = y; i < y + sz; i++)
		for (int j = x; j< x + sz; j++)
			if (arr[i][j] != arr[y][x])return -1;
	return arr[y][x];
}
void recursive(int x, int y,int sz)
{
	int val = color(x, y, sz);
	if (val != -1) { if (val == 1)b++; else w++; }
	else
	{
		recursive(x, y, sz / 2);
		recursive(x, y + sz / 2, sz / 2);
		recursive(x + sz / 2, y, sz / 2);
		recursive(x + sz / 2, y + sz / 2, sz / 2);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int n; cin >> n; for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> arr[i][j];
	recursive(1, 1, n);	cout << w << "\n" << b; return 0;
}