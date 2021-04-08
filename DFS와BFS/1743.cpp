#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, k, cnt, a, b; int arr[101][101];
int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
void bfs(int x,int y)
{
	queue<pair<int, int>>q; q.push({ x,y }); arr[y][x] = 0; cnt = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || arr[ny][nx] == 0)continue;
			q.push({ nx,ny }); arr[ny][nx] = 0; cnt++;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m >> k; while (k--) { cin >> a >> b; arr[a - 1][b - 1] = 1; }
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 1) { bfs(j, i); res = max(res, cnt); }
	cout << res;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);