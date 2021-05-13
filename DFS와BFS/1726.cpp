#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, result, Map[101][101];
int Cache[101][101][5];
int sx, sy, sd, ex, ey, ed;
int dx[5] = { 0,1,-1,0,0 }, dy[5] = { 0,0,0,1,-1 };
//1 2 3 4 µ¿ ¼­ ³² ºÏ
bool range(int x, int y,int d)
{
	if (x < 1 || x > M || y < 1 || y > N || Map[y][x] == 1)return false;
	return true;
}
void bfs()
{
	queue<pair<pair<int, int>, int>>q; q.push({ { sx,sy },sd }); Cache[sy][sx][sd] = 0;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curD = q.front().second; q.pop();
		if (curX == ex && curY == ey && ed == curD)continue;
		int d1 = 0, d2 = 0, d3 = 0;
		if (curD == 1 || curD == 2) { d1 = 3; d2 = 4; }
		if (curD == 3 || curD == 4) { d1 = 1; d2 = 2; }
		if (curD == 1)d3 = 2; if (curD == 2)d3 = 1; if (curD == 3)d3 = 4; if (curD == 4)d3 = 3;
		if (Cache[curY][curX][d1] > Cache[curY][curX][curD] + 1) {
			Cache[curY][curX][d1] = Cache[curY][curX][curD] + 1; q.push({ {curX,curY},d1 });
		}
		if (Cache[curY][curX][d2] > Cache[curY][curX][curD] + 1) {
			Cache[curY][curX][d2] = Cache[curY][curX][curD] + 1; q.push({ {curX,curY},d2 });
		}
		if (Cache[curY][curX][d3] > Cache[curY][curX][curD] + 2) {
			Cache[curY][curX][d3] = Cache[curY][curX][curD] + 2; q.push({ {curX,curY},d3 });
		}
		int nextX=curX, nextY=curY;
		for (int i = 0; i < 3; i++)
		{
			nextX = nextX + dx[curD]; nextY = nextY + dy[curD];
			if (!range(nextX, nextY, curD))break;
			if (Cache[nextY][nextX][curD] > Cache[curY][curX][curD] + 1)
			{
				q.push({ {nextX,nextY}, curD }); Cache[nextY][nextX][curD] = Cache[curY][curX][curD] + 1;
			}
		}
	}
	cout << Cache[ey][ex][ed];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> Map[i][j];
			for (int k = 1; k <= 4; k++)Cache[i][j][k] = INF;
		}
	cin >> sy >> sx >> sd >> ey >> ex >> ed;
	bfs();
	return 0;
}