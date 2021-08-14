#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, Map[200][200], S, Y, X;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	queue<pair<pair<int, int>, int>>q; vector<pair<int, pair<int, int>>>v;
	cin >> N >> M; for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) {
		cin >> Map[i][j]; if (Map[i][j] != 0)v.push_back({ Map[i][j],{j, i} });
	}
	cin >> S >> Y >> X; Y--, X--; sort(v.begin(), v.end());
	for (pair<int, pair<int, int>>p : v)q.push({ {p.second.first,p.second.second},0 });
	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second, curS = q.front().second; q.pop();
		if (curS >= S)break;
		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || Map[nextY][nextX] != 0)continue;
			Map[nextY][nextX] = Map[curY][curX]; q.push({ {nextX,nextY},curS + 1 });
		}
	}cout << Map[Y][X];
}
//cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);