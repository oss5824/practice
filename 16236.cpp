#include <iostream>
#include <queue>
#include <cstring>
#define INF 1e9
using namespace std;
int n, res, cnt, dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 }, arr[21][21];
bool visit[21][21];
struct shark { int x, y, sz; };
int fx, fy;
shark s;
int distance()
{
	memset(visit, false, sizeof(visit)); queue<pair<shark, int>>q; q.push({ s,0 }); visit[s.y][s.x] = true;
	while (!q.empty()) {
		int cx = q.front().first.x, cy = q.front().first.y, dist = q.front().second;
		q.pop();
		if (cx == fx && cy == fy) return dist;
		for (int i = 0; i < 4; i++) {
			shark sh; sh.x = cx + dx[i]; sh.y = cy + dy[i];
			if (sh.x < 0 || sh.x >= n || sh.y < 0 || sh.y >= n || s.sz < arr[sh.y][sh.x] || visit[sh.y][sh.x])continue;
			sh.sz = arr[sh.y][sh.x];
			q.push({ sh,dist + 1 }); visit[sh.y][sh.x] = true;
		}
	}return INF;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) { cin >> arr[i][j]; if (arr[i][j] == 9) { s.x = j, s.y = i; s.sz = 2; } }
	while (1)
	{
		int x = 0, y = 0, dist = INF;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (s.sz > arr[i][j] && arr[i][j] != 0) {
					fx = j; fy = i; int val = distance();
					if (dist > val) { x = j; y = i; dist = val; }
				}
		if (dist == INF)break;
		cnt++; if (cnt == s.sz) { cnt = 0; s.sz++; }
		res += dist; arr[y][x] = 0; arr[s.y][s.x] = 0; s.x = x; s.y = y;
	}cout << res;
	return 0;
}
