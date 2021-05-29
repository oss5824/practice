#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, result;
char Map[50][51];
bool visit[50][50];
int Cache[50][50];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
bool check = false;
int dfs(int x, int y)
{
	if (visit[y][x]) { check = true; return -1; }
	if (Cache[y][x] != 0)return Cache[y][x];
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		if (check)return -1;
		int sz = Map[y][x] - '0';
		int nextX = x + dx[i] * sz, nextY = y + dy[i] * sz;
		if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N ||
			Map[nextY][nextX] == 'H') continue;
		Cache[y][x] = max(Cache[y][x], dfs(nextX, nextY) + 1);
		visit[nextY][nextX] = false;
	}
	visit[y][x] = false;
	return Cache[y][x];
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> Map[i];
	int val = dfs(0, 0);
	if (check)cout << "-1";
	else cout << val + 1;
	return 0;
}