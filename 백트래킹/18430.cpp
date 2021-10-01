#pragma warning(disable: 4996)
#include<stdio.h>
int N, M, Map[5][5], res;
int mv[12][2] = { {1,0},{0,0},{0,1},{0,0} ,
	{1,0},{1,1},{0,0},{0,1},{1,1},{1,0},{1,1},{0,1} };
bool visit[5][5];
bool range(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N || visit[y][x])return false;
	return true;
}
void solve(int x, int y, int sum)
{
	for (int i = y; i < N; i++) {
		for (int j = x; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx1 = j + mv[3 * k][0], ny1 = i + mv[3 * k][1];
				int nx2 = j + mv[3 * k + 1][0], ny2 = i + mv[3 * k + 1][1];
				int nx3 = j + mv[3 * k + 2][0], ny3 = i + mv[3 * k + 2][1];
				if (!range(nx1, ny1) || !range(nx2, ny2) || !range(nx3, ny3))continue;
				visit[ny1][nx1] = true; visit[ny2][nx2] = true; visit[ny3][nx3] = true;
				int result = sum + Map[ny1][nx1] + Map[ny2][nx2] * 2 + Map[ny3][nx3];
				if (result > res)res = result;
				solve(j, i, result);
				visit[ny1][nx1] = false; visit[ny2][nx2] = false; visit[ny3][nx3] = false;
			}
		}x = 0;
	}
}
int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)scanf("%d", &Map[i][j]);
	solve(0, 0, 0); printf("%d", res);
}