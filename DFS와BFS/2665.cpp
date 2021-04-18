#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M, result;
char Map[50][51];
int Dist[50][50];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void bfs()
{
	deque<pair<int, int>>dq; dq.push_front({ 0,0 }); Dist[0][0] = 0;
	while (!dq.empty()) {
		int curX = dq.front().first, curY = dq.front().second; dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)continue;
			int value = Map[nextY][nextX] - '0'; value = (value == 0) ? 1 : 0;
			if (value + Dist[curY][curX] < Dist[nextY][nextX])
			{
				Dist[nextY][nextX] = value + Dist[curY][curX];
				if (value == 0)dq.push_front({ nextX,nextY });
				else dq.push_back({ nextX,nextY });
			}
		}
	}
	cout << Dist[N - 1][N - 1];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) { cin >> Map[i][j]; Dist[i][j] = INF; }
	bfs();
	return 0;
}

