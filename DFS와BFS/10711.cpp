#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;
int N, M, cnt = 0;
char Map[1000][1001];
int dx[8] = { -1,-1,-1,0,1,1,1,0 }, dy[8] = { 1,0,-1,-1,-1,0,1,1 };
int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> Map[i];
	queue<pair<int, int>>q;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] == '.') { q.push({ j,i }); Map[i][j] = '0'; }
	while (++cnt)
	{
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int x = q.front().first, y = q.front().second; q.pop();
			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || Map[ny][nx] == '0')continue;
				if (--Map[ny][nx] == '0')q.push({ nx,ny });
			}
		}if (q.empty()) { cout << cnt - 1; break; }
	}
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
