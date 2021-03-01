//DFS
#include<iostream>
#include<cstring>
using namespace std;
int h, w;
int arr[501][501];
int visit[501][501];
int move_x[4] = { -1,1,0,0 };
int move_y[4] = { 0,0,1,-1 };
int dfs(int x, int y)
{
	if (visit[y][x] != 0)return visit[y][x];
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + move_x[i], next_y = y + move_y[i];
		if (1 <= next_x && next_x <= w && 1 <= next_y && next_y <= h)
			if (arr[y][x] < arr[next_y][next_x])visit[y][x] += dfs(next_x, next_y);
	}
	return visit[y][x];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	memset(arr, 0, sizeof(arr)); memset(visit, 0, sizeof(visit)); cin >> h >> w;
	for (int i = 1; i <= h; i++)for (int j = 1; j <= w; j++)cin >> arr[i][j];
	visit[1][1] = 1; cout << dfs(w, h);
	return 0;
}

//BFS
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int h, w, result = 0;
int arr[501][501];
bool visit[501][501];
int move_x[4] = { -1,1,0,0 };
int move_y[4] = { 0,0,1,-1 };
queue<pair<int, int>>q;
void bfs()
{
	q.push({ 1,1 }); visit[1][1] = true;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + move_x[i], next_y = y + move_y[i];
			if (1 <= next_x && next_x <= w && 1 <= next_y && next_y <= h)
				if (arr[y][x] > arr[next_y][next_x])
				{
					if (next_x == w && next_y == h)result++;
					q.push({ next_x,next_y });
				}
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	memset(arr, 0, sizeof(arr)); memset(visit, false, sizeof(visit)); cin >> h >> w;
	for (int i = 1; i <= h; i++)for (int j = 1; j <= w; j++)cin >> arr[i][j];
	bfs(); cout << result;
	return 0;
}