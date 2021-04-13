#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, M, K, res;
char Map[50][51];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void bfs(int x, int y)
{
	int Cache[50][50]; memset(Cache, 0, sizeof(Cache));
	queue<pair<int, int>>q; q.push({ x,y }); Map[y][x] = 'X';
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N
				|| Map[nextY][nextX] != 'L' || Cache[nextY][nextX] != 0)continue;
			q.push({ nextX,nextY }); Map[nextY][nextX] = 'X';
			Cache[nextY][nextX] = Cache[curY][curX] + 1;
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Cache[i][j] > result)result = Cache[i][j];
	res = max(result, res);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N>>M; for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	int start = 0;
	while (1)
	{
		int x = start % M, y = start / M;
		if (Map[y][x] == 'L') {
			char backUpMap[50][51]; memcpy(backUpMap, Map, sizeof(Map));
			bfs(x, y);
			memcpy(Map, backUpMap, sizeof(Map));
		}
		start++;
		if (start >= N * M)break;
	}
	cout << res;
	return 0;
}

