#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<string>
#define INF 987654321
typedef unsigned long long ull;
using namespace std;
int N, M, D,result, KillPoint, Map[15][15];
bool visit[15][15];
vector<pair<int, int>>v;
bool Sub(int n) { int cnt = 0; while (n) { if (n & 1)cnt++; n = n >> 1; }if (cnt == 3)return true; else return false; }
void Kill(int pos)
{
	int x = pos, y = N;
	pair<int, int>enemy = { INF,INF }; int min_dist = INF;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Map[i][j] == 1)
			{
				int dist = abs(x - j) + abs(N - i);
				if (dist > min_dist || dist > D)continue;
				else if (dist == min_dist)
				{
					if (j < enemy.first) { enemy = { j,i }; }
				}
				else {
					min_dist = dist;
					enemy = { j,i };
				}
			}
	if (min_dist != INF)
	{
		if (!visit[enemy.second][enemy.first])
		{
			visit[enemy.second][enemy.first] = true;
			v.push_back({ enemy.first,enemy.second });
		}
	}
}
bool check() { for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) if (Map[i][j] == 1)return false; return true; }
void move()
{
	for (int i = N - 1; i >= 1; i--)for (int j = 0; j < M; j++)Map[i][j] = Map[i - 1][j];
	for (int j = 0; j < M; j++)Map[0][j] = 0;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)cin >> Map[i][j];
	int num = pow(2, M);
	for (int i = 0; i < num; i++)
	{
		if (!Sub(i))continue;
		int backUpMap[15][15]; memcpy(backUpMap, Map, sizeof(Map)); 
		KillPoint = 0;
		while (1) {
			int n = i, cnt = 0; memset(visit, false, sizeof(visit)); v.clear();
			while (n) {
				if (n & 1)Kill(cnt);
				n = n >> 1; cnt++;
			}
			for (pair<int, int>p : v) {
				Map[p.second][p.first] = 0;
				KillPoint++;
			}
			move();
			if (check())break;
		}
		memcpy(Map, backUpMap, sizeof(Map));
		result = max(result, KillPoint);
	}cout << result;
	return 0;
}

