#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<limits.h>
#include<string>
#define INF INT_MAX
using namespace std;
int N, M;
char Map[30][31];
bool visit[30][30];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int result = INF;
bool range(int nextX, int nextY)
{
	if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextY][nextX] || Map[nextY][nextX] == '*')return false;
	return true;
}
bool mapCheck()
{
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] == '.' && !visit[i][j])return false;
	return true;
}
void solve(int x, int y, int cnt)
{
	bool check = false;
	for (int i = 0; i < 4; i++)
	{
		int curX = x, curY = y;
		int nextX = x + dx[i], nextY = y + dy[i];
		if (!range(nextX, nextY))continue;
		check = true;
	}
	if (!check)
	{
		if (mapCheck() || cnt == 0)result = min(result, cnt);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		bool backUp[30][30]; memcpy(backUp, visit, sizeof(visit));
		int curX = x, curY = y; visit[curY][curX] = true;
		if (!range(curX + dx[i], curY + dy[i]))continue;
		while (range(curX + dx[i], curY + dy[i])) { curX = curX + dx[i]; curY = curY + dy[i]; visit[curY][curX] = true; }
		solve(curX, curY, cnt + 1);
		memcpy(visit, backUp, sizeof(visit));
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int cnt = 1;
	while (cin >> N)
	{
		cin >> M; memset(Map, 0, sizeof(Map)); result = INF;
		for (int i = 0; i < N; i++)cin >> Map[i];
		int dot = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (Map[i][j] == '.')
				{
					memset(visit, false, sizeof(visit));
					solve(j, i, 0);
				}
		if(result==INF)result=-1;
		cout << "Case " << cnt++ << ": " << result << "\n";
	}
	return 0;
}

