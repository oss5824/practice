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
int N, M, K;
int Map[101][101];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
//¼­ ºÏ µ¿ ³²
queue<pair<int, char>>v;
int main()
{
	cout.tie(NULL); cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M;
	while (M--) { int a, b; cin >> a >> b; Map[a][b] = 1; }
	cin >> K;
	while (K--) { int a; char c; cin >> a >> c; v.push({ a,c }); }
	int t = 0;
	deque<pair<int, int>>q; q.push_front({ 1,1 }); Map[1][1] = 2;
	int direction = 2;
	while (1)
	{
		t++;
		int X = q.front().first, Y = q.front().second;
		int nextX = X + dx[direction], nextY = Y + dy[direction];
		if (nextX<1 || nextX>N || nextY<1 || nextY>N || Map[nextY][nextX] == 2) { cout << t; break; }
		if (Map[nextY][nextX] == 1){
			Map[nextY][nextX] = 2; q.push_front({ nextX,nextY });
		}
		else{
			Map[q.back().second][q.back().first] = 0;
			q.pop_back();
			q.push_front({ nextX,nextY });
			Map[nextY][nextX] = 2;
		}
		if (!v.empty() && v.front().first == t)
		{
			if (v.front().second == 'L') { if (direction == 0)direction = 3; else direction--; }
			else if (v.front().second == 'D') { if (direction == 3)direction = 0; else direction++; }
			v.pop();
		}

	}
	return 0;
}