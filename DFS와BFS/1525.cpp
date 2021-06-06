#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF INT_MAX
typedef unsigned long long ull;
using namespace std;
int Map[3][3];
string start;
set<string>visit;
string res = "123456780";
int pos = 0;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };

void bfs()
{
	queue<pair<pair<string, int>, int>>q; q.push({ {start,pos},0 });
	visit.insert(start);
	while (!q.empty()) {
		string cur = q.front().first.first;
		int curP = q.front().first.second, curS = q.front().second;
		int curX = curP % 3, curY = curP / 3; q.pop();
		if (cur.compare(res) == 0) { cout << curS; return; }
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i], nextY = curY + dy[i];
			string next = cur;
			if (nextX < 0 || nextX >= 3 || nextY < 0 || nextY >= 3)continue;
			int nextP = nextY * 3 + nextX;
			swap(next[curP], next[nextP]);
			if (visit.count(next) == 1)continue;
			visit.insert(next); q.push({ {next,nextP},curS + 1 });
		}
	}
	cout << "-1";
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> Map[i][j];
			start = start + to_string(Map[i][j]);
			if (Map[i][j] == 0)pos = i * 3 + j;
		}
	bfs();
	return 0;
}
