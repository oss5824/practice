#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#define INF 987654321
using namespace std;
int N, M;
int Map[1000][1000];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M; 
	int start = N * N + 1, x = 1, y = 1, direction = 2;
	//0À§ 1¿À 2¾Æ3¿Þ
	while (--start) {
		Map[y][x] = start;
		if (direction == 2) {
			if (y + 1 > N || Map[y + 1][x] != 0) { direction = 1; x++; }
			else y++;
		}
		else if (direction == 1) {
			if (x + 1 > N || Map[y][x + 1] != 0) { direction = 0; y--; }
			else x++;
		}
		else if (direction == 0) {
			if (y - 1 < 1 || Map[y - 1][x] != 0) { direction = 3; x--; }
			else y--;
		}
		else if (direction == 3) {
			if (x - 1 < 1 || Map[y][x - 1] != 0) { direction = 2; y++; }
			else x--;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) { cout << Map[i][j] << " "; if (Map[i][j] == M) { x = j; y = i; } }
		cout << "\n";
	}cout << y << " " << x;
	return 0;
}

