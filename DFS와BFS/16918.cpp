#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;
char Map[200][201];
queue<pair<int, int>>q;
int N, M, K, T;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)cin >> Map[i];
	if (K % 2 == 0) {
		for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++)cout << 'O'; cout << "\n"; }
	}
	else {
		while (1) {
			for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] == 'O')q.push({ j,i });
			if (++T == K)break;
			for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)Map[i][j] = 'O';
			if (++T == K)break;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second; q.pop(); Map[y][x] = '.';
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
					Map[ny][nx] = '.';
				}
			}
		}
		for (int i = 0; i < N; i++) { for (int j = 0; j < M; j++)cout << Map[i][j]; cout << "\n"; }
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
