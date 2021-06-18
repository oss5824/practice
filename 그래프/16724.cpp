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
int N, M, result;
char Map[1000][1001];
int Cache[1000][1000];
bool visit[1000][1000];

int dfs(int x, int y)
{
	int& ret = Cache[y][x];
	if (ret != -1)return ret;
	if (visit[y][x])return ++result;
	visit[y][x] = true;
	if (Map[y][x] == 'D')return ret = dfs(x, y + 1);
	else if (Map[y][x] == 'L')return ret = dfs(x - 1, y);
	else if (Map[y][x] == 'R')return ret = dfs(x + 1, y);
	else if (Map[y][x] == 'U')return ret = dfs(x, y - 1);
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; for (int i = 0; i < N; i++)cin >> Map[i];
	memset(Cache, -1, sizeof(Cache));
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Cache[i][j] == -1)dfs(j, i);
	cout << result;
	return 0;
}
