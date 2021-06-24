#include<iostream>
#include<string>
#include<set>
using namespace std;

int N, cnt, Map[5][5];
bool visit[5][5];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
bool range(int x, int y)
{
	if (x < 0 || x>4 || y < 0 || y>4 || visit[y][x] || Map[y][x] == 1)return false;
	return true;
}
void solve(int x1, int y1, int x2, int y2)
{
	if (x1 == x2 && y1 == y2) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (Map[i][j] == 1)continue;
				if (!visit[i][j])return;
			}
		}
		cnt++;
		return;
	}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int nextX1 = x1 + dx[i], nextY1 = y1 + dy[i];
			int nextX2 = x2 + dx[j], nextY2 = y2 + dy[j];
			if (!range(nextX1, nextY1) || !range(nextX2, nextY2))continue;
			visit[nextY1][nextX1] = true; visit[nextY2][nextX2] = true;
			solve(nextX1, nextY1, nextX2, nextY2);
			visit[nextY1][nextX1] = false; visit[nextY2][nextX2] = false;
		}
}
int main()
{

	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		int a, b; cin >> a >> b; Map[a - 1][b - 1] = 1;
	}
	visit[0][0] = true; visit[4][4] = true;
	solve(0, 0, 4, 4);
	cout << cnt;
	return 0;
}
