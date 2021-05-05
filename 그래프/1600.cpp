#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;

int N, M, K;
int Map[200][200];
bool visit[200][200][31];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int dx1[8] = { -2,-2,-1,-1,1,1,2,2 }, dy1[8] = { -1,1,-2,2,-2,2,-1,1 };
void bfs()
{
	queue<pair<pair<int, int>, pair<int, int>>>q; q.push({ { 0,0 },{0,0} }); visit[0][0][0] = true;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second; 
		int curD = q.front().second.first, curS = q.front().second.second; q.pop();

		if (curX == M - 1 && curY == N - 1) { cout << curD; return; }
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextY][nextX][curS]
				|| Map[nextY][nextX] == 1)continue;
			q.push({ {nextX,nextY},{curD + 1,curS} }); visit[nextY][nextX][curS] = true;
		}
		if (curS == K)continue;
		for (int i = 0; i < 8; i++)
		{
			int nextX = curX + dx1[i], nextY = curY + dy1[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextY][nextX][curS+1]
				|| Map[nextY][nextX] == 1)continue;
			q.push({ {nextX,nextY},{curD + 1,curS + 1} }); visit[nextY][nextX][curS + 1] = true;
		}
	}
	cout << "-1";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> K >> M >> N;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	bfs();
	return 0;
}