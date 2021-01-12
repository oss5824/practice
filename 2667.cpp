#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char arr[27][27];
int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };
int n, num = 0, all = 0;
void dfs(int i, int j)
{
	num++;
	arr[i][j] = '0';
	for (int q = 0; q < 4; q++)
	{
		if (i + y[q] < 0 || i + y[q] >= n || j + x[q] < 0 || j + x[q] >= n)continue;
		if (arr[i + y[q]][j + x[q]] != '0')dfs(i + y[q], j + x[q]);
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	int res[1000] = { 0, };
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < n; i++)cin >> arr[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] != '0')
			{
				num = 0;
				dfs(i, j);
				res[all++] = num;
			}
	sort(res, res + all);
	printf("%d\n", all);
	for (int i = 0; i < all; i++)printf("%d\n", res[i]);
	return 0;
}