#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M, result;
int Map[500][500];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int bfs(int x, int y, int color)
{
	queue<pair<int, int>>q; q.push({ x,y }); Map[y][x] = color; int cnt = 1;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N|| Map[nextY][nextX] != 1)continue;
			q.push({ nextX,nextY }); Map[nextY][nextX] = color; cnt++;
		}
	}
	return cnt;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int color = 2;
	cin >> N >> M; for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] == 1)result = max(result, bfs(j, i, color++));
	cout << color - 2 << "\n" << result;
	return 0;
}

