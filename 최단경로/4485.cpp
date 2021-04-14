#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int T, N, result = INF;
int Map[125][125], M[125][125];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void bfs()
{
	queue<pair<int, int>>q; q.push({ 0,0 }); M[0][0] = Map[0][0];
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)continue;
			if (M[nextY][nextX] > M[curY][curX] + Map[nextY][nextX]){
				q.push({ nextX,nextY });
				M[nextY][nextX] = M[curY][curX] + Map[nextY][nextX];
			}
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int cnt = 1;
	while (cin >> N) {
		if (N == 0)break;
		memset(Map, false, sizeof(Map)); memset(M, 0, sizeof(M));
		for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) { cin >> Map[i][j]; M[i][j] = INF; }
		bfs(); cout << "Problem " << cnt++ << ": " << M[N - 1][N - 1] << "\n";
	}
	return 0;
}

