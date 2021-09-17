#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
string s[12];
bool visit[12][6];
int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
vector<pair<int, int>>v;
int bfs(int x, int y, char c)
{
	queue<pair<int, int>>q; q.push({ x,y }); visit[y][x] = true; int cnt = 1;
	v.clear(); v.push_back({ x,y });
	while (!q.empty()) {
		int cx = q.front().first, cy = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= 6 || ny < 0 || ny >= 12 || visit[ny][nx] || s[ny][nx] != c)continue;
			visit[ny][nx] = true; cnt++; q.push({ nx,ny }); v.push_back({ nx,ny });
		}
	}
	return cnt;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); int res = 0;
	for (int i = 0; i < 12; i++)cin >> s[i];
	for (int x = 0; x < 72; x++) {
		memset(visit, false, sizeof(visit)); bool check = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (s[i][j] != '.' && !visit[i][j]) {
					int cnt = bfs(j, i, s[i][j]);
					if (cnt >= 4) check = true;
					else for (pair<int, int>p : v) visit[p.second][p.first] = false;
				}
			}
		}
		if (check) {
			res++;
			for (int j = 0; j < 6; j++) {
				string str;
				for (int i = 11; i >= 0; i--) {
					if (visit[i][j])continue;
					str.push_back(s[i][j]);
				}
				int len = str.length(), idx = 0;
				for (int i = 11; i >= 0; i--) {
					if (idx == len)s[i][j] = '.';
					else s[i][j] = str[idx++];
				}
			}
		}
	}
	cout << res;
	return 0;
}

