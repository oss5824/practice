#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
int N, M, x, y, K;
using namespace std;
int Map[20][20];
int Left, Right, Back, Front, Top, Bottom;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	for (int i = 0; i < K; i++)
	{
		int direction;
		cin >> direction;

		if (direction == 1 && x == M - 1)continue;else if (direction == 2 && x == 0)continue;
		else if (direction == 3 && y == 0)continue;else if (direction == 4 && y == N - 1)continue;

		if (direction == 1) { int tmp = Top; Top = Left; Left = Bottom; Bottom = Right; Right = tmp; x++; }
		else if (direction == 2) { int tmp = Top; Top = Right; Right = Bottom; Bottom = Left; Left = tmp; x--; }
		else if (direction == 3) { int tmp = Top; Top = Front; Front = Bottom; Bottom = Back; Back = tmp; y--; }
		else if (direction == 4) { int tmp = Top; Top = Back; Back = Bottom; Bottom = Front; Front = tmp; y++; }

		if (Map[y][x] == 0)Map[y][x] = Bottom;
		else { Bottom = Map[y][x]; Map[y][x] = 0; }
		cout << Top << "\n";
	}
	return 0;
}
