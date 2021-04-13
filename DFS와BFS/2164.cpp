#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, result = INF;
int Map[100][100];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void bfs(int x, int y,int color)
{
	queue<pair<int, int>>q; q.push({ x,y }); Map[y][x] = color;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N
				|| Map[nextY][nextX] != 1)continue;
			q.push({ nextX,nextY }); Map[nextY][nextX] = color;
		}
	}
}
void bridge(int x, int y, int color)
{
	queue<pair<pair<int, int>, int>>q; q.push({ { x,y },0 });
	bool visit[100][100]; memset(visit, false, sizeof(visit));
	visit[y][x] = true;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curD = q.front().second; q.pop();
		if (Map[curY][curX] != 0 && Map[curY][curX] != color) { curD--; result = min(result, curD); break; }
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N
				|| Map[nextY][nextX] == color || visit[nextY][nextX])continue;
			q.push({ { nextX,nextY },curD + 1 }); visit[nextY][nextX] = true;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int color = 2;
	cin >> N; for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> Map[i][j];
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)if (Map[i][j] == 1) { bfs(j, i, color); color++; }
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) if (Map[i][j] != 0) { bridge(j, i, Map[i][j]); }
	cout << result;
	return 0;
}

