#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int N, M;
char Map[100][101];
int dogN, dogM, pillowN, pillowM;
int visit[100][100];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	cin >> dogN >> dogM >> pillowN >> pillowM;
	int minN = N, maxN = -1, minM = M, maxM = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'G') { minM = min(j, minM); maxM = max(j, maxM); minN = min(i, minN); maxN = max(i, maxN); }
		}
	}
	if ((maxN - minN+1) != dogN && (maxM - minM+1) != dogM) { cout << "0"; return 0; }
	bool check = true;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && Map[i][j] == 'G') {
				if (!check) { cout << "0"; return 0; }
				check = false; visit[i][j] = true;
				queue<pair<int, int>>q; q.push({ j,i });
				while (!q.empty()) {
					int curX = q.front().first, curY = q.front().second; q.pop();
					for (int i = 0; i < 4; i++) {
						int nextX = curX + dx[i], nextY = curY + dy[i];
						if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextY][nextX]
							|| Map[nextY][nextX] != 'G')continue;
						q.push({ nextX,nextY }); visit[nextY][nextX] = true;
					}
				}
			}
		}
	check = true; memset(visit, false, sizeof(visit));
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && Map[i][j] != '.') {
				if (!check) { cout << "0"; return 0; }
				check = false; visit[i][j] = true;
				if (Map[i][j] == 'P')sum++;
				queue<pair<int, int>>q; q.push({ j,i });
				while (!q.empty()) {
					int curX = q.front().first, curY = q.front().second; q.pop();
					for (int i = 0; i < 4; i++) {
						int nextX = curX + dx[i], nextY = curY + dy[i];
						if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextY][nextX]
							|| Map[nextY][nextX] == '.')continue;
						if (Map[nextY][nextX] == 'P')sum++;
						q.push({ nextX,nextY }); visit[nextY][nextX] = true;
					}
				}
			}
		}
	if (sum == pillowM * pillowN)cout << "0";
	else cout << "1";
	return 0;
}