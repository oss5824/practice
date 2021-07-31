#include<stdio.h>
#include<math.h>
#include<queue>
#include<cstring>

using namespace std;
int N, M, V, Y, X, Map[101][101], visit[101][101], height, time = 1e9;
bool check[101][101];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int main()
{
	scanf("%d %d %d %d %d", &N, &M, &V, &Y, &X);
	for (int i = 1, a; i <= N; i++)for (int j = 1; j <= M; j++) { scanf("%d", &a); Map[i][j] = a; visit[i][j] = 1e9; }
	while (V--) {
		int y, x, t; scanf("%d %d %d", &y, &x, &t);
		queue<pair<pair<int, int>, int>>q; q.push({ {x,y},t }); visit[y][x] = min(visit[y][x], t); check[y][x] = true;
		while (!q.empty()) {
			int curX = q.front().first.first, curY = q.front().first.second, curT = q.front().second; q.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = curX + dx[i], nextY = curY + dy[i];
				if (nextX <= 0 || nextX > M || nextY <= 0 || nextY > N || visit[nextY][nextX] <= curT + 1)continue;
				q.push({ {nextX,nextY},curT + 1 }); visit[nextY][nextX] = curT + 1;
			}
		}
	}
	queue<pair<pair<int, int>, int>>q; q.push({ {X,Y},0 }); check[Y][X] = true;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second, curT = q.front().second;
		if (height <= Map[curY][curX]) { height = Map[curY][curX]; time = curT; }
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX <= 0 || nextX > M || nextY <= 0 || nextY > N || check[nextY][nextX] || visit[nextY][nextX] <= curT + 1)
				continue;
			q.push({ {nextX,nextY},curT + 1 }); check[nextY][nextX] = true;
		}
	}printf("%d %d", height, time);
}