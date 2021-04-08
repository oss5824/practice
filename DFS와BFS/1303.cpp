#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m, cnt; char arr[101][101];
int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
void bfs(int x,int y,char c)
{
	queue<pair<int, int>>q; q.push({ x,y }); arr[y][x] = 'x'; cnt = 1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[ny][nx] != c)continue;
			q.push({ nx,ny }); arr[ny][nx] = 'x'; cnt++;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m; for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)cin >> arr[i][j];
	int sumb = 0, sumw = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == 'B') { bfs(j, i, 'B'); sumb += cnt * cnt; }
			else if (arr[i][j] == 'W') { bfs(j, i, 'W'); sumw += cnt * cnt; }
	cout << sumw << " " << sumb;
	return 0;
}
//cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);