#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R, C, T;
int Map[51][51];
struct Cleaner { int top_x, top_y, down_x, down_y; };
Cleaner cleaner = { 0,0,0,0 };
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void Spread()
{
	while (T--)
	{
		vector<int>store[51][51];
		for (int y = 1; y <= R; y++)
			for (int x = 1; x <= C; x++)
			{
				int& sum = Map[y][x]; int count = 0;
				if (sum == 0 || sum == -1)continue;
				for (int k = 0; k < 4; k++)
				{
					int nextX = x + dx[k], nextY = y + dy[k];
					if (nextX<1 || nextX>C || nextY < 1 || nextY > R || Map[nextY][nextX] == -1)continue;
					count++; store[nextY][nextX].push_back(sum / 5);
				}
				int spread = (sum / 5) * count;
				sum -= spread;
			}
		for (int y = 1; y <= R; y++)for (int x = 1; x <= C; x++)for (int val : store[y][x])Map[y][x] += val;
		int topX = cleaner.top_x, topY = cleaner.top_y, downX = cleaner.down_x, downY = cleaner.down_y;
		int x = topX, y = topY, idx = 0;
		if (x == 1)y--;
		else x--;
		while (!(x == topX && y == topY)) {
			if (idx == 0) {
				if (x == 1) { idx = 1; continue; }
				Map[y][x] = Map[y][x - 1]; x--;
			}
			else if (idx == 1) {
				if (y == 1) { idx = 2; continue; }
				Map[y][x] = Map[y - 1][x]; y--;
			}
			else if (idx == 2) {
				if (x == C) { idx = 3; continue; }
				Map[y][x] = Map[y][x + 1]; x++;
			}
			else if (idx == 3) {
				if (y == topY) { idx = 4; continue; }
				Map[y][x] = Map[y + 1][x]; y++;
			}
			else if (idx == 4){
				if (Map[y][x - 1] == -1) { Map[y][x] = 0; break; }
				Map[y][x] = Map[y][x - 1]; x--;
			}
		}
		x = downX, y = downY, idx = 0;
		if (x == 1)y++; else x--;
		while (!(x == downX && y == downY)) {
			if (idx == 0) {
				if (x == 1) { idx = 1; continue; }
				Map[y][x] = Map[y][x - 1]; x--;
			}
			else if (idx == 1) {
				if (y == R) { idx = 2; continue; }
				Map[y][x] = Map[y + 1][x]; y++;
			}
			else if (idx == 2) {
				if (x == C) { idx = 3; continue; }
				Map[y][x] = Map[y][x + 1]; x++;
			}
			else if (idx == 3) {
				if (y == downY) { idx = 4; continue; }
				Map[y][x] = Map[y - 1][x]; y--;
			}
			else if (idx == 4){
				if (Map[y][x - 1] == -1) { Map[y][x] = 0; break; }
				Map[y][x] = Map[y][x - 1]; x--;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= R; i++)for (int j = 1; j <= C; j++)if (Map[i][j] > 0)sum += Map[i][j];
	cout << sum;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == -1 && cleaner.top_x == 0) cleaner = { j,i,j,i + 1 };
		}
	Spread();
	return 0;
}