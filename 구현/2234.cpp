#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, M, Map[51][51][4];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
//¼­ ºÏ µ¿ ³²
//0¼­1ºÏ2µ¿3³²
int visit[51][51];
int result = 0;
vector<int>v;
void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>>q; q.push({ x,y }); visit[y][x] = cnt;
	int count = 1;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextY][nextX] != 0)continue;
			if (i == 0 && Map[nextY][nextX][2] == 1)continue;
			if (i == 1 && Map[nextY][nextX][3] == 1)continue;
			if (i == 2 && Map[nextY][nextX][0] == 1)continue;
			if (i == 3 && Map[nextY][nextX][1] == 1)continue;
			q.push({ nextX,nextY }); visit[nextY][nextX] = cnt; count++;
		}
	}
	result = max(result, count);
	v.push_back(count);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> M >> N;
	int cnt = 1;
	v.push_back(0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int a, cnt = 0; cin >> a;
			while (a) { if (a & 1) { Map[i][j][cnt] = 1; }cnt++; a = a >> 1; }
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 0)bfs(j, i, cnt++);
		}
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int curX = j, curY = i;
			for (int k = 0; k < 4; k++)
			{
				int nextX = curX + dx[k], nextY = curY + dy[k];
				if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N
					|| visit[curY][curX] == visit[nextY][nextX])continue;
				res = max(res, v[visit[nextY][nextX]] + v[visit[curY][curX]]);
			}
		}
	}
	cout << cnt - 1 << "\n";
	cout << result << "\n";
	cout << res << "\n";
	return 0;
}