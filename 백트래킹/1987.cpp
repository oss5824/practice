#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, M, result;
char Map[20][21];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool visit[26];
void dfs(int x, int y, int cnt)
{
	result = max(result, cnt);
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i], nextY = y + dy[i];
		if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[Map[nextY][nextX] - 'A'])continue;
		visit[Map[nextY][nextX] - 'A'] = true; dfs(nextX, nextY, cnt + 1); visit[Map[nextY][nextX] - 'A'] = false;
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; 
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	visit[Map[0][0] - 'A'] = true; dfs(0, 0, 1);
	cout << result;
	return 0;
}

