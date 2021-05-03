#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
using namespace std;

int N, M;
char Map[500][501];
bool visit[500][501];
int Cache[500][500];
bool check(int x, int y) { if (x < 0 || x >= M || y < 0 || y >= N)return true; else return false; }
int dfs(int x, int y)
{
	if (check(x, y))return 1;
	if (visit[y][x])return Cache[y][x];
	visit[y][x] = true;
	if (Map[y][x] == 'R')Cache[y][x] = dfs(x + 1, y);
	else if (Map[y][x] == 'L')Cache[y][x] = dfs(x - 1, y);
	else if (Map[y][x] == 'U')Cache[y][x] = dfs(x, y - 1);
	else if (Map[y][x] == 'D')Cache[y][x] = dfs(x , y + 1);
	return Cache[y][x];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; for (int i = 0; i < N; i++)cin >> Map[i];
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			sum += dfs(j, i);
		}
	cout << sum;
	return 0;
}