#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[100001];
bool visit[100001];
int n, l, vmin = 0;
void bfs()
{
	queue<pair<int, int>>q; q.push({ 0,n }); int res = 2000000000; visit[n] = true;
	while (!(q.empty())) {
		int cur = q.front().second, cur_dist = q.front().first; q.pop(); visit[l] = false; visit[cur] = true;
		if (cur == l) { res = min(res, cur_dist); continue; }
		int move[3] = { 1,-1,cur };
		for (int k = 0; k < 3; k++) {
			if (cur + move[k] < 0 || cur + move[k] >100000 || visit[cur + move[k]])continue;
			int dist = cur_dist; if (k == 0 || k == 1)dist = cur_dist + 1;
			q.push({ dist,cur + move[k] });
		}
	}cout << res;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> l;bfs();
	return 0;
}