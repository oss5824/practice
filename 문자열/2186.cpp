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
int N, M, K, len;
char Map[100][101];
int Cache[100][100][81];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
string s;
int dfs(int x, int y, int idx)
{
	if (idx == len - 1)return 1;

	int& ret = Cache[y][x][idx];
	if (ret != -1)return ret;
	ret = 0;

	for (int step = 1; step <= K; step++) {
		for (int i = 0; i < 4; i++) {
			int nextX = x + dx[i] * step, nextY = y + dy[i] * step;
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)continue;
			if (s[idx + 1] != Map[nextY][nextX])continue;
			ret += dfs(nextX, nextY, idx + 1);
		}
	}
	return ret;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)cin >> Map[i];
	cin >> s; len = s.size(); memset(Cache, -1, sizeof(Cache));
	int result = 0;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] == s[0])result += dfs(j, i, 0);
	cout << result;
	return 0;
}
