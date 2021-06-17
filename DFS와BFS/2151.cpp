#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<limits.h>
#include<string>
#include<queue>
#define INF 1e9
typedef unsigned long long ull;
using namespace std;
char Map[50][51];
int Cache[50][50][4];
int N;
bool find_start = false;
pair<int, int>start, finish;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
void bfs()
{
	queue<pair<pair<int, int>, int>>q;
	q.push({ start,0 }); q.push({ start,1 }); q.push({ start,2 }); q.push({ start,3 });

	Cache[start.second][start.first][0] = 0; Cache[start.second][start.first][1] = 0;
	Cache[start.second][start.first][2] = 0; Cache[start.second][start.first][3] = 0;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curD = q.front().second;
		q.pop();
		int nextX = curX + dx[curD], nextY = curY + dy[curD];
		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || Map[nextY][nextX] == '*')continue;
		if (Cache[curY][curX][curD] < Cache[nextY][nextX][curD]) {
			Cache[nextY][nextX][curD] = Cache[curY][curX][curD];
			q.push({ {nextX,nextY},curD });
		}
		if (Map[nextY][nextX] == '!')
		{
			int nextD1 = 0, nextD2 = 0;
			if (curD == 0 || curD == 2) { nextD1 = 1, nextD2 = 3; }
			else if (curD == 1 || curD == 3) { nextD1 = 0, nextD2 = 2; }
			if (Cache[curY][curX][curD] < Cache[nextY][nextX][nextD1]) {
				Cache[nextY][nextX][nextD1] = Cache[curY][curX][curD] + 1;
				q.push({ {nextX,nextY},nextD1 });
			}
			if (Cache[curY][curX][curD] + 1 < Cache[nextY][nextX][nextD2]) {
				Cache[nextY][nextX][nextD2] = Cache[curY][curX][curD] + 1;
				q.push({ {nextX,nextY},nextD2 });
			}
		}
		
	}
	int result = INF; for (int i = 0; i < 4; i++)result = min(result, Cache[finish.second][finish.first][i]);
	cout << result;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N; for (int i = 0; i < N; i++)cin >> Map[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == '#' && !find_start) { start = { j,i }; find_start = true; }
			else if (Map[i][j] == '#' && find_start) { finish = { j,i }; }
			Cache[i][j][0] = INF; Cache[i][j][1] = INF; Cache[i][j][2] = INF; Cache[i][j][3] = INF;
		}
	bfs();
	return 0;
}


