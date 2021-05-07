#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#include<limits.h>
#define INF 1e9
using namespace std;
int N, cnt;
int Map[5][5];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
string s;
map<string, int>m;
void dfs(int x, int y)
{
	if (s.size() == 6)
	{
		if (m[s] == 0) { m[s] = 1; cnt++; }
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i], nextY = y + dy[i];
		if (nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 5)continue;
		s += (Map[nextY][nextX] + '0');
		dfs(nextX, nextY);
		s.pop_back();
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)cin >> Map[i][j];
	for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++) { s = ""; s += (Map[i][j] + '0'); dfs(j, i); }
	cout << cnt << "\n";
	return 0;
}