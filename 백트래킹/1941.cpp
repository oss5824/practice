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

string Map[5];
vector<int>v;
bool visit[5][5];
int result;
bool mapVisit[5][5];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
void bfs(int x,int y)
{
	memset(mapVisit, false, sizeof(mapVisit));
	queue<pair<int, int>>q; q.push({ x, y }); mapVisit[y][x] = true;
	while (!q.empty()) {
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 5 ||
				mapVisit[nextY][nextX] || !visit[nextY][nextX])continue;
			q.push({ nextX,nextY }); mapVisit[nextY][nextX] = true;
		}
	}
}
bool check()
{
	int cnt = 0;
	for (int i : v)if (Map[i / 5][i % 5] == 'Y')cnt++;
	if (cnt >= 4)return false;
	return true;
}
void solve(int num)
{
	if (v.size() == 7)
	{
		bfs(v[0] % 5, v[0] / 5);
		for (int i : v)if (!mapVisit[i / 5][i % 5])return;
		result++; 
		return;
	}
	for (int i = num; i < 25; i++) {
		if (!visit[i / 5][i % 5])
		{
			visit[i / 5][i % 5] = true;
			v.push_back(i);
			if (check())solve(i);
			v.pop_back();
			visit[i / 5][i % 5] = false;
		}
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 0; i < 5; i++)cin >> Map[i];
	solve(0);
	cout << result;
	return 0;
}