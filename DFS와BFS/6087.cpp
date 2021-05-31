#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
typedef unsigned long long ull;
int N, M;
char Map[100][101];
int Cache[100][100][4];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
pair<int, int>s, e;
void bfs()
{
	queue<pair<pair<int, int>, int>>q; 
	Cache[s.second][s.first][0] = 0;	Cache[s.second][s.first][1] = 0;
	Cache[s.second][s.first][2] = 0;	Cache[s.second][s.first][3] = 0;
	q.push({ s,0 }); q.push({ s,1 }); q.push({ s,2 }); q.push({ s,3 });
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curD = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N|| Map[nextY][nextX] == '*')continue;
			if (i == curD) {
				if (Cache[nextY][nextX][i] <= Cache[curY][curX][i])continue;
				q.push({ {nextX,nextY} ,i }); 
				Cache[nextY][nextX][i] = Cache[curY][curX][i];
			}
			else {
				if (Cache[nextY][nextX][i] <= Cache[curY][curX][curD])continue;
				q.push({ {nextX,nextY} ,i });
				Cache[nextY][nextX][i] = Cache[curY][curX][curD] + 1;
			}
		}
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> M >> N;
	bool check = false;
	for (int i = 0; i < N; i++)cin >> Map[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			Cache[i][j][0] = INF;Cache[i][j][1] = INF;
			Cache[i][j][2] = INF;Cache[i][j][3] = INF;
			if (Map[i][j] == 'C' && check == false) {
				s = { j,i }; check = true;
			}
			else if (Map[i][j] == 'C')e = { j,i };
		}
	bfs();
	int result = INF;
	for (int i = 0; i < 4; i++)result = min(result, Cache[e.second][e.first][i]);
	cout << result;
	return 0;
}

