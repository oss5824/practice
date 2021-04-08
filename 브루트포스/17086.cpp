#include <iostream>
#include <queue>
using namespace std;
int res, n, m, dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { 0,-1,1,1,-1,0,-1,1 }, arr[51][51], M[51][51];
queue<pair<int, int>>q;
void bfs()
{
	while (!q.empty()) {
		int cur_x = q.front().first, cur_y = q.front().second; q.pop();
		for (int i = 0; i < 8; i++) {
			int next_x = cur_x + dx[i], next_y = cur_y + dy[i];
			if (next_x<0 || next_x>m || next_y<0 || next_y>n)continue;
			if (M[next_y][next_x] > M[cur_y][cur_x] + 1) {
				q.push({ next_x,next_y }); M[next_y][next_x] = M[cur_y][cur_x] + 1;
				res = (res < M[next_y][next_x]) ? M[next_y][next_x] : res;
			}
		}
	}cout << res;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> arr[i][j]; if (arr[i][j] == 1)q.push({ j,i }); else M[i][j] = 1000000000;
		}bfs();
	return 0;
}


/*

#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;
int res = INF, n, m, dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { 0,-1,1,1,-1,0,-1,1 }, arr[51][51];
bool visit[51][51];
queue<pair<pair<int, int>, int>>q;
int bfs(int x,int y)
{
	q.push({ {x,y,},0 }); visit[y][x] = true;
	while (!q.empty()) {
		int cur_x = q.front().first.first, cur_y = q.front().first.second, cur_dist = q.front().second; q.pop();
		for (int i = 0; i < 8; i++) {
			int next_x = cur_x + dx[i], next_y = cur_y + dy[i];
			if (next_x<0 || next_x>m || next_y<0 || next_y>n || visit[next_y][next_x])continue;
			q.push({ { next_x,next_y },cur_dist + 1 });visit[]
		}
	}return INF;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); cin >> n >> m;
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
	bfs();
	return 0;
}

*/