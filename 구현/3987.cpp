#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
bool visit[500][500][4];
int N, M, sy, sx, res = -1;
char Map[500][501], c, k;
int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
int s[4] = { 1,0,3,2 }, bs[4] = { 3,2,1,0 };
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)scanf("%s", Map[i]);
	scanf("%d %d", &sy, &sx); sy--; sx--;
	char ch[] = { 'U','R','D','L' };
	for (int i = 0; i < 4; i++) {
		int x = sx, y = sy, cnt = 1, d = i; visit[y][x][d] = true;
		while (1) {
			x += dx[d], y += dy[d];
			if (x < 0 || x >= M || y < 0 || y >= N || Map[y][x] == 'C')break;
			if (visit[y][x][d]) { printf("%c\nVoyager", ch[i]); return 0; }
			visit[y][x][d] = true; cnt++; k = Map[y][x];
			if (k == '.') {}else if (k == '/')d = s[d]; else d = bs[d];
		}
		if (res < cnt) { res = cnt; c = ch[i]; } memset(visit, false, sizeof(visit));
	}printf("%c\n%d", c, res);
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
