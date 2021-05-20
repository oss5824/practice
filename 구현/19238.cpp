#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, T, Map[21][21];
pair<int,pair<int,int>> Start[21][21];
bool visit[21][21];
pair<int, int>Taxi;
//pair<pair<int, int>, pair<int, int>>People[400];
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

pair<int, pair<int, int>> distance(int x, int y)
{
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, int>>q; q.push({ { x,y },0 }); visit[y][x] = true;
	int dist = INF;
	pair<int, int>res;
	bool check = false;
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second, curD = q.front().second;
		q.pop();
		if (Start[curY][curX].first != 0 && dist > curD) { check = true; dist = curD; res = { curX,curY }; }
		else if (Start[curY][curX].first != 0 && dist == curD)
		{
			if (curY < res.second)res = { curX,curY };
			else if (curY == res.second)
			{
				if (curX < res.first)res = { curX,curY };
			}
		}
		else if (dist < curD)break;
		for (int k = 0; k < 4; k++)
		{
			int nextX = curX + dx[k], nextY = curY + dy[k];
			if (nextX<1 || nextX>N || nextY<1 || nextY>N || Map[nextY][nextX] == 1
				|| visit[nextY][nextX])continue;
			q.push({ {nextX,nextY},curD + 1 }); visit[nextY][nextX] = true;
		}
	}
	if (!check)return { -1,{0,0} };
	return Start[res.second][res.first];
}
void bfs()
{
	int x = Taxi.first, y = Taxi.second;
	pair<int, pair<int, int>>s_idx;
	for (int i = 1; i <= 2 * M; i++)
	{
		queue<pair<pair<int, int>, int>>q; q.push({ {x,y},T }); bool check = false;
		if (i % 2 == 1) { s_idx = distance(x, y); if (s_idx.first == -1) { cout << "-1\n"; return; } }
		memset(visit, false, sizeof(visit)); visit[y][x] = true;
		while (!q.empty()) {
			int curX = q.front().first.first, curY = q.front().first.second, curD = q.front().second;
			q.pop();
			if (Start[curY][curX].first == s_idx.first && i % 2 == 1) {
				T = curD; x = curX; y = curY; check = true; Start[curY][curX].first = 0;
				break;
			}
			else if (curX == s_idx.second.first && curY == s_idx.second.second
				&& i % 2 == 0) {
				T = curD + (T - curD) * 2; x = curX; y = curY; check = true; 
				break;
			}
			for (int k = 0; k < 4; k++)
			{
				int nextX = curX + dx[k], nextY = curY + dy[k];
				if (nextX<1 || nextX>N || nextY<1 || nextY>N || Map[nextY][nextX] == 1
					|| visit[nextY][nextX] || curD - 1 < 0)continue;
				q.push({ {nextX,nextY},curD - 1 }); visit[nextY][nextX] = true;
			}
		}
		if (!check) { cout << "-1\n"; return; }
	}
	cout << T<<"\n";
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)cin >> Map[i][j];
	cin >> Taxi.second >> Taxi.first;
	for (int i = 1; i <= M; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		Start[a][b] = { i,{d,c} };
	}
	bfs();
	return 0;
}