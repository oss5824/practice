#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 1e9
using namespace std;
int M[1001][1001];
bool visit[1001][1001];
int n;
void bfs()
{
	//화면1 클립보드0
	queue<pair<int, int>>q; q.push({ 1,0 }); M[1][0] = 0; visit[1][0] = true; int res = 1000000000;
	while (!(q.empty())) {
		int cur_display = q.front().first, cur_clip = q.front().second; q.pop();
		if (cur_display == n) { break; }
		pair<int, int> move[3] = { {cur_display,cur_display},{cur_display + cur_clip,cur_clip},{cur_display - 1,cur_clip} };
		for (int k = 0; k < 3; k++) {
			int f = move[k].first, s = move[k].second;
			if (f < 0 || s == 0 || f > 1000 || visit[f][s] == true)continue;
			q.push(move[k]); visit[f][s] = true;
			M[f][s] = min(M[cur_display][cur_clip] + 1,M[f][s]);
			if (f == n)res = min(res, M[f][s]);
		}
	}cout << res;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
	for (int i = 0; i < 1001; i++)for (int j = 0; j < 1001; j++)M[i][j] = INF;
	cin >> n; bfs();
	return 0;
}