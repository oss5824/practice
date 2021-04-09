#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int N, M, K, Map[100][100];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int bfs(int x, int y)
{
	queue<pair<int, int>>q; q.push({ x,y }); Map[y][x] = 1; int cnt = 1;
	while (!q.empty()){
		int curX = q.front().first, curY = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nextX = curX + dx[i], nextY = curY + dy[i];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || Map[nextY][nextX] == 1)continue;
			q.push({ nextX,nextY }); Map[nextY][nextX] = 1; cnt++;
		}
	}
	return cnt;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N>>M>>K;
	vector<int>v;
	while (K--) {
		int a, b, c, d; cin >> a >> b >> c >> d;//x,y
		for (int i = b; i < d; i++)for (int j = a; j < c; j++)Map[i][j] = 1;
	}
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)if (Map[i][j] == 0) { v.push_back(bfs(j, i)); }
	sort(v.begin(), v.end()); cout << v.size() << "\n"; for (int i : v)cout << i << " ";
	return 0;
}

