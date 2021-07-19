#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N, M, T, result;
char Map[100][101];
pair<int, int>pos;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };

void dfs(int x, int y,int d,int cur, int t)
{
	result = max(result, cur);
	if (x < 0 || x >= M || y < 0 || y >= N || t == T || Map[y][x] == '#')return;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i], nextY = y + dy[i];
		char c = Map[nextY][nextX];
		if (c == '#')continue;
		if (c == 'S') {
			Map[nextY][nextX] = '.';
			dfs(nextX, nextY, i, cur + 1, t + 1);
			Map[nextY][nextX] = 'S';
		}
		else dfs(nextX, nextY, i, cur, t + 1);
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { cin >> Map[i][j]; if (Map[i][j] == 'G')pos = { j,i }; }
	for (int i = 0; i < 4; i++)dfs(pos.first, pos.second, i, 0, 0);
	cout << result;
	return 0;
}