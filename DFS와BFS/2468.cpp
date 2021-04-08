#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, Map[100][100], result;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool Route[100][100];
void bfs(int x, int y, int h)
{
	queue<pair<int, int>>q; q.push({ x,y }); Map[y][x] = 0;
	while (!q.empty())
	{
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || Map[nextY][nextX] <= h)continue;
			q.push({ nextX,nextY }); Map[nextY][nextX] = 0;
		}
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int height = 0;cin >> N; 
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) { cin >> Map[i][j]; height = max(height, Map[i][j]); }
	
	for (int h = 0; h <= height; h++)
	{
		int backUpMap[100][100], cnt = 0; memcpy(backUpMap, Map, sizeof(Map));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (Map[i][j] <= h)continue;
				cnt++; bfs(j, i, h);
			}
		result = max(cnt, result);
		memcpy(Map, backUpMap, sizeof(Map));
	}cout << result;
	return 0;
}

