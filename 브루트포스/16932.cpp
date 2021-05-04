#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;

int N, M, result;
int Map[1000][1000];
int Group[1000][1000];
bool visit[1000][1000];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
vector<int>v;
int bfs(int x, int y, int group)
{
	queue<pair<int, int>>q; q.push({ x,y }); visit[y][x] = true; int cnt = 1; Group[y][x] = group;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || Map[nextY][nextX] == 0
				|| visit[nextY][nextX])continue;
			q.push({ nextX,nextY }); visit[nextY][nextX] = true; cnt++; Group[nextY][nextX] = group;
		}
	}
	return cnt;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	v.push_back(0);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	int group = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 0 || visit[i][j])continue;
			v.push_back(bfs(j, i, group));
			group++;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 1)continue;
			int curX = j, curY = i, sum = 1;
			int G[4] = { -1,-1,-1,-1 };
			for (int k = 0; k < 4; k++) {
				int nextX = curX + dx[k], nextY = curY + dy[k];
				if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || Group[nextY][nextX] == 0)continue;
				G[k] = Group[nextY][nextX];
				if (k == 1 && G[1] == G[0])continue;
				else if (k == 2 && (G[2] == G[0] || G[2] == G[1]))continue;
				else if (k == 3 && (G[3] == G[2] || G[3] == G[1] || G[3] == G[0]))continue;
				sum += v[Group[nextY][nextX]];
			}
			result = max(result, sum);
		}
	cout << result;
	return 0;
}