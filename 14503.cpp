#include<iostream>
#include<algorithm>
using namespace std;
int N, M, Map[51][51];
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
int x, y, direction;
void solve()
{
	Map[y][x] = 2; int cnt = 0, cleaner = 1; 
	while (1)
	{
		int sub_direction = (direction == 0) ? 3 : direction - 1;
		int nextX = x + dx[sub_direction], nextY = y + dy[sub_direction];
		if (Map[nextY][nextX] == 0)
		{
			direction = sub_direction; x = nextX, y = nextY;
			Map[y][x] = 2; cleaner++;
		}
		else if ((Map[y - 1][x] == 1 || Map[y - 1][x] == 2) &&
			(Map[y + 1][x] == 1 || Map[y + 1][x] == 2) &&
			(Map[y][x - 1] == 1 || Map[y][x - 1] == 2) &&
			(Map[y][x + 1] == 1 || Map[y][x + 1] == 2))
		{
			if (direction == 0)y++; else if (direction == 2)y--;
			else if (direction == 1)x--; else if (direction == 3)x++;
			if (Map[y][x] == 1)break;
		}
		else if (Map[nextY][nextX] == 2 || Map[nextY][nextX] == 1)direction = sub_direction;
	}cout << cleaner;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	cin >> y >> x >> direction;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	solve();
	return 0;
}