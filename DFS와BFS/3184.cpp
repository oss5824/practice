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
char Map[250][251];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int result_sheep, result_wolf;
void bfs(int x, int y)
{
	queue<pair<int, int>>q; q.push({ x,y }); 
	int sheep = 0, wolf = 0;
	if (Map[y][x] == 'o')sheep++; else if (Map[y][x] == 'v')wolf++;
	Map[y][x] = '#';
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N|| Map[nextY][nextX] == '#')continue;
			if (Map[nextY][nextX] == 'o')sheep++; else if (Map[nextY][nextX] == 'v')wolf++;
			q.push({ nextX,nextY }); Map[nextY][nextX] = '#';
		}
	}
	if (sheep > wolf)result_sheep += sheep; else result_wolf += wolf;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] != '#')bfs(j, i);
	cout << result_sheep << " " << result_wolf;
	return 0;
}

