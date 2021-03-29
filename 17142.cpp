#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M;
int arr[50][50];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool visit[50][50];
pair<int, int>virus[10];
int virus_count = 0;
int Count(int n)
{
	int cnt = 0;
	while (n) {
		if (n & 1)cnt++;
		n = n >> 1;
	}
	return cnt;
}
int bfs(int n)
{
	queue<pair<pair<int, int>, int>>q; memset(visit, false, sizeof(visit));
	int cnt = 0, maxSec = 0;
	while (n)
	{
		if (n & 1)
		{
			 q.push({ virus[cnt],0 }); visit[virus[cnt].second][virus[cnt].first] = true;
		}
		n = n >> 1; cnt++;
	}
	while (!q.empty())
	{
		int curX = q.front().first.first, curY = q.front().first.second, curS = q.front().second;
		if (arr[curY][curX] != 2) { maxSec = max(maxSec, curS); }
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || arr[nextY][nextX] == 1 || visit[nextY][nextX])continue;
			q.push({ {nextX,nextY},curS + 1 }); visit[nextY][nextX] = true;
		}
	}
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)if (arr[i][j] == 0 && visit[i][j] == false)return INF;
	return maxSec;
}
void solve()
{
	int minTime = INF;
	for (int i = 0; i < (1 << virus_count); i++)
	{
		int cnt = Count(i);
		if (cnt == M)minTime = min(minTime, bfs(i));
	}
	(minTime == INF) ? cout << "-1" : cout << minTime;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)virus[virus_count++] = { j,i };
		}
	solve();
	return 0;
}
