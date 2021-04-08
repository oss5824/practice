#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
int n, l, r, arr[51][51];
bool visit[51][51];
int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
bool bfs(int x, int y)
{
	queue<pair<int, int>>q; q.push({ x, y }); visit[y][x] = true;
	vector<pair<int, int>>v; int sum = 0;
	while (!q.empty())
	{
		int curX = q.front().first, curY = q.front().second, curV = arr[curY][curX]; 
		v.push_back({ curX,curY });sum += curV; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextY < 0 || nextX >= n | nextY >= n || visit[nextY][nextX])continue;
			int nextV = arr[nextY][nextX],subV = abs(nextV - curV);
			if (l <= subV && subV <= r) { q.push({ nextX, nextY }); visit[nextY][nextX] = true; }
		}
	}
	int len = v.size();
	if (len == 1)return false;
	int mean = sum / len;
	for (pair<int, int>p : v) { arr[p.second][p.first] = mean; }
	return true;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> arr[i][j];
	int count = 0;
	while (1)
	{
		bool finish = false; memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (!visit[i][j])
				{
					bool check = bfs(j, i);
					if (finish == false && check == true)finish = true;
				}
			}
		if (finish == false) { cout << count; break; }
		count++;
	}
	return 0;
}