#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, H, W, Map[1000][1000];
int sx, sy, ex, ey;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
bool visit[1000][1000];
bool check(int bx, int by, int x, int y, int direction)
{
	if (x < 0 || x + W > M || y < 0 || y + H > N || visit[y][x])return false;
	if (direction == 0) { for (int i = y; i < y + H; i++)if (Map[i][x] == 1)return false; }
	else if (direction == 2) { for (int i = y; i < y + H; i++)if (Map[i][bx + W] == 1)return false; }
	else if (direction == 1) { for (int i = x; i < x + W; i++)if (Map[y][i] == 1)return false; }
	else if (direction == 3) { for (int i = x; i < x + W; i++)if (Map[by + H][i] == 1)return false; }
	return true;
}
void bfs()
{
	queue<pair<pair<int, int>, int>>q; q.push({ {sx,sy},0 }); visit[sy][sx] = true;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curD = q.front().second; q.pop();
		if (curX == ex && curY == ey) { cout << curD; return; }
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (!check(curX, curY, nextX, nextY, i))continue;
			q.push({ {nextX,nextY},curD + 1 }); visit[nextY][nextX] = true;
		}
	}
	cout << "-1";
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	cin >> H >> W >> sy >> sx >> ey >> ex;
	sy--, sx--, ey--, ex--;
	bfs();
	return 0;
}

