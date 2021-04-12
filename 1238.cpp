#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#define INF 987654321
using namespace std;
int N, M, dest, res;
int dist[1001];
int result[1001];
vector<pair<int, int>>v[1001];
int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> dest; fill(dist, dist + N + 1, INF);
	while (M--) { int a, b, c; cin >> a >> b >> c; v[a].push_back({ c,b }); }
	for (int i = 1; i <= N; i++)sort(v[i].begin(), v[i].end());

	for (int i = 1; i <= N; i++) {
		queue<pair<int, int>>q; q.push({ i,0 }); fill(dist, dist + N + 1, INF);
		dist[i] = 0;
		while (!q.empty()) {
			int cur = q.front().first, cur_dist = q.front().second; q.pop();
			if (dist[cur] < cur_dist)continue;
			for (pair<int, int>p : v[cur]){
				int next = p.second, next_dist = p.first;
				if (dist[cur] + next_dist < dist[next]){
					dist[next] = dist[cur] + next_dist;
					q.push({ next,dist[next] });
				}
			}
		}
		result[i] = dist[dest];
	}
	queue<pair<int, int>>q; q.push({ dest,0 }); fill(dist, dist + N + 1, INF);
	dist[dest] = 0;
	while (!q.empty()) {
		int cur = q.front().first, cur_dist = q.front().second; q.pop();
		if (dist[cur] < cur_dist)continue;
		for (pair<int, int>p : v[cur]){
			int next = p.second, next_dist = p.first;
			if (dist[cur] + next_dist < dist[next]){
				dist[next] = dist[cur] + next_dist;
				q.push({ next,dist[next] });
			}
		}
	}
	for (int i = 1; i <= N; i++)res = max(res, dist[i] + result[i]);
	cout << res;
	return 0;
}


