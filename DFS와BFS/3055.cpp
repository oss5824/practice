#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, M;
char Map[50][51];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int visitMouse[50][50];
int visitWater[50][50];
queue<pair<int, int>>water;
queue<pair<int, int>>mouse;
void bfs()
{
	while (!water.empty()) {
		int curX = water.front().first, curY = water.front().second; water.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || Map[nextY][nextX] == 'X'
				|| visitWater[nextY][nextX] != -1 || Map[nextY][nextX] == 'D')continue;
			water.push({ nextX,nextY }); visitWater[nextY][nextX] = visitWater[curY][curX] + 1;
		}
	}
	while (!mouse.empty()) {
		int curX = mouse.front().first, curY = mouse.front().second; mouse.pop();
		if (Map[curY][curX] == 'D') { cout << visitMouse[curY][curX] << "\n"; return; }
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || Map[nextY][nextX] == 'X'
				|| visitMouse[nextY][nextX] != -1)continue;
			if (Map[nextY][nextX] != 'D' && (visitWater[nextY][nextX] != -1 && (visitWater[nextY][nextX] <= visitMouse[curY][curX] + 1)))continue;
			mouse.push({ nextX,nextY }); visitMouse[nextY][nextX] = visitMouse[curY][curX] + 1;
		}
	}

	cout << "KAKTUS" << "\n";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; 
	memset(visitMouse, -1, sizeof(visitMouse)); memset(visitWater, -1, sizeof(visitWater));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == '*') { water.push({ j,i }); visitWater[i][j] = 0; }
			else if (Map[i][j] == 'S') { mouse.push({ j,i }); visitMouse[i][j] = 0; }
		}
	bfs();
	return 0;
}


