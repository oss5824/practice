#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;

int N, M, result = INF;
char Map[20][21];
bool visit[20][20];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int dist[11][11];
vector<pair<int, int>>v;
pair<int, int>robot;
int bfs(int x1, int y1, int x2, int y2)
{
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, int>>q; q.push({ { x1,y1 },0 }); visit[y1][x1] = true;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second; 
		int curD = q.front().second; q.pop();
		if (curX == x2 && curY == y2) { return curD; }
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N||visit[nextY][nextX]
				|| Map[nextY][nextX] == 'x')continue;
			q.push({ {nextX,nextY},curD + 1 }); visit[nextY][nextX] = true;
		}
	}
	return -1;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	while (1)
	{
		cin >> M >> N; if (M == 0 && N == 0)break;
		memset(Map, 0, sizeof(Map)); v.clear(); memset(dist, 0, sizeof(dist)); result = INF;
		for (int i = 0; i < N; i++)cin >> Map[i];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (Map[i][j] == '*')v.push_back({ j,i });
				else if (Map[i][j] == 'o') { robot = { j,i }; }
			}
		v.push_back({ robot });
		int len = v.size();
		bool check = false;
		for (int i = 0; i < len - 1; i++){
			for (int j = i + 1; j < len; j++){
				int val = bfs(v[i].first, v[i].second, v[j].first, v[j].second);
				if (val == -1) { check = true; break; }
				dist[i][j] = val; dist[j][i] = val;
			}
			if (check)break;
		}
		vector<int>vs; for (int i = 0; i < len; i++)vs.push_back(i);
		if (check)cout << "-1\n";
		else {
			do {
				if (vs[0] != len - 1)continue;
				int sum = 0;
				for (int i = 1; i < len; i++)sum += dist[vs[i - 1]][vs[i]];
				result = min(result, sum);
			} while (next_permutation(vs.begin(), vs.end()));
			cout << result << "\n";
		}
	}
	return 0;
}