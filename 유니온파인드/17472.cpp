#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<limits.h>
#define INF INT_MAX
using namespace std;
int N, M, Map[10][10];
bool visit[10][10];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int dist[7][7];
int tmpDist[10][10];
int par[7];
vector<pair<int, pair<int, int>>>Town;
bool range(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N || Map[y][x] == 0 || visit[y][x])return false;
	return true;
}
bool range2(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N )return false;
	return true;
}
void make_map(int x, int y,int num)
{
	queue<pair<int, int>>q; q.push({ x,y }); visit[y][x] = true; Map[y][x] = num;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (!range(nextX, nextY))continue;
			visit[nextY][nextX] = true; q.push({ nextX,nextY }); Map[nextY][nextX] = num;
		}
	}
}
void make_bridge(int x, int y, int num)
{
	queue<pair<pair<int, int>, pair<int, int>>>q; tmpDist[y][x] = 0;
	q.push({ {x,y},{0,0} }); q.push({ {x,y},{1,0} });
	q.push({ {x,y},{2,0} }); q.push({ {x,y},{3,0} });
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second; 
		int curD = q.front().second.first, curS = q.front().second.second;
		q.pop();
		if (Map[curY][curX] != 0 && Map[curY][curX] != num && curS >= 3)
		{
			dist[num][Map[curY][curX]] = min(dist[num][Map[curY][curX]], curS - 1);
			dist[Map[curY][curX]][num] = min(dist[Map[curY][curX]][num], curS - 1);
			continue;
		}
		else if (Map[curY][curX] != 0 && Map[curY][curX] != num && curS < 3)continue;
		for (int i = 0; i < 4; i++){
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (!range2(nextX, nextY))continue;
			if (i == curD) {
				if (Map[nextY][nextX] != num)curS++;
				if (tmpDist[nextY][nextX] <= curS)continue;
				tmpDist[nextY][nextX] = curS;
				q.push({ {nextX,nextY},{curD,curS} });
			}
			else {
				if (Map[nextY][nextX] != num)continue;
				if (tmpDist[nextY][nextX] == 0)continue;
				tmpDist[nextY][nextX] = 0;
				vector<int>v;
				for (int j = 0; j < 4; j++)if (i != j)v.push_back(j);
				q.push({ {nextX,nextY},{v[0],0} });
				q.push({ {nextX,nextY},{v[1],0} });
				q.push({ {nextX,nextY},{v[2],0} });
			}
		}
	}
}
int Find(int x) { if (x == par[x])return x; else return par[x] = Find(par[x]); }
bool Merge(int x, int y)
{
	x = Find(x); y = Find(y); if (x == y)return false;
	if (x > y)par[x] = y;
	else par[y] = x;
	return true;
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	int cnt = 1;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) { cin >> Map[i][j]; }
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			if (Map[i][j] == 0 || visit[i][j])continue;
			Town.push_back({ cnt,{j,i} });make_map(j, i, cnt++);	
		}
	for (int i = 1; i < cnt; i++)for (int j = 1; j < cnt; j++)dist[i][j] = INF;
	for (pair<int, pair<int, int>>p : Town)
	{
		int num = p.first, x = p.second.first, y = p.second.second;
		for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)tmpDist[i][j] = INF;
		make_bridge(x, y, num); par[num] = num;
	}
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>
		, greater<pair<int, pair<int, int>>>>q;
	for (int i = 1; i < cnt; i++)
		for (int j = 1; j < cnt; j++)
		{
			if (i == j || dist[i][j] == INF)continue; q.push({ dist[i][j],{j,i} });
		}
	
	int sum = 0, line = 0;
	while (!q.empty()) {
		int val = q.top().first, a = q.top().second.first, b = q.top().second.second;
		q.pop();
		if (!Merge(par[a], par[b]))continue;
		line++;
		sum += val;
	}
	if (line == cnt - 2)cout << sum; else cout << "-1";
	return 0;
}
