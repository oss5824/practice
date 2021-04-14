#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, M, T;
char Map[1000][1001];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int visitPeople[1000][1000];
int visitFire[1000][1000];
void bfs(queue<pair<int, int>>Fire,queue<pair<int, int>>People)
{
	while (!Fire.empty()) {
		int curX = Fire.front().first, curY = Fire.front().second; Fire.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || Map[nextY][nextX] == '#'
				|| visitFire[nextY][nextX] != -1)continue;
			Fire.push({ nextX,nextY }); visitFire[nextY][nextX] = visitFire[curY][curX] + 1;
		}
	}
	while (!People.empty()) {
		int curX = People.front().first, curY = People.front().second; People.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) { cout << visitPeople[curY][curX] + 1 << "\n"; return; }
			if(Map[nextY][nextX] == '#'|| visitPeople[nextY][nextX] != -1)continue;
			if ((visitFire[nextY][nextX] != -1 && (visitFire[nextY][nextX] <= visitPeople[curY][curX] + 1)))continue;
			People.push({ nextX,nextY }); visitPeople[nextY][nextX] = visitPeople[curY][curX] + 1;
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> M >> N;
		queue<pair<int, int>>Fire;queue<pair<int, int>>People;
		memset(visitPeople, -1, sizeof(visitPeople)); memset(visitFire, -1, sizeof(visitFire)); memset(Map, 0, sizeof(Map));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				cin >> Map[i][j];
				if (Map[i][j] == '*') { Fire.push({ j,i }); visitFire[i][j] = 0; }
				else if (Map[i][j] == '@') { People.push({ j,i }); visitPeople[i][j] = 0; }
			}
		bfs(Fire, People);
	}
	return 0;
}


