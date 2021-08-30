#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char M[7][7];
int N, n, sx[5], sy[5];
bool fin;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
void solve(int p, int cnt)
{
	bool c = true;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 4; k++) {
			int y = sy[i], x = sx[i];
			while (1) {
				x += dx[k], y += dy[k];
				if (x < 0 || x >= N || y < 0 || y >= N || M[y][x] == 'O')break;
				if (M[y][x] == 'S') { c = false; break; }
			}
			if (!c)break;
		}
		if (!c)break;
	}
	if (c) { fin = true; return; }
	if (fin || p == N * N || cnt == 3)return;
	for (int i = p; i < N * N; i++) {
		int y = i / N, x = i % N; if (M[y][x] != 'X')continue;
		M[y][x] = 'O'; solve(i + 1, cnt + 1); M[y][x] = 'X';
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) { scanf(" %c", &M[i][j]); if (M[i][j] == 'T')sx[n] = j, sy[n++] = i; }
	solve(0, 0);
	fin ? printf("YES") : printf("NO");
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
