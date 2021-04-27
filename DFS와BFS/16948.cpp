#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 1000000000
using namespace std;
int N, M, result = INF;
int dx[6] = { -1,1,-2,2,-1,1 }, dy[6] = { -2,-2,0,0,2,2 };
bool visit[200][200];
int sx, sy, ex, ey;
void bfs()
{
	queue<pair<pair<int, int>, int>>q; q.push({ { sx,sy } ,0 }); visit[sy][sx] = true;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second, curD = q.front().second;
		q.pop();
		if (curX == ex && curY == ey) { cout << curD; return; }
		for (int i = 0; i < 6; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || visit[nextY][nextX])continue;
			visit[nextY][nextX] = true;
			q.push({ { nextX,nextY },curD + 1 });
		}
	}
	cout << "-1";
}
int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> sy >> sx >> ey >> ex;
	bfs();
	return 0;
}