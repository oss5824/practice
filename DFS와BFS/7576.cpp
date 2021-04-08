#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
int arr[1001][1001];
int M[1001][1001];
int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };
int m, n, maximum = 0;
void bfs(queue<pair<int, int>>q)
{
	while (!(q.empty()))
	{
		int a = q.front().first, b = q.front().second;
		q.pop();
		arr[a][b] = -1;
		for (int k = 0; k < 4; k++)
		{
			if (a + y[k] < 0 || a + y[k] >= n || b + x[k] < 0 || b + x[k] >= m)continue;
			if (arr[a + y[k]][b + x[k]] == 0)
			{
				M[a + y[k]][b + x[k]] = M[a][b] + 1;
				arr[a + y[k]][b + x[k]] = -1;
				maximum = max(maximum, M[a + y[k]][b + x[k]]);
				q.push(make_pair(a + y[k], b + x[k]));
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a;
	queue<pair<int, int>>q;
	cin >> m >> n;
	memset(arr, 0, sizeof(arr));
	memset(M, 0, sizeof(M));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)q.push(make_pair(i, j));
		}
	bfs(q);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 0)
			{
				printf("-1");
				return 0;
			}
	printf("%d", maximum);
	return 0;
}