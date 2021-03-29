#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Shark
{
	int x, y, speed, direction, sz, die;
};
int R, C, M, result;
int visit[101][101];
Shark shark[10001];
void Die(int x)
{
	for (int i = 1; i <= R; i++)
		if (visit[i][x] != 0)
		{
			result += shark[visit[i][x]].sz;
			shark[visit[i][x]].die = 0; visit[i][x] = 0; break;
		}
}
void solve()
{
	for (int i = 1; i <= C; i++)
	{
		Die(i); vector<int>EqualPos[101][101];
		for (int j = 1; j <= M; j++)
		{
			int x = shark[j].x, y = shark[j].y, speed = shark[j].speed;
			int direction = shark[j].direction, sz = shark[j].sz, die = shark[j].die;
			if (die == 0)continue;
			visit[y][x] = 0;
			for (int k = 0; k < speed; k++)
			{//1,2위 아래 3,4오른쪽 왼쪽
				if (direction == 1) {
					if (y == 1) { direction = 2; y = 2; }
					else y--;
				}
				else if (direction == 2) {
					if (y == R) { direction = 1; y = R - 1; }
					else y++;
				}
				else if (direction == 3) {
					if (x == C) { direction = 4; x = C - 1; }
					else x++;
				}
				else if (direction == 4) {
					if (x == 1) { direction = 3; x = 2; }
					else x--;
				}
			}
			shark[j] = { x,y,speed,direction,sz,1 };
			EqualPos[y][x].push_back(j);
		}
		for (int j = 1; j <= R; j++)
		{
			for (int k = 1; k <= C; k++)
			{
				int sz = EqualPos[j][k].size();
				if (sz == 0)continue;
				else if (sz == 1)visit[j][k] = EqualPos[j][k][0];
				else
				{
					int maxIdx = 0;
					for (int q = 0; q < sz; q++)maxIdx = max(maxIdx, shark[EqualPos[j][k][q]].sz);
					for (int q = 0; q < sz; q++)
					{
						if (shark[EqualPos[j][k][q]].sz == maxIdx)visit[shark[EqualPos[j][k][q]].y][shark[EqualPos[j][k][q]].x] = EqualPos[j][k][q];
						else shark[EqualPos[j][k][q]].die = 0;
					}
				}
			}
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++)
	{
		int y, x, speed, direction, sz;
		cin >> y >> x >> speed >> direction >> sz;
		visit[y][x] = i;
		shark[i] = { x,y,speed,direction,sz,1 };
	}
	if (M == 0) { cout << "0"; return 0; }
	solve();
	cout << result;
	return 0;
}