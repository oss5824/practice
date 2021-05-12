#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M;
char Map[1000][1001];
int Fire[1000][1000],JiHoon[1000][1000];
int px, py;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
queue<pair<int, int>>q;
void bfs()
{
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N ||
				Fire[nextY][nextX] <= Fire[curY][curX] + 1
				|| Map[nextY][nextX] == '#' || Map[nextY][nextX] == 'F')continue;
			q.push({ nextX,nextY }); Fire[nextY][nextX] = Fire[curY][curX] + 1;
		}
	}
	q.push({ px,py });
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		if (curX == 0 || curX == M - 1 || curY == 0 || curY == N - 1){
			cout << JiHoon[curY][curX] + 1; return;
		}
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || JiHoon[nextY][nextX] != 0 ||
				Fire[nextY][nextX] <= JiHoon[curY][curX] + 1 || Map[nextY][nextX] == '#')continue;
			q.push({ nextX,nextY }); JiHoon[nextY][nextX] = JiHoon[curY][curX] + 1;
		}
	}
	cout << "IMPOSSIBLE";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			Fire[i][j] = INF;
			if (Map[i][j] == 'J') { px = j, py = i; }
			if (Map[i][j] == 'F') { q.push({ j,i }); Fire[i][j]=0;}
		}
	bfs();
	return 0;
}