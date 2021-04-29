#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<limits.h>
#define INF INT_MAX
using namespace std;
char Map[1001][1001];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool visit[1001][1001][12];
int N, M, K, result = INF;
void bfs()
{
	queue<pair<pair<int, int>, pair<int, int>>>q; 
	q.push({ { 0,0 },{1,0 } }); memset(visit, false, sizeof(false));
	visit[0][0][0] = true;
	while (!q.empty())
	{
		int curX = q.front().first.first, curY = q.front().first.second;
		int curD = q.front().second.first, cnt = q.front().second.second;
		q.pop();
		if (curX == M - 1 && curY == N - 1) { result = min(result, curD); break; }
		for (int i = 0; i < 4; i++){
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)continue;
			if (Map[nextY][nextX] == '1' && !visit[nextY][nextX][cnt + 1] && cnt < K) {
				q.push({ {nextX,nextY} ,{curD + 1,cnt + 1} }); visit[nextY][nextX][cnt + 1] = true;
			}
			else if (Map[nextY][nextX] == '0' && !visit[nextY][nextX][cnt]) {
				q.push({ {nextX,nextY} ,{curD + 1,cnt} }); visit[nextY][nextX][cnt] = true;
			}
		}
	}
	result == INF ? cout << "-1" : cout << result;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	bfs();
	return 0;
}

