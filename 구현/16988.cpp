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
#define INF INT_MAX
typedef unsigned long long ull;
using namespace std;
int N, M, Map[20][20], result;
bool visit[20][20];
bool visit2[20][20];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
vector<pair<int, int>>v;
int  bfs(int x, int y)
{
	int num = 0; bool check = false;
	queue<pair<int, int>>q; q.push({ x,y }); visit[y][x] = true; num = 1;
	//cout << x << " " << y << "\n";
	while(!q.empty())
	{
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)continue;
			if (Map[nextY][nextX] == 0) { check = true; continue; }
			if (Map[nextY][nextX] != 2)continue;
			if (visit[nextY][nextX])continue;
			q.push({ nextX,nextY }); num++; visit[nextY][nextX] = true;
		}
	}
	if (!check)return num;
	else return 0;
}
void solve(int x, int y)
{
	if (v.size() == 2)
	{
		memset(visit, false, sizeof(visit));
		int x = v[0].first, y = v[0].second;
		int val1 = 0, val2 = 0;
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i], nextY = y + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)continue;
			if (Map[nextY][nextX] != 2 || visit[nextY][nextX])continue;
			val1 = val1 + bfs(nextX, nextY);
		}
		x = v[1].first, y = v[1].second;
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i], nextY = y + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)continue;
			if (Map[nextY][nextX] != 2 || visit[nextY][nextX])continue;
			val2 = val2 + bfs(nextX, nextY);
		}
		result = max(result, val1 + val2);
		return;
	}
	for (int i = y; i < N; i++)
		for (int j = x; j < M; j++)
		{
			if (!visit2[i][j])
			{
				if (Map[i][j] != 0)continue;
				visit2[i][j] = true; v.push_back({ j,i }); Map[i][j] = 1;
				solve(j, i);
				visit2[i][j] = false; v.pop_back(); Map[i][j] = 0;
			}
			x = 0;
		}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];

	solve(0, 0);
	cout << result;
	return 0;
}
