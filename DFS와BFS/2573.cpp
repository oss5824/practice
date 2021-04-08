#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int N, M, year;
int Map[300][300];
bool visit[300][300];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
vector<pair<pair<int, int>, int>>v;
void bfs(int x, int y)
{
	queue<pair<int, int>>q; q.push({ x,y }); visit[y][x] = true;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX<0 || nextX>M || nextY < 0 || nextY >= N || visit[nextY][nextX]
				|| Map[nextY][nextX] == 0)continue;
			q.push({ nextX,nextY }); visit[nextY][nextX] = true;
		}
	}
}
bool finish()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] != 0 && !visit[i][j])return true;
	return false;
}
bool iceCheck()
{
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] != 0)return true;
	return false;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	while (1)
	{
		int cnt = 0; v.clear();memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (Map[i][j] == 0)continue;
				if (visit[i][j])continue;
				bfs(j, i); cnt++;
			}
		if (cnt != 1) { cout << year; break; }
		for (int i = 1; i < N - 1; i++)
			for (int j = 1; j < M - 1; j++)
			{
				int water = 0;
				if (Map[i + 1][j] == 0)water++;
				if (Map[i - 1][j] == 0)water++;
				if (Map[i][j + 1] == 0)water++;
				if (Map[i][j - 1] == 0)water++;
				v.push_back({ {j,i},water });
			}
		for (pair<pair<int, int>, int>p : v)
		{
			int x = p.first.first, y = p.first.second, water = p.second;
			Map[y][x] = (Map[y][x] - water >= 0) ? Map[y][x] - water : 0;
		}
		if (!iceCheck()) { cout << "0"; break; }
		year++;
	}
	return 0;
}

