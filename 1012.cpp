#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char arr[51][51];
int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };
int m, n, k, T;
void dfs(int i, int j)
{
	arr[i][j] = '0';
	for (int q = 0; q < 4; q++)
	{
		if (i + y[q] < 0 || i + y[q] >= n || j + x[q] < 0 || j + x[q] >= m)continue;
		if (arr[i + y[q]][j + x[q]] == '1')dfs(i + y[q], j + x[q]);
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int a = 0; a < T; a++)
	{
		int cnt = 0;
		cin >> m >> n >> k;
		memset(arr, '0', sizeof(arr));
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[b][a] = '1';
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] == '1')
				{
					cnt++;
					dfs(i, j);
				}
		printf("%d\n", cnt);
	}
	return 0;
}