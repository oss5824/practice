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
int A, B, N, M;
int Map[101][101];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
pair<pair<int, int>, int>robot[101];
vector<pair<char, pair<int, int>>>v;
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> A >> B;//A가로 B세로
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int a, b, d = 0; char c;
		cin >> a >> b >> c;
		if (c == 'W')d = 0; else if (c == 'N')d = 1; else if (c == 'E')d = 2; else if (c == 'S')d = 3;
		robot[i] = { { a,b },d };
		Map[b][a] = i;
	}
	for (int i = 0; i < M; i++) { int a, b; char c; cin >> a >> c >> b; v.push_back({ c,{a,b} }); }
	for (int i = 0; i < M; i++)
	{
		int num = v[i].second.first, rep = v[i].second.second; char c = v[i].first;
		int& x = robot[num].first.first, & y = robot[num].first.second, & direction = robot[num].second;
		if (c == 'F') {
			Map[y][x] = 0;
			while (rep--) {
				x = x + dx[direction], y = y + dy[direction];
				if (x<1 || x>A || y<1 || y>B) { cout << "Robot " << num << " crashes into the wall"; return 0; }
				else if (Map[y][x] != 0) { cout << "Robot " << num << " crashes into robot " << Map[y][x]; return 0; }
			}
			Map[y][x] = num;
		}
		else if (c == 'L') { while (rep--) { direction--; if (direction < 0)direction = 3; } }
		else if (c == 'R') { while (rep--) { direction++; if (direction > 3)direction = 0; } }
	}
	cout << "OK";
	return 0;
}