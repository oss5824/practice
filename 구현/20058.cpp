#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF ll_MAX
typedef long long ll;
using namespace std;
int N, M, L, Q, len, Map[64][64], backUp[64][64];
bool visit[64][64];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
void rotate()
{
	memcpy(backUp, Map, sizeof(Map));
	for (int i = 0; i < M; i = i + len)
		for (int j = 0; j < M; j = j + len)
			for (int y = 0; y < len; y++)
				for (int x = 0; x < len; x++)
					Map[i + y][j + x] = backUp[i + len - x - 1][j + y];
	
}
void ice()
{
	vector<pair<int, int>>v;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
		{
			int cnt = 0, x = j, y = i;
			if (Map[i][j] == 0)continue;
			for (int k = 0; k < 4; k++){
				int nextX = x + dx[k], nextY = y + dy[k];
				if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= M
					|| Map[nextY][nextX] == 0)continue;
				cnt++;
			}
			if (cnt < 3)v.push_back({ j,i });
		}
	for (pair<int, int>p : v) { Map[p.second][p.first]--; }
}
int bfs(int x, int y)
{
	queue<pair<int, int>>q; q.push({ x,y }); visit[y][x] = true; 
	int val = 0;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop(); val++;
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= M
				|| Map[nextY][nextX] == 0 || visit[nextY][nextX])continue;
			visit[nextY][nextX] = true; q.push({ nextX,nextY });
		}
	}
	return val;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> Q;
	M = pow(2, N); for (int i = 0; i < M; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	while (Q--) { cin >> L; len = pow(2, L); if (L != 0)rotate(); ice(); }
	int sum = 0, result = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++){
			sum += Map[i][j];
			if (!visit[i][j]){
				if (Map[i][j] == 0)continue;
				result = max(bfs(j, i), result);
			}
		}
	if (sum == 0)cout << "0\n0";
	else cout << sum << "\n" << result;
	return 0;
}
