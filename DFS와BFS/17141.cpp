#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<limits.h>
#define INF INT_MAX
using namespace std;

int N, M, len, result = INF;
int Map[50][50];
//bool visit[50][50];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
vector<pair<int, int>>virus;
vector<int>v;
bool visit2[11];
queue<pair<pair<int, int>, int>>q;
int Cache[50][50];
int bfs()
{
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second; 
		int curS = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || Cache[nextY][nextX] != -1
				|| Map[nextY][nextX] == 1)continue;
			q.push({ { nextX,nextY },curS + 1 }); Cache[nextY][nextX] = curS + 1;
		}
	}
	int s = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (Map[i][j] != 1 && Cache[i][j] == -1)return INF;
			else s = max(s, Cache[i][j]);
	return s;
}
void solve(int num)
{
	if (v.size() == M){
		memset(Cache, -1, sizeof(Cache));
		for (int i : v){
			q.push({ { virus[i].first,virus[i].second },0 }); Cache[virus[i].second][virus[i].first] = 0;
		}
		result = min(result, bfs());
		return;
	}
	for (int i = num; i < len; i++)
		if (!visit2[i]){
			visit2[i] = true;
			v.push_back(i);
			solve(i);
			v.pop_back();
			visit2[i] = false;
		}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 2)virus.push_back({ j,i });
		}
	len = virus.size();
	solve(0);
	result == INF ? cout << "-1" : cout << result;
	return 0;
}