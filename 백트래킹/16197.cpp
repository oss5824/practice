#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
char arr[21][21];
bool visit[21][21][21][21];
int dx[4] = { -1,0,0,1 }, dy[4] = { 0,-1,1,0 };
pair<int, int>p1, p2;
void bfs()
{
	queue<pair<pair<int, int>,int>>q1, q2;
	q1.push({ p1,0 }); q2.push({ p2,0 }); visit[p1.second][p1.first][p2.second][p2.first] = true;
	while (!q1.empty() || !q2.empty())
	{
		int x1 = q1.front().first.first, y1 = q1.front().first.second, c1 = q1.front().second;
		int x2 = q2.front().first.first, y2 = q2.front().first.second, c2 = q2.front().second;
		//cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
		if (c1 >= 10)break;
		q1.pop(); q2.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
			int nx2 = x2 + dx[i], ny2 = y2 + dy[i];

			if ((nx1 < 0 || nx1 >= m || ny1 < 0 || ny1 >= n) && (nx2 < 0 || nx2 >= m || ny2 < 0 || ny2 >= n))continue;
			if (((nx1 < 0 || nx1 >= m || ny1 < 0 || ny1 >= n) && (0 <= nx2 && nx2 < m && 0 <= ny2 && ny2 < n))
				|| ((nx2 < 0 || nx2 >= m || ny2 < 0 || ny2 >= n) && (0 <= nx1 && nx1 < m && 0 <= ny1 && ny1 < n))) {
				cout << c1 + 1; return;
			}

			if (arr[ny1][nx1] == '#' && arr[ny2][nx2] == '#')continue;
			if (arr[ny1][nx1] == '#' && nx2 == x1 && ny2 == y1)continue;
			if (arr[ny2][nx2] == '#' && x2 == nx1 && y2 == ny1)continue;
			if (visit[ny1][nx1][ny2][nx2])continue;
			if (arr[ny1][nx1] == '#'){
				q1.push({ { x1,y1 },c1 + 1 }); q2.push({ { nx2,ny2 },c2 + 1 });
				visit[y1][x1][ny2][nx2] = true;
			}
			else if (arr[ny2][nx2] == '#'){
				q1.push({ { nx1,ny1 },c1 + 1 }); q2.push({ { x2,y2 },c2 + 1 });
				visit[ny1][nx1][y2][x2] = true;
			}
			else{
				q1.push({ { nx1,ny1 },c1 + 1 }); q2.push({ { nx2,ny2 },c2 + 1 });
				visit[ny1][nx1][ny2][nx2] = true;
			}
		}
	}
	cout << "-1";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> m; bool check = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (check == false && arr[i][j] == 'o') { p1.first = j, p1.second = i; check = true; }
			else if (arr[i][j] == 'o') { p2.first = j, p2.second = i; }
		}bfs();
	return 0;
}


