#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
using namespace std;
typedef unsigned long long ull;
int N, M;
char Map[10][11];
pair<int, int>red, blue;
typedef pair<pair<int, int>, pair<int, int>> pp;
bool visit[10][10][10][10];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
//¼­ ºÏ µ¿ ³²
bool range(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N || Map[y][x] == '#')return false;
	return true;
}
void bfs() 
{
	queue<pair<pp, int>>q; q.push({ {red,blue},0 });
	visit[red.second][red.first][blue.second][blue.first] = true;
	while (!q.empty()) {
		pp cur = q.front().first;
		int redX = cur.first.first, redY = cur.first.second;
		int blueX = cur.second.first, blueY = cur.second.second;
		int curS = q.front().second; q.pop();
		if (Map[redY][redX] == 'O' && curS <= 10) { cout << "1"; return; }
		if (curS > 10) { cout << "0"; return; }
		for (int i = 0; i < 4; i++) {
			int redNX = redX, redNY = redY, blueNX = blueX, blueNY = blueY;
			while (range(redNX + dx[i], redNY + dy[i])){
				redNX = redNX + dx[i]; redNY = redNY + dy[i];
				if (Map[redNY][redNX] == 'O')break;
			}
			while (range(blueNX + dx[i], blueNY + dy[i])){
				blueNX = blueNX + dx[i]; blueNY = blueNY + dy[i];
				if (Map[blueNY][blueNX] == 'O')break;
			}
			if (Map[blueNY][blueNX] == 'O')continue;
			if (Map[redNY][redNX] == 'O' && Map[blueNY][blueNX] == 'O')continue;
			if (redNX == blueNX && redNY == blueNY)
			{
				if (i == 0) { if (redX < blueX)blueNX++; else redNX++; }
				else if (i == 1) { if (redY < blueY)blueNY++; else redNY++; }
				else if (i == 2) { if (redX < blueX)redNX--; else blueNX--; }
				else if (i == 3) { if (redY > blueY)blueNY--; else redNY--; }
			}
			if (visit[redNY][redNX][blueNY][blueNX])continue;
			visit[redNY][redNX][blueNY][blueNX] = true;
			pp next = { {redNX,redNY},{blueNX,blueNY} };
			q.push({ next,curS + 1 });
		}
	}
	cout << "0";
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> Map[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			if (Map[i][j] == 'R')red = { j,i };
			else if (Map[i][j] == 'B')blue = { j,i };
		}
	bfs();
	return 0;
}

