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
vector<pair<int, int>>v;
bool check() { for (int i = 1; i < N - 1; i++)for (int j = 1; j < M - 1; j++)if (Map[i][j] == 1)return false; return true; }
bool bfs(int x, int y)
{
	queue<pair<int, int>>q; q.push({ 0,0 }); memset(visit, false, sizeof(visit)); visit[0][0] = true;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX == x && nextY == y)  return true;
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
	while (1)
	{
		if (check()) { cout << hour << "\n" << v.size(); break; }
		else hour++;
		v.clear();
		for (int i = 1; i < N - 1; i++)
			for (int j = 1; j < M - 1; j++)
			{
				if (Map[i][j] == 1)if (bfs(j, i))v.push_back({ i,j });
			}
		for (pair<int, int>p : v)Map[p.first][p.second] = 0;
	}
	return 0;
}

