#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, M, K;
char Map[100][101];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void bfs(int x, int y,char c)
{
	queue<pair<int, int>>q; q.push({ x,y }); Map[y][x] = 'X';
	while (!q.empty()){
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || Map[nextY][nextX] == 'X' || Map[nextY][nextX] != c)continue;
			q.push({ nextX,nextY }); Map[nextY][nextX] = 'X';
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> Map[i][j];
	char backUpMap[100][101]; memcpy(backUpMap, Map, sizeof(Map)); int cnt = 0;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)if (Map[i][j] != 'X') { bfs(j, i, Map[i][j]); cnt++; }
	cout << cnt << " "; 
	memcpy(Map, backUpMap, sizeof(Map)); cnt = 0;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)if (Map[i][j] == 'G')Map[i][j] = 'R';
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)if (Map[i][j] != 'X') { bfs(j, i, Map[i][j]); cnt++; }
	cout << cnt;
	return 0;
}

