#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int Z, Y, X, EZ, EY, EX;
char Map[31][31][31];
bool visit[30][30][30];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 }, dz[2] = { -1,1 };
queue<pair<pair<int, int>, pair<int, int>>>q;
void bfs()
{
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curZ = q.front().second.first, curD = q.front().second.second;
		q.pop();
		if (curX == EX && curY == EY && curZ == EZ)
		{
			cout << "Escaped in " << curD << " minute(s).\n"; return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= X || nextY < 0 || nextY >= Y
				|| visit[curZ][nextY][nextX] || Map[curZ][nextY][nextX] == '#')continue;
			q.push({ {nextX,nextY},{curZ,curD + 1} });
			visit[curZ][nextY][nextX] = true;
		}
		for (int i = 0; i < 2; i++)
		{
			int nextZ = curZ + dz[i];
			if (nextZ < 0 || nextZ >= Z || visit[nextZ][curY][curX]
				|| Map[nextZ][curY][curX] == '#')continue;
			q.push({ {curX,curY},{nextZ,curD + 1} });
			visit[nextZ][curY][curX] = true;
		}
	}
	cout << "Trapped!\n";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (1)
	{
		cin >> Z >> Y >> X;
		if (Z == 0 && Y == 0 && X == 0)break; while (!q.empty())q.pop();
		memset(Map, 0, sizeof(Map)); memset(visit, false, sizeof(visit));
		for (int z = 0; z < Z; z++)
			for (int y = 0; y < Y; y++)
				for (int x = 0; x < X; x++)
				{
					cin >> Map[z][y][x];
					if (Map[z][y][x] == 'S') { q.push({ {x,y},{z,0} }); visit[z][y][x] = true; }
					else if (Map[z][y][x] == 'E') { EZ = z; EY = y; EX = x; }
				}
		bfs();
	}

	return 0;
}

