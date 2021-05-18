#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, M;
bool visit[1000][1000];
bool can = false;
char Map[1001][1001];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
void bfs(int x,int y)
{
	queue<pair<int, int>>q; q.push({ x, y }); visit[y][x] = true;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextY == N - 1) { can = true; return; }
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N
				|| visit[nextY][nextX] || Map[nextY][nextX] == '1')continue;
			q.push({ nextX,nextY }); visit[nextY][nextX] = true;
		}
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> Map[i];
	for (int j = 0; j < M; j++)
	{
		if (Map[0][j] == '0' && !visit[0][j]) { bfs(j, 0); }
		if (can) { cout << "YES"; return 0; }
	}
	cout << "NO";
	return 0;
}