#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M;
bool visit[100][100];
char Map[100][101];
int Dist[100][100];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
void bfs()
{
	deque<pair<int, int>>dq; dq.push_front({ 0,0 }); Dist[0][0] = 0;
	while (!dq.empty()){
		int curX = dq.front().first, curY = dq.front().second; dq.pop_front();
		for (int i = 0; i < 4; i++){
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)continue;
			int value = (Map[nextY][nextX] == '1') ? 1 : 0;
			if (Dist[curY][curX] + value < Dist[nextY][nextX])
			{
				Dist[nextY][nextX] = Dist[curY][curX] + value;
				if (value == 0)dq.push_front({ nextX,nextY });
				else dq.push_back({ nextX,nextY });
			}
		}
	}
	cout << Dist[N - 1][M - 1];
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> M >> N;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) { cin >> Map[i][j]; Dist[i][j] = INF; }
	bfs();
	return 0;
}


