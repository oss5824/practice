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
typedef pair<pair<int, int>, pair<int, int>>pp;
int N, M;
char Map[10][11];
pair<int, int>red, blue;
queue<pair<pp, int>>q;
bool visit[10][10][10][10];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool range(int x,int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N || Map[y][x] == '#')return false;
	return true;
}
void Setting(int x1, int y1, int x2, int y2, int num)
{
	pp next = { {x1,y1},{x2,y2} };
	visit[y1][x1][y2][x2] = true; q.push({ next,num + 1 });
}
void bfs()
{
	q.push({ { red,blue },0 });
	visit[red.second][red.first][blue.second][blue.first] = true;
	while (!q.empty()) {
		pp cur = q.front().first;
		int redX = cur.first.first, redY = cur.first.second;
		int blueX = cur.second.first, blueY = cur.second.second;
		int num = q.front().second;
		if (Map[redY][redX] == 'O') { cout << num; return; }
		q.pop();
		if (num > 10) { cout << "-1"; return; }
		for (int i = 0; i < 4; i++){
			int redX2 = redX, redY2 = redY, blueX2 = blueX, blueY2 = blueY;

			while (range(redX2 + dx[i], redY2 + dy[i])) {
				redX2 = redX2 + dx[i]; redY2 = redY2 + dy[i];
				if (Map[redY2][redX2] == 'O')break;
			}
			while (range(blueX2 + dx[i], blueY2 + dy[i])) {
				blueX2 = blueX2 + dx[i]; blueY2 = blueY2+ dy[i];
				if (Map[blueY2][blueX2] == 'O')break;
			}
			if (Map[blueY2][blueX2] == 'O')continue;
			if (Map[blueY2][blueX2] == 'O' && Map[redY2][redX2] == 'O')continue;
			if (redX2 == blueX2 && redY2 == blueY2) {
				if (i == 0) { if (redX < blueX)blueX2++; else redX2++; }
				else if (i == 2) { if (redX > blueX)blueX2--; else redX2--; }
				if (i == 1) { if (redY < blueY)redY2--; else blueY2--; }
				else if (i == 3) { if (redY > blueY)redY2++; else blueY2++; }
			}
			if (visit[redY2][redX2][blueY2][blueX2])continue;
			Setting(redX2, redY2, blueX2, blueY2, num);
		}
	}
	cout << "-1";
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> Map[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			if (Map[i][j] == 'B')blue = { j,i };
			else if (Map[i][j] == 'R')red = { j,i };
		}
	bfs();
	return 0;
}