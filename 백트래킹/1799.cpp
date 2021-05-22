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
#define INF 1e9
using namespace std;
int N, Map[10][10], result;
bool visit[10][10];
vector<int>v;
vector<pair<int, int>>pos, pos1, pos2;

bool check(int j, int i)
{
	if (visit[i][j]) return false; visit[i][j] = true; int x = j - 1, y = i - 1;
	while (x >= 0 && y >= 0) { visit[y][x] = true; x--; y--; }x = j - 1; y = i + 1;
	while (x >= 0 && y < N) { visit[y][x] = true; x--; y++; }x = j + 1; y = i - 1;
	while (x < N && y >= 0) { visit[y][x] = true; x++; y--; }x = j + 1; y = i + 1;
	while (x < N && y < N) { visit[y][x] = true; x++; y++; }
	return true;
}
void solve(int cnt, int num)
{
	result = max(result, num);
	if (cnt == pos.size())return;
	if (visit[pos[cnt].second][pos[cnt].first])solve(cnt + 1, num);
	else
	{
		bool backUp[10][10];
		memcpy(backUp, visit, sizeof(visit));
		if (check(pos[cnt].first, pos[cnt].second)) solve(cnt + 1, num + 1);
		memcpy(visit, backUp, sizeof(visit));
		solve(cnt + 1, num);
	}
}
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 1)
			{
				if (i % 2 == 0 && j % 2 == 0)pos1.push_back({ j,i });
				else if (i % 2 == 0)pos2.push_back({ j,i });
				else if (i % 2 == 1 && j % 2 == 0)pos2.push_back({ j,i });
				else if (i % 2 == 1 && j % 2 == 1)pos1.push_back({ j,i });
			}
		}
	int sum = 0;
	pos.clear(); pos = pos1; memset(visit, false, sizeof(visit));
	solve(0, 0); sum += result;
	pos.clear(); pos = pos2; result = 0; memset(visit, false, sizeof(visit));
	solve(0, 0); sum += result;
	cout << sum;
	return 0;
}