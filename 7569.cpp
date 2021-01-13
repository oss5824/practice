#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
int arr[101][101][101];
int M[101][101][101];
int x[6] = { 0,1,0,-1,0,0 };
int y[6] = { -1,0,1,0,0,0 };
int z[6] = { 0,0,0,0,-1,1 };
int m, n, h, maximum = 0;
void bfs(queue<pair<int, pair<int, int>>>q)
{
	while (!(q.empty()))
	{
		int c = q.front().first, b = q.front().second.first, a = q.front().second.second;
		q.pop();
		arr[c][b][a] = -1;
		for (int k = 0; k < 6; k++)
		{
			if (b + y[k] < 0 || b + y[k] >= n || a + x[k] < 0 || a + x[k] >= m
				|| c + z[k] < 0 || c + z[k] >= h)continue;
			if (arr[c + z[k]][b + y[k]][a + x[k]] == 0)
			{
				M[c + z[k]][b + y[k]][a + x[k]] = M[c][b][a] + 1;
				arr[c + z[k]][b + y[k]][a + x[k]] = -1;
				maximum = max(maximum, M[c + z[k]][b + y[k]][a + x[k]]);
				q.push(make_pair(c + z[k], make_pair(b + y[k], a + x[k])));
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a;
	queue<pair<int, pair<int, int>>>q;
	cin >> m >> n >> h;
	memset(arr, 0, sizeof(arr));
	memset(M, 0, sizeof(M));
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1)q.push(make_pair(k, make_pair(i, j)));
			}

	bfs(q);
	for (int k = 0; k < h; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[k][i][j] == 0)
				{
					printf("-1");
					return 0;
				}
	printf("%d", maximum);
	return 0;
}