#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#define LEFT 2
#define RIGHT 1
#define NONE 0
#define INF 987654321
using namespace std;
int N, M, H, result = INF;
int Ladder[30][10];
bool check()
{
	for (int x = 0; x < N; x++)
	{
		int pos = x;
		for (int y = 0; y < H; y++)
		{
			if (Ladder[y][pos] == RIGHT)pos++;
			else if (Ladder[y][pos] == LEFT)pos--;
		}
		if (pos != x)return false;
	}
	return true;
}
void solve(int pos, int cnt)
{
	if (check())result = min(result, cnt);
	if (pos >= N * H || cnt == 3)return;
	int x = pos % N, y = pos / N, ret = INF;
	if (x != N - 1 && Ladder[y][x] == NONE && Ladder[y][x + 1] == NONE)
	{
		Ladder[y][x] = RIGHT; Ladder[y][x + 1] = LEFT;
		solve(pos + 2, cnt + 1);
		Ladder[y][x] = NONE; Ladder[y][x + 1] = NONE;
	}
	solve(pos + 1, cnt );
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b; Ladder[a - 1][b - 1] = RIGHT; Ladder[a - 1][b] = LEFT;
	}
	solve(0, 0);
	(result == INF) ? cout << "-1" : cout << result;
	return 0;
}
