#include<iostream>
#include<queue>
using namespace std;
int Map[501][501], n, m, y, x, a, b, cnt, res[1001], val;
int dx[8] = { -2,-2,-1,1,2,2,1,-1 };
int dy[8] = { 1,-1,-2,-2,-1,1,2,2 };
bool visit[501][501];
int main(){
	cin.tie(NULL);ios::sync_with_stdio(false);
	cin >> n >> m >> y >> x;
	for (int i = 0; i < m; i++) { cin >> a >> b; Map[a][b] = ++cnt; }
	queue<pair<pair<int, int>, int>>q; q.push({ { x,y },0 }); visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second; 
		int c = q.front().second;
		q.pop();
		if (Map[y][x] != 0) { res[Map[y][x]] = c; if (++val == cnt)break; }
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n || visit[ny][nx])continue;
			q.push({ { nx,ny },c + 1 }); visit[ny][nx] = true;
		}
	}
	for (int i = 1; i <= m; i++)cout << res[i] << " ";
}
