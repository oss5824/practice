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
int Map[4][4];
int result;
pair<pair<int, int>, int>order[17];
//크기,방향,x,y
bool live[17];
int dx[8] = { 0,-1,-1,-1,0,1,1,1 }, dy[8] = { -1,-1,0,1,1,1,0,-1 };
pair<pair<int, int>, int>shark;
void rotate()
{
	for (int i = 1; i <= 16; i++)
	{
		if (live[i] == false)continue;
		int x = order[i].first.first, y = order[i].first.second;
		int d = order[i].second;
		int nextX = 0, nextY = 0;
		for (int k = 0; k < 8; k++) {
			int nextX = x + dx[d], nextY = y + dy[d];
			if (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4
				|| (nextX == shark.first.first && nextY == shark.first.second)) {
				d++; if (d == 8)d = 0; continue;
			}
			int sz = Map[nextY][nextX];
			order[i] = { {nextX,nextY},d };
			order[sz] = { {x,y},order[sz].second };
			swap(Map[nextY][nextX], Map[y][x]);
			break;
		}
	}
}
bool range(int x, int y)
{
	if (x < 0 || x >= 4 || y < 0 || y >= 4)return false;
	return true;
}
void solve(int cnt)
{
	result = max(result, cnt);
	rotate();
	int x = shark.first.first, y = shark.first.second, d = shark.second;
	int nextX = x, nextY = y;
	while (range(nextX + dx[d], nextY + dy[d]))
	{
		nextX = nextX + dx[d], nextY = nextY + dy[d];
		pair<pair<int, int>, int>tmp = shark;
		pair<pair<int, int>, int>backUpOrder[17]; memcpy(backUpOrder, order, sizeof(order));
		int backUpMap[4][4]; memcpy(backUpMap, Map, sizeof(Map));
		bool backUpLive[17]; memcpy(backUpLive, live, sizeof(live));
		int val = Map[nextY][nextX];
		if (Map[nextY][nextX] != 0){
			shark.second = order[Map[nextY][nextX]].second;
			live[Map[nextY][nextX]] = false;
			Map[nextY][nextX] = 0;
		}
		else continue;
		shark.first = { nextX,nextY };
		solve(cnt + val);
		shark = tmp; memcpy(live, backUpLive, sizeof(live)); 
		memcpy(Map, backUpMap, sizeof(Map)); memcpy(order, backUpOrder, sizeof(order));
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	memset(live, true, sizeof(live));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int a, b; cin >> a >> b; order[a] = { {j,i},b - 1 }; Map[i][j] = a;
		}
	int val = Map[0][0];
	shark = { { 0,0 },order[Map[0][0]].second }; Map[0][0] = 0; live[val] = false;
	solve(val);
	cout << result;
	return 0;
}