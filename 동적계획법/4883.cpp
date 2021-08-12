#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, Map[100000][3], dp[100000][3][4];
int solve(int x, int y, int up)
{
	if (y == 0) {
		if (x == 0 || x == 1)return Map[y][1];
		return dp[y][x][up] = min(solve(1, y, 3) + Map[y][x], dp[y][x][up]);
	}
	if (dp[y][x][up] != 1e9)return dp[y][x][up];
	if (x == 0) {
		dp[y][x][up] = min(solve(0, y - 1, 1) + Map[y][x], dp[y][x][up]);
		dp[y][x][up] = min(solve(1, y - 1, 2) + Map[y][x], dp[y][x][up]);
	}
	else if (x == 1){
		dp[y][x][up] = min(solve(0, y - 1, 0) + Map[y][x], dp[y][x][up]);
		dp[y][x][up] = min(solve(1, y - 1, 1) + Map[y][x], dp[y][x][up]);
		dp[y][x][up] = min(solve(2, y - 1, 2) + Map[y][x], dp[y][x][up]);
		dp[y][x][up] = min(solve(0, y, 3) + Map[y][x], dp[y][x][up]);
	}
	else {
		dp[y][x][up] = min(solve(1, y - 1, 0) + Map[y][x], dp[y][x][up]);
		dp[y][x][up] = min(solve(2, y - 1, 1) + Map[y][x], dp[y][x][up]);
		dp[y][x][up] = min(solve(1, y, 3) + Map[y][x], dp[y][x][up]);
	}
	return dp[y][x][up];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int t = 1;; t++) {
		cin >> N; if (N == 0)break;
		for (int i = 0; i < N; i++)for (int j = 0; j < 3; j++) {
			cin >> Map[i][j]; for (int k = 0; k < 4; k++)dp[i][j][k] = 1e9;
		}Map[0][0] = 0;
		cout << t << ". " << min(min(solve(0, N - 2, 0), solve(1, N - 2, 1)),
			min(solve(2, N - 2, 2), solve(0, N - 1, 3))) + Map[N - 1][1] << "\n";
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);