#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
using namespace std;

int N, M, Map[500][500];
pair<int, int>Cache[500][500];
int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };
bool check(int x, int y)
{
	for (int i = 0; i < 8; i++){
		int nextX = x + dx[i], nextY = y + dy[i];
		if (nextX < 0 || nextX >= M || nextY<0 || nextY >= N || Map[nextY][nextX]>Map[y][x])continue;
		return false;
	}
	return true;
}
pair<int,int> dfs(int x, int y)
{
	if (check(x, y)) return { x,y };
	if (Cache[y][x].first != -1)return Cache[y][x];
	int nx = 0, ny = 0, res = INT_MAX;
	for (int i = 0; i < 8; i++) {
		int nextX = x + dx[i], nextY = y + dy[i];
		if (nextX < 0 || nextX >= M || nextY<0 || nextY >= N || Map[nextY][nextX]>Map[y][x])continue;
		if (res > Map[nextY][nextX]) { nx = nextX, ny = nextY, res = Map[nextY][nextX]; }
	}
	Cache[y][x] = dfs(nx, ny);
	return Cache[y][x];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) { cin >> Map[i][j]; Cache[i][j] = { -1,-1 }; }
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)Cache[i][j] = dfs(j, i);
	memset(Map, 0, sizeof(Map));
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)Map[Cache[i][j].second][Cache[i][j].first]++;
	for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++)cout << Map[i][j] << " "; cout << "\n"; }
	return 0;
}