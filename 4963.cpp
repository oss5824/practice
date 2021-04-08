#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, M, cnt;
int Map[50][50];
bool visit[50][50];
int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,1,-1,-1,0,1 };
void bfs(int x, int y)
{
	queue<pair<int, int>>q; q.push({ x,y }); visit[y][x] = true;
	while (!q.empty())
	{
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextY][nextX] || Map[nextY][nextX] == 0)continue;
			q.push({ nextX,nextY }); visit[nextY][nextX] = true;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (1)
	{
		cin >> M >> N;
		if (M == 0 && N == 0)break;
		memset(Map, 0, sizeof(Map)); memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
		cnt = 0;
		for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) { if (Map[i][j] == 0 || visit[i][j])continue; cnt++; bfs(j, i); }
		cout << cnt << "\n";
	}
	return 0;
}

