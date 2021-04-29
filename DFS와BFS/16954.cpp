#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<limits.h>
#define INF INT_MAX
using namespace std;
char Map[10][10][10];
bool visit[10][10][10];
int dx[9] = { -1,-1,-1,0,0,0,1,1,1 }, dy[9] = { -1,0,1,-1,0,1,-1,0,1 };
void make_map()
{
	for (int k = 1; k <= 9; k++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 7; i++)Map[k][i][j] = Map[k - 1][i + 1][j];
			Map[k][7][j] = '.';
		}
	}
}
void bfs()
{
	queue<pair<pair<int, int>, int>>q; q.push({ { 0,0 },0 }); visit[0][0][0] = true;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second, curS = q.front().second;

		q.pop();
		if (curX == 7 && curY == 7) { cout << "1"; return; }
		if (curS >= 8)curS = 8;
		for (int i = 0; i < 9; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX>7 || nextY < 0 || nextY>7 || visit[curS+1][nextY][nextX]
				|| Map[curS + 1][nextY][nextX] == '#' || Map[curS][nextY][nextX] == '#')continue;
			q.push({ {nextX,nextY},curS + 1 }); visit[curS + 1][nextY][nextX] = true;
		}
	}
	cout << "0";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 7; i >= 0; i--)for (int j = 0; j < 8; j++)cin >> Map[0][i][j];
	make_map();
	bfs();
	return 0;
}

