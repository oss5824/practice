#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
int arr[301][301];
int M[301][301];
int n, l;
int a, b, c, d;
int mx[8] = { -1,1,2,2,-1,1,-2,-2 };
int my[8] = { -2,-2,-1,1,2,2,-1,1 };
void bfs()
{
	queue<pair<int, int>>q;
	q.push(make_pair(b, a));
	arr[b][a] = 1;
	while (!(q.empty()))
	{
		int y = q.front().first, x = q.front().second;
		q.pop();
		if (d == y && c == x)break;
		arr[y][x] = 1;
		for (int k = 0; k < 8; k++)
		{
			if (y + my[k] < 0 || y + my[k] >= l || x + mx[k] < 0 || x + mx[k] >= l)continue;
			if (arr[y + my[k]][x + mx[k]] == 0)
			{
				arr[y + my[k]][x + mx[k]] = 1;
				M[y + my[k]][x + mx[k]] = M[y][x] + 1;
				q.push(make_pair(y + my[k], x + mx[k]));
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		cin >> b >> a;
		cin >> d >> c;
		memset(arr, 0, sizeof(arr));
		memset(M, 0, sizeof(M));
		bfs();
		printf("%d\n", M[d][c]);
	}
	return 0;
}
