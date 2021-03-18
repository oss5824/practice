#include <iostream>
#include <queue>
using namespace std;
int arr[100001];
bool visit[100001];
int n, l, vmin = 0;
void bfs()
{
	queue<pair<int, int>>q; q.push({ n,0 }); int cnt = 0, dist = 0; visit[n] = true;
	while (!(q.empty())) {
		int cur = q.front().first, cur_dist = q.front().second; q.pop(); visit[cur] = true;
		if (cur == l && cnt == 0) { cnt++; dist = cur_dist; continue; }
		else if (cur == l && dist == cur_dist) { cnt++; continue; }
		int move[3] = { 1,-1,cur };
		for (int k = 0; k < 3; k++) {
			if (cur + move[k] < 0 || cur + move[k] >100000 || visit[cur + move[k]])continue;
			q.push({ cur + move[k],cur_dist + 1 }); 
		}
	}cout << dist << "\n" << cnt;
}
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> n >> l;bfs();
	return 0;
}