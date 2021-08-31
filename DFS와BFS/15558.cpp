#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
using namespace std;
struct pos { int x, y, t; };
int N, K;
char Map[2][100001];
bool v[2][100001];
int main()
{
	scanf("%d %d %s %s", &N, &K, Map[0], Map[1]);
	queue<pos>q; q.push({ 0,0,0 }); v[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, t = q.front().t; q.pop();
		int dx[3] = { -1,1,K }, dy[3] = { y,y,!y };
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i], ny = dy[i];
			if (nx >= N) { printf("1"); return 0; }
			if (nx < 0 || nx <= t || Map[ny][nx] == '0' || v[ny][nx])continue;
			q.push({ nx,ny,t + 1 }); v[ny][nx] = 1;
		}
	}printf("0");
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);