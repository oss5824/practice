#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
char arr[101][101];
int M[101][101];
int x[4] = { 0,1,0,-1 };
int y[4] = { -1,0,1,0 };
int m, n, T, min_val = 1000000;
void bfs(int i, int j)
{
	queue <pair<int, int>> q;
	q.push(make_pair(i, j));
	while (!(q.empty()))
	{
		int a = q.front().first, b = q.front().second;
		q.pop();
		arr[a][b] = '0';
		for (int k = 0; k < 4; k++)
		{
			if (a + y[k] < 0 || a + y[k] >= n || b + x[k] < 0 || b + x[k] >= m)continue;
			if (arr[a + y[k]][b + x[k]] == '1')
			{
				M[a + y[k]][b + x[k]] = M[a][b] + 1;
				q.push(make_pair(a + y[k], b + x[k]));
			}
			if (a + y[k] == n - 1 && b + x[k] == m - 1)
				min_val = min(min_val, M[a + y[k]][b + x[k]]);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> arr[i];
	memset(M, 0, sizeof(M));
	M[0][0] = 1;
	bfs(0, 0);
	printf("%d\n", min_val);
	return 0;
}
