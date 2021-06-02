#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, T;
int Map[100][100];
int Cache[100][100][2];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
pair<int, int>sword;
void bfs()
{
	queue<pair<pair<int, int>, pair<int, int>>>q; q.push({ {0,0},{0,0} });
	Cache[0][0][0] = 0; bool check = false;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curT = q.front().second.first, curD = q.front().second.second; q.pop();
		if (curT > T) break;
		if (curX == M - 1 && curY == N - 1)continue;
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)continue;
			if (Cache[nextY][nextX][curD] != INF)continue;
			if (curD == 0 && Map[nextY][nextX] == 1)continue;
			if (nextX == sword.first && nextY == sword.second)
			{
				q.push({ {nextX,nextY},{curT + 1,0} });
				Cache[nextY][nextX][0] = Cache[curY][curX][0] + 1;
				q.push({ {nextX,nextY},{curT + 1,1} });
				Cache[nextY][nextX][1] = Cache[curY][curX][0] + 1;
				continue;
			}
			if (Cache[nextY][nextX][curD] > Cache[curY][curX][curD] + 1)
			{
				Cache[nextY][nextX][curD] = Cache[curY][curX][curD] + 1;
				q.push({ {nextX,nextY},{curT + 1,curD} });
			}
		}
	}
	if (Cache[N - 1][M - 1][0] == INF && Cache[N - 1][M - 1][1] == INF)cout << "Fail";
	else cout << min(Cache[N - 1][M - 1][0], Cache[N - 1][M - 1][1]);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			cin >> Map[i][j];
			if (Map[i][j] == 2)sword = { j,i };
			Cache[i][j][0] = INF; Cache[i][j][1] = INF;
		}
	bfs();
	return 0;
}