#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<string>
#define INF 987654321
typedef unsigned long long ull;
using namespace std;
int N, M, Map[100][100];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool visit[100][100];
int air[100][100];
vector<pair<int, int>>v;
bool check() { for (int i = 1; i < N - 1; i++)for (int j = 1; j < M - 1; j++)if (Map[i][j] == 1)return false; return true; }
bool bfs(int x, int y)
{
	queue<pair<int, int>>q; q.push({ x,y }); memset(visit, false, sizeof(visit)); visit[y][x] = true;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		if (curX == 0 && curY == 0) return true; 
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextY][nextX] || Map[nextY][nextX] == 1)continue;
			q.push({ nextX,nextY }); visit[nextY][nextX] = true;
		}
	}
	return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; int hour = 0;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] == 0) { if (!bfs(j, i))Map[i][j] = 2; else Map[i][j] = 0; }
	while (1)
	{
		if (check())break;
		hour++; v.clear();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (Map[i][j] == 2) { if (bfs(j, i)) Map[i][j] = 0; }
		for (int i = 1; i < N - 1; i++)
			for (int j = 1; j < M - 1; j++)
			{
				int cnt = 0;
				if (Map[i][j] != 1)continue;
				if (Map[i][j - 1] == 0)cnt++;
				if (Map[i][j + 1] == 0)cnt++;
				if (Map[i - 1][j] == 0)cnt++;
				if (Map[i + 1][j] == 0)cnt++;
				if (cnt >= 2)v.push_back({ j,i });
			}
		for (pair<int, int>p : v)Map[p.second][p.first] = 0;
	}cout << hour;
	return 0;
}

